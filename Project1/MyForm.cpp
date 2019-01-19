#include "MyForm.h"
#include <iostream>
//#include <cctype>

using namespace System;
using namespace Windows::Forms;
using namespace Project1;

int main(array<String^>^ args)
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
        LB_PlayerList->Items->RemoveAt(LB_PlayerList->SelectedIndex);
}

void MyForm::RemoveAllPlayers(System::Object ^ /*sender*/, System::EventArgs ^ /*e*/)
{
    if (MessageBox::Show("Удалить всех игроков из списка?", "Очистка списка", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes)
    {
        LB_PlayerList->Items->Clear();
    }
}

void MyForm::AddPlayerInList(System::Object ^ /*sender*/, System::EventArgs ^/* e*/)
{
    if (TB_AddPlayerTextBox->Text->Length)
    {
        for (int i = 0; i < LB_PlayerList->Items->Count; i++)
        {
            if (LB_PlayerList->Items[i]->ToString() == TB_AddPlayerTextBox->Text)
            {
                MessageBox::Show("Этот игрок уже есть в списке!", "Предупреждение", MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }
        }

        LB_PlayerList->Items->Add(TB_AddPlayerTextBox->Text);
        TB_AddPlayerTextBox->Text = nullptr;
    }
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
