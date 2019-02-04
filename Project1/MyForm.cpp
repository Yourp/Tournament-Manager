#include "MyForm.h"
#include "Player.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

//#include <cctype>

using namespace System;
using namespace Windows::Forms;
using namespace Project1;
using namespace msclr::interop;

int main(array<String^>^ /*args*/)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MyForm form;
    Application::Run(%form);

    return 0;
}

void MyForm::RemovePlayer(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    if (LB_PlayerList->SelectedIndex >= 0)
    {
        players->DeletePlayer(marshal_as<std::string>(LB_PlayerList->Items[LB_PlayerList->SelectedIndex]->ToString()));
        LB_PlayerList->Items->RemoveAt(LB_PlayerList->SelectedIndex);
        HandleBegin();
    }
}

void MyForm::RemoveAllPlayers(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    if (MessageBox::Show("Удалить всех игроков из списка?", "Очистка списка", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
    {
        LB_PlayerList->Items->Clear();
        players->ClearAllPlayers();
        LV_TeamList->Items->Clear();
        SetCurrentArena(false);
        HandleBegin();
    }
}

void MyForm::AddPlayerInList(System::Object ^ /*sender*/, System::EventArgs ^/* e*/)
{
    if (TB_AddPlayerTextBox->Text->Length)
    {
        for (int32_t i = 0; i < LB_PlayerList->Items->Count; i++)
        {
            if (LB_PlayerList->Items[i]->ToString() == (HealerCheck->Checked ? (TB_AddPlayerTextBox->Text + HealMarker) : TB_AddPlayerTextBox->Text))
            {
                MessageBox::Show("Этот игрок уже есть в списке!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
        }

        if (HealerCheck->Checked)
        {
            LB_PlayerList->Items->Add(TB_AddPlayerTextBox->Text + HealMarker);

            std::string name = marshal_as<std::string>(TB_AddPlayerTextBox->Text + HealMarker);
            players->AddPlayerInList(name, new Player(SpecHealer, name));
        }
        else
        {
            LB_PlayerList->Items->Add(TB_AddPlayerTextBox->Text);

            std::string name = marshal_as<std::string>(TB_AddPlayerTextBox->Text);
            players->AddPlayerInList(name, new Player(SpecDamager, name));
        }

        HandleBegin();

        TB_AddPlayerTextBox->Text = nullptr;
    }
}

void Project1::MyForm::BeginTournament(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    B_Begin->Enabled = false;
    players->SortTeams();
    players->FindGame();
    SendPlayerNames();
}

void Project1::MyForm::SelectWinner1(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    players->SetSelectedWinner(0);
    timer1->Enabled = false;
    B_Winner->Enabled = true;
}

void Project1::MyForm::SelectWinner2(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    players->SetSelectedWinner(1);
    timer1->Enabled = false;
    B_Winner->Enabled = true;
}

void Project1::MyForm::DeselectWinner(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    timer1->Enabled = true;
}

void Project1::MyForm::HandleWinner(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    B_Winner->Enabled = false;

    uint8_t winnerIndex = players->GetSelectedWinner();

    if (Team* winner = players->GetTeam(winnerIndex))
    {
        winner->SetWin();
        SendTeamInScoreboard(winner, false);

        if (Team* losser = players->GetTeam(winnerIndex ? 0 : 1))
        {
            losser->SetLose();
            bool removeTeam = losser->GetLoses() >= MaxLoses;

            SendTeamInScoreboard(losser, removeTeam);

            if (removeTeam)
                players->RemoveTeam(losser);
        }
    }

    ClearCurrentArena();
    players->FindGame();
    SendPlayerNames();
}

void Project1::MyForm::CurrentArenaTick(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    B_Winner->Enabled = false;
    timer1->Enabled = false;
}

void MyForm::TextCorrecter(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    if (bCanCheckTextInTextBox)
    {
        bCanCheckTextInTextBox = false;
        String^ curString = nullptr;
        int Section = TB_AddPlayerTextBox->SelectionStart;

        for (int i = 0; i < TB_AddPlayerTextBox->Text->Length; i++)
        {
            if ((TB_AddPlayerTextBox->Text[i] >= 'A' && TB_AddPlayerTextBox->Text[i] <= 'Z') || (TB_AddPlayerTextBox->Text[i] >= 1040 && TB_AddPlayerTextBox->Text[i] <= 1071))
            {
                if (i)
                {
                    curString += TB_AddPlayerTextBox->Text[i].ToLower(TB_AddPlayerTextBox->Text[i]);
                    continue;
                }

                curString += TB_AddPlayerTextBox->Text[i];
            }
            else if ((TB_AddPlayerTextBox->Text[i] >= 'a' && TB_AddPlayerTextBox->Text[i] <= 'z') || (TB_AddPlayerTextBox->Text[i] >= 1072 && TB_AddPlayerTextBox->Text[i] <= 1103))
            {
                if (!i)
                {
                    curString += TB_AddPlayerTextBox->Text[i].ToUpper(TB_AddPlayerTextBox->Text[i]);
                    continue;
                }

                curString += TB_AddPlayerTextBox->Text[i];
            }
            else continue;
        }

        TB_AddPlayerTextBox->Text = curString;
        TB_AddPlayerTextBox->SelectionStart = Section;
        bCanCheckTextInTextBox = true;
    }
}

void Project1::MyForm::HandleBegin()
{
    switch (players->CanBegin())
    {
        case BE_PlayersCount:
        {
            L_BeginErrors->Text = BEGIN_ERROR_PLAYERS_COUNT;
            break;
        }
        case BE_HealersCount:
        {
            L_BeginErrors->Text = BEGIN_ERROR_HEALERS_COUNT;
            break;
        }
        default:
        {
            B_Begin->Enabled = true;
            L_BeginErrors->Text = BEGIN_ERROR_NONE;
            return;
        }
    }
    
    B_Begin->Enabled = false;
}

void Project1::MyForm::SendPlayerNames()
{
    SetCurrentArena(true);

    ListViewItem^ team1 = (gcnew ListViewItem(gcnew cli::array< System::String^  >(2)
    {
        marshal_as<String^>(*players->GetTeam(0)->GetPlayerName(0)),
        marshal_as<String^>(*players->GetTeam(0)->GetPlayerName(1))
    }, -1));

    LV_Team_1->Items->Add(team1);

    ListViewItem^ team2 = (gcnew ListViewItem(gcnew cli::array< System::String^  >(2)
    {
        marshal_as<String^>(*players->GetTeam(1)->GetPlayerName(0)),
        marshal_as<String^>(*players->GetTeam(1)->GetPlayerName(1))
    }, -1));

    LV_Team_2->Items->Add(team2);
}

void Project1::MyForm::SendTeamInScoreboard(Team * team, bool removeTm)
{
    String^ leaderName = marshal_as<String^>(*team->GetPlayerName(0));
    ListViewItem^ LVItem = nullptr;
    
    for (int32_t i = 0; i < LV_TeamList->Items->Count; i++)
    {
        if (LV_TeamList->Items[i]->Text == leaderName)
        {
            LVItem = LV_TeamList->Items[i];
            break;
        }
    }

    if (LVItem == nullptr)
    {
        LVItem = (gcnew ListViewItem(gcnew cli::array< System::String^  >(3)
        {
            marshal_as<String^>(*team->GetPlayerName(0)),
            marshal_as<String^>(*team->GetPlayerName(1)),
                L""
        }, -1));

        LV_TeamList->Items->Add(LVItem);
    }

    LVItem->SubItems[2]->Text = Convert::ToString(team->GetWins());
    LVItem->SubItems[2]->Text += " - ";
    LVItem->SubItems[2]->Text += Convert::ToString(team->GetLoses());

    if (removeTm)
        LVItem->ForeColor = Drawing::SystemColors::ScrollBar;
}

void Project1::MyForm::SetCurrentArena(bool toEnable)
{
    LV_Team_1->Enabled = toEnable;
    LV_Team_2->Enabled = toEnable;

    if (!toEnable)
    {
        ClearCurrentArena();
    }
}

void Project1::MyForm::ClearCurrentArena()
{
    LV_Team_1->Items->Clear();
    LV_Team_2->Items->Clear();
}
