#include "MyForm.h"
#include "Player.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

//#include <cctype>

using namespace System;
using namespace Windows::Forms;
using namespace Project1;
using namespace msclr::interop;

int main(array<String^>^)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MyForm form;
    Application::Run(%form);

    return 0;
}

void MyForm::RemovePlayer(System::Object ^, System::EventArgs ^)
{
    if (LB_PlayerList->SelectedIndex >= 0)
    {
        players->DeletePlayer(marshal_as<std::string>(LB_PlayerList->Items[LB_PlayerList->SelectedIndex]->ToString()));
        LB_PlayerList->Items->RemoveAt(LB_PlayerList->SelectedIndex);
        HandleBegin();
    }
}

void MyForm::RemoveAllPlayers(System::Object ^, System::EventArgs ^)
{
    if (MessageBox::Show("Удалить всех игроков из списка?", "Очистка списка", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
    {
        LB_PlayerList->Items->Clear();
        players->ClearAllPlayers();
        LV_TeamList->Items->Clear();
        SetCurrentArena(false);
        CheckAPLocker();
        HandleBegin();
    }
}

void MyForm::AddPlayerInList(System::Object ^, System::EventArgs ^)
{
    if (TB_AddPlayerTextBox->Text->Length)
    {
        if (!CheckPlayerInList())
            return;

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

void MyForm::BeginTournament(System::Object ^, System::EventArgs ^)
{
    B_Begin->Enabled = false;
    B_Remove->Enabled = false;
    TB_AddPlayerTextBox->Text = nullptr;
    players->SortTeams();
    players->FindGame();
    SendPlayerNames();
}

void MyForm::SelectWinner1(System::Object ^, System::EventArgs ^)
{
    players->SetSelectedWinner(0);
    timer1->Enabled = false;
    B_Winner->Enabled = true;
}

void MyForm::SelectWinner2(System::Object ^, System::EventArgs ^)
{
    players->SetSelectedWinner(1);
    timer1->Enabled = false;
    B_Winner->Enabled = true;
}

void MyForm::DeselectWinner(System::Object ^, System::EventArgs ^)
{
    timer1->Enabled = true;
}

void MyForm::HandleWinner(System::Object ^, System::EventArgs ^)
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

        if (players->GetTeamsCount() == 1)
        {
            String^ msg = "Победители: ";
            msg += marshal_as<String^>(*winner->GetPlayerName(0));
            msg += " и ";
            msg += marshal_as<String^>(*winner->GetPlayerName(1));

            MessageBox::Show(msg, "Турнир завершен!", MessageBoxButtons::OK, MessageBoxIcon::Information);

            SetCurrentArena(false);
            LV_TeamList->Items->Clear();
            TB_AddPlayerTextBox->Text = nullptr;
            players->ClearAllTeams();
            HandleBegin();
            return;
        }
    }

    ClearCurrentArena();
    players->FindGame();
    SendPlayerNames();
}

void MyForm::CurrentArenaTick(System::Object ^, System::EventArgs ^)
{
    B_Winner->Enabled = false;
    timer1->Enabled = false;
}

void MyForm::TextCorrecter(System::Object ^, System::EventArgs ^)
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
        CheckAPLocker();
        TB_AddPlayerTextBox->SelectionStart = Section;
        bCanCheckTextInTextBox = true;
    }
}

void MyForm::ReplacePlayer(System::Object ^, System::EventArgs ^)
{
    if (LB_PlayerList->SelectedIndex >= 0 && TB_AddPlayerTextBox->Text->Length)
    {
        if (!CheckPlayerInList())
            return;

        String^ oldName = LB_PlayerList->Items[LB_PlayerList->SelectedIndex]->ToString();
        std::string ConvertedOldName = marshal_as<std::string>(oldName);
        players->ReplacePlayer(&ConvertedOldName, &marshal_as<std::string>(TB_AddPlayerTextBox->Text));

        LB_PlayerList->Items[LB_PlayerList->SelectedIndex] = TB_AddPlayerTextBox->Text;

        if (LV_Team_1->Items[0]->Text == oldName)
        {
            LV_Team_1->Items[0]->Text = TB_AddPlayerTextBox->Text;
        }
        else if (LV_Team_1->Items[0]->SubItems[1]->Text == oldName)
        {
            LV_Team_1->Items[0]->SubItems[1]->Text = TB_AddPlayerTextBox->Text;
        }
        else if (LV_Team_2->Items[0]->Text == oldName)
        {
            LV_Team_2->Items[0]->Text = TB_AddPlayerTextBox->Text;
        }
        else if (LV_Team_2->Items[0]->SubItems[1]->Text == oldName)
        {
            LV_Team_2->Items[0]->SubItems[1]->Text = TB_AddPlayerTextBox->Text;
        }

        for (int32_t i = 0; i < LV_TeamList->Items->Count; i++)
        {
            if (LV_TeamList->Items[i]->Text == oldName)
            {
                LV_TeamList->Items[i]->Text = TB_AddPlayerTextBox->Text;
                break;
            }
            else if (LV_TeamList->Items[i]->SubItems[1]->Text == oldName)
            {
                LV_TeamList->Items[i]->SubItems[1]->Text = TB_AddPlayerTextBox->Text;
                break;
            }
        }

        TB_AddPlayerTextBox->Text = nullptr;
    }
}

void MyForm::SelectedIndexInListBox(System::Object ^, System::EventArgs ^)
{
    CheckAPLocker();
    B_Remove->Enabled = (LB_PlayerList->SelectedIndex >= 0 && players->GetTeamsCount() == 0);
}

void MyForm::HandleBegin()
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
        case BE_TeamsCount:
        {
            L_BeginErrors->Text = BEGIN_ERROR_TEAMS_COUNT;
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

void MyForm::CheckAPLocker()
{
    bool lockButtons = TB_AddPlayerTextBox->Text == "";

    if (players->GetTeamsCount() > 0)
    {
        B_AddPlayer->Enabled = false;
        B_ReplacePlayer->Enabled = (LB_PlayerList->SelectedIndex >= 0 && !lockButtons);
    }
    else
    {
        B_AddPlayer->Enabled = !lockButtons;
        B_ReplacePlayer->Enabled = false;
    }
}

bool Project1::MyForm::CheckPlayerInList()
{
    for (int32_t i = 0; i < LB_PlayerList->Items->Count; i++)
    {
        if (LB_PlayerList->Items[i]->ToString() == (HealerCheck->Checked ? (TB_AddPlayerTextBox->Text + HealMarker) : TB_AddPlayerTextBox->Text))
        {
            MessageBox::Show("Этот игрок уже есть в списке!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
            return false;
        }
    }

    return true;
}

void MyForm::SendPlayerNames()
{
    SetCurrentArena(true);

    for (uint8_t i = 0; i < MaxTeamInArena; i++)
    {
        ListViewItem^ team = (gcnew ListViewItem(gcnew cli::array< System::String^  >(2)
        {
            marshal_as<String^>(*players->GetTeam(i)->GetPlayerName(0)),
            marshal_as<String^>(*players->GetTeam(i)->GetPlayerName(1))
        }, -1));

        !i ? LV_Team_1->Items->Add(team) : LV_Team_2->Items->Add(team);
    }
}

void MyForm::SendTeamInScoreboard(Team * team, bool removeTm)
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

void MyForm::SetCurrentArena(bool toEnable)
{
    LV_Team_1->Enabled = toEnable;
    LV_Team_2->Enabled = toEnable;

    if (!toEnable)
    {
        ClearCurrentArena();
    }
}

void MyForm::ClearCurrentArena()
{
    LV_Team_1->Items->Clear();
    LV_Team_2->Items->Clear();
}
