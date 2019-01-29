#pragma once

#include "Players.h"

#define HealMarker " [+]"

#define BEGIN_ERROR_NONE "Можно начинать!"
#define BEGIN_ERROR_PLAYERS_COUNT "Не парное количество игроков!"
#define BEGIN_ERROR_HEALERS_COUNT "Хилов больше чем дамагеров!"

enum BeginErrors
{
    BE_None,
    BE_PlayersCount,
    BE_HealersCount
};

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
            players = new Players();
            bCanCheckTextInTextBox = true;

			InitializeComponent();
            HandleBegin();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
            if (players)
            {
                delete players;
                players = nullptr;
            }

			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::TextBox^  TB_AddPlayerTextBox;
    private: System::Windows::Forms::Button^  B_AddPlayer;

    private: System::Windows::Forms::ToolTip^  toolTip1;
    private: System::Windows::Forms::CheckBox^  HealerCheck;


    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::Button^  B_Remove;
    private: System::Windows::Forms::Button^  B_RemoveAll;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::ListBox^  LB_PlayerList;


    private: System::Windows::Forms::ListView^  listView1;
    private: System::Windows::Forms::ListView^  listView2;
    private: System::Windows::Forms::ListView^  listView3;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::GroupBox^  P_CurArena;
    private: System::Windows::Forms::Label^  L_BeginErrors;
    private: System::Windows::Forms::Button^  B_Begin;
    private: System::Windows::Forms::GroupBox^  groupBox2;

    private: System::Windows::Forms::GroupBox^  groupBox3;
    private: System::Windows::Forms::Button^  B_Winner;



















        System::ComponentModel::IContainer^  components;
    public:
    
        void RemovePlayer(System::Object^  sender, System::EventArgs^  e);
        void RemoveAllPlayers(System::Object^  sender, System::EventArgs^  e);
        void AddPlayerInList(System::Object^  sender, System::EventArgs^  e);
        void BeginTournament(System::Object^  sender, System::EventArgs^  e);

        void TextCorrecter(System::Object^  sender, System::EventArgs^  e);

        void HandleBegin();

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

        bool bCanCheckTextInTextBox;
        Players* players;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::Windows::Forms::ColumnHeader^  columnHeader1;
            System::Windows::Forms::ListViewItem^  listViewItem1 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3)
            {
                L"Tilandra [+]",
                    L"Симела", L"88 - 88"
            }, -1));
            System::Windows::Forms::ListViewItem^  listViewItem2 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3)
            {
                L"Vnepolovaya [+]",
                    L"Кл", L"99 - 77"
            }, -1));
            System::Windows::Forms::ListViewItem^  listViewItem3 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3)
            {
                L"Wwwwwwwwwwww [+]",
                    L"Сигмарус", L"57 - 55"
            }, -1, System::Drawing::SystemColors::ScrollBar, System::Drawing::Color::Empty, nullptr));
            System::Windows::Forms::ColumnHeader^  columnHeader2;
            System::Windows::Forms::ColumnHeader^  columnHeader3;
            System::Windows::Forms::ListViewItem^  listViewItem4 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3)
            {
                L"Tilandra [+]",
                    L"Симела", L"88 - 88"
            }, -1));
            System::Windows::Forms::ColumnHeader^  columnHeader4;
            System::Windows::Forms::ColumnHeader^  columnHeader5;
            System::Windows::Forms::ListViewItem^  listViewItem5 = (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^  >(3)
            {
                L"Tilandra [+]",
                    L"Симела", L"88 - 88"
            }, -1));
            System::Windows::Forms::ColumnHeader^  columnHeader6;
            System::Windows::Forms::ColumnHeader^  columnHeader7;
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->listView1 = (gcnew System::Windows::Forms::ListView());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->LB_PlayerList = (gcnew System::Windows::Forms::ListBox());
            this->HealerCheck = (gcnew System::Windows::Forms::CheckBox());
            this->TB_AddPlayerTextBox = (gcnew System::Windows::Forms::TextBox());
            this->B_RemoveAll = (gcnew System::Windows::Forms::Button());
            this->B_Remove = (gcnew System::Windows::Forms::Button());
            this->B_AddPlayer = (gcnew System::Windows::Forms::Button());
            this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
            this->listView2 = (gcnew System::Windows::Forms::ListView());
            this->listView3 = (gcnew System::Windows::Forms::ListView());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->P_CurArena = (gcnew System::Windows::Forms::GroupBox());
            this->L_BeginErrors = (gcnew System::Windows::Forms::Label());
            this->B_Begin = (gcnew System::Windows::Forms::Button());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->B_Winner = (gcnew System::Windows::Forms::Button());
            columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
            columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
            columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
            columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
            columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
            columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
            columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
            this->groupBox1->SuspendLayout();
            this->P_CurArena->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->SuspendLayout();
            // 
            // columnHeader1
            // 
            columnHeader1->Text = L"Игрок1";
            columnHeader1->Width = 152;
            // 
            // listView1
            // 
            this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3)
            {
                columnHeader1, columnHeader2,
                    columnHeader3
            });
            this->listView1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->listView1->FullRowSelect = true;
            this->listView1->GridLines = true;
            this->listView1->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
            this->listView1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(3)
            {
                listViewItem1, listViewItem2,
                    listViewItem3
            });
            this->listView1->Location = System::Drawing::Point(6, 19);
            this->listView1->MultiSelect = false;
            this->listView1->Name = L"listView1";
            this->listView1->Size = System::Drawing::Size(380, 377);
            this->listView1->TabIndex = 7;
            this->listView1->UseCompatibleStateImageBehavior = false;
            this->listView1->View = System::Windows::Forms::View::Details;
            // 
            // columnHeader2
            // 
            columnHeader2->Text = L"Игрок2";
            columnHeader2->Width = 152;
            // 
            // columnHeader3
            // 
            columnHeader3->Text = L"В";
            columnHeader3->Width = 54;
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->LB_PlayerList);
            this->groupBox1->Controls->Add(this->HealerCheck);
            this->groupBox1->Controls->Add(this->TB_AddPlayerTextBox);
            this->groupBox1->Controls->Add(this->B_RemoveAll);
            this->groupBox1->Controls->Add(this->B_Remove);
            this->groupBox1->Controls->Add(this->B_AddPlayer);
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Candara", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->groupBox1->Location = System::Drawing::Point(12, 77);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(299, 546);
            this->groupBox1->TabIndex = 4;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Регистрация на турнир";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(163, 19);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(67, 14);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Ник игрока";
            // 
            // LB_PlayerList
            // 
            this->LB_PlayerList->Font = (gcnew System::Drawing::Font(L"Candara", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(204)));
            this->LB_PlayerList->FormattingEnabled = true;
            this->LB_PlayerList->ItemHeight = 19;
            this->LB_PlayerList->Items->AddRange(gcnew cli::array< System::Object^  >(3)
            {
                L"Vnepolovaya [+]", L"Deadthrow", L"Симела"
            });
            this->LB_PlayerList->Location = System::Drawing::Point(6, 19);
            this->LB_PlayerList->Name = L"LB_PlayerList";
            this->LB_PlayerList->Size = System::Drawing::Size(150, 517);
            this->LB_PlayerList->TabIndex = 2;
            // 
            // HealerCheck
            // 
            this->HealerCheck->AutoSize = true;
            this->HealerCheck->Font = (gcnew System::Drawing::Font(L"Candara", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                       static_cast<System::Byte>(204)));
            this->HealerCheck->Location = System::Drawing::Point(162, 63);
            this->HealerCheck->Name = L"HealerCheck";
            this->HealerCheck->Size = System::Drawing::Size(96, 19);
            this->HealerCheck->TabIndex = 3;
            this->HealerCheck->Text = L"Это хиллер\?";
            this->HealerCheck->UseVisualStyleBackColor = true;
            // 
            // TB_AddPlayerTextBox
            // 
            this->TB_AddPlayerTextBox->Location = System::Drawing::Point(162, 35);
            this->TB_AddPlayerTextBox->MaxLength = 12;
            this->TB_AddPlayerTextBox->Name = L"TB_AddPlayerTextBox";
            this->TB_AddPlayerTextBox->Size = System::Drawing::Size(131, 22);
            this->TB_AddPlayerTextBox->TabIndex = 0;
            this->toolTip1->SetToolTip(this->TB_AddPlayerTextBox, L"Напишите ник участника");
            this->TB_AddPlayerTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::TextCorrecter);
            // 
            // B_RemoveAll
            // 
            this->B_RemoveAll->Cursor = System::Windows::Forms::Cursors::Hand;
            this->B_RemoveAll->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                       static_cast<System::Byte>(204)));
            this->B_RemoveAll->Location = System::Drawing::Point(162, 485);
            this->B_RemoveAll->Name = L"B_RemoveAll";
            this->B_RemoveAll->Size = System::Drawing::Size(131, 52);
            this->B_RemoveAll->TabIndex = 1;
            this->B_RemoveAll->Text = L"Очистить список";
            this->toolTip1->SetToolTip(this->B_RemoveAll, L"Удаление всех игроков из списка");
            this->B_RemoveAll->UseVisualStyleBackColor = true;
            this->B_RemoveAll->Click += gcnew System::EventHandler(this, &MyForm::RemoveAllPlayers);
            // 
            // B_Remove
            // 
            this->B_Remove->Cursor = System::Windows::Forms::Cursors::Hand;
            this->B_Remove->FlatStyle = System::Windows::Forms::FlatStyle::System;
            this->B_Remove->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                    static_cast<System::Byte>(204)));
            this->B_Remove->Location = System::Drawing::Point(162, 298);
            this->B_Remove->Name = L"B_Remove";
            this->B_Remove->Size = System::Drawing::Size(131, 52);
            this->B_Remove->TabIndex = 1;
            this->B_Remove->Text = L"Удалить игрока";
            this->B_Remove->UseVisualStyleBackColor = true;
            this->B_Remove->Click += gcnew System::EventHandler(this, &MyForm::RemovePlayer);
            // 
            // B_AddPlayer
            // 
            this->B_AddPlayer->Cursor = System::Windows::Forms::Cursors::Hand;
            this->B_AddPlayer->FlatStyle = System::Windows::Forms::FlatStyle::System;
            this->B_AddPlayer->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                       static_cast<System::Byte>(204)));
            this->B_AddPlayer->Location = System::Drawing::Point(162, 88);
            this->B_AddPlayer->Name = L"B_AddPlayer";
            this->B_AddPlayer->Size = System::Drawing::Size(131, 52);
            this->B_AddPlayer->TabIndex = 1;
            this->B_AddPlayer->Text = L"Добавить игрока";
            this->B_AddPlayer->UseVisualStyleBackColor = true;
            this->B_AddPlayer->Click += gcnew System::EventHandler(this, &MyForm::AddPlayerInList);
            // 
            // toolTip1
            // 
            this->toolTip1->AutoPopDelay = 10000;
            this->toolTip1->InitialDelay = 1000;
            this->toolTip1->ReshowDelay = 100;
            this->toolTip1->ShowAlways = true;
            // 
            // listView2
            // 
            this->listView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2)
            {
                columnHeader4, columnHeader5
            });
            this->listView2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->listView2->FullRowSelect = true;
            this->listView2->GridLines = true;
            this->listView2->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
            this->listView2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1)
            {
                listViewItem4
            });
            this->listView2->Location = System::Drawing::Point(14, 19);
            this->listView2->MultiSelect = false;
            this->listView2->Name = L"listView2";
            this->listView2->Size = System::Drawing::Size(312, 25);
            this->listView2->TabIndex = 7;
            this->listView2->UseCompatibleStateImageBehavior = false;
            this->listView2->View = System::Windows::Forms::View::Details;
            // 
            // columnHeader4
            // 
            columnHeader4->Text = L"Игрок1";
            columnHeader4->Width = 152;
            // 
            // columnHeader5
            // 
            columnHeader5->Text = L"Игрок2";
            columnHeader5->Width = 152;
            // 
            // listView3
            // 
            this->listView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2)
            {
                columnHeader6, columnHeader7
            });
            this->listView3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->listView3->FullRowSelect = true;
            this->listView3->GridLines = true;
            this->listView3->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::None;
            this->listView3->Items->AddRange(gcnew cli::array< System::Windows::Forms::ListViewItem^  >(1)
            {
                listViewItem5
            });
            this->listView3->Location = System::Drawing::Point(372, 19);
            this->listView3->MultiSelect = false;
            this->listView3->Name = L"listView3";
            this->listView3->Size = System::Drawing::Size(312, 25);
            this->listView3->TabIndex = 7;
            this->listView3->UseCompatibleStateImageBehavior = false;
            this->listView3->View = System::Windows::Forms::View::Details;
            // 
            // columnHeader6
            // 
            columnHeader6->Text = L"Игрок1";
            columnHeader6->Width = 152;
            // 
            // columnHeader7
            // 
            columnHeader7->Text = L"Игрок2";
            columnHeader7->Width = 152;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                  static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(332, 19);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(34, 25);
            this->label2->TabIndex = 8;
            this->label2->Text = L"VS";
            // 
            // P_CurArena
            // 
            this->P_CurArena->Controls->Add(this->listView2);
            this->P_CurArena->Controls->Add(this->label2);
            this->P_CurArena->Controls->Add(this->listView3);
            this->P_CurArena->Font = (gcnew System::Drawing::Font(L"Candara", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                      static_cast<System::Byte>(204)));
            this->P_CurArena->Location = System::Drawing::Point(12, 12);
            this->P_CurArena->Name = L"P_CurArena";
            this->P_CurArena->Size = System::Drawing::Size(697, 56);
            this->P_CurArena->TabIndex = 9;
            this->P_CurArena->TabStop = false;
            this->P_CurArena->Text = L"Текущая арена";
            // 
            // L_BeginErrors
            // 
            this->L_BeginErrors->AutoSize = true;
            this->L_BeginErrors->Font = (gcnew System::Drawing::Font(L"Candara", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                         static_cast<System::Byte>(204)));
            this->L_BeginErrors->Location = System::Drawing::Point(157, 33);
            this->L_BeginErrors->Name = L"L_BeginErrors";
            this->L_BeginErrors->Size = System::Drawing::Size(39, 15);
            this->L_BeginErrors->TabIndex = 5;
            this->L_BeginErrors->Text = L"label2";
            // 
            // B_Begin
            // 
            this->B_Begin->BackColor = System::Drawing::SystemColors::ControlDark;
            this->B_Begin->Cursor = System::Windows::Forms::Cursors::Hand;
            this->B_Begin->Enabled = false;
            this->B_Begin->FlatStyle = System::Windows::Forms::FlatStyle::System;
            this->B_Begin->Font = (gcnew System::Drawing::Font(L"Candara", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                   static_cast<System::Byte>(204)));
            this->B_Begin->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->B_Begin->Location = System::Drawing::Point(6, 14);
            this->B_Begin->Name = L"B_Begin";
            this->B_Begin->Size = System::Drawing::Size(145, 52);
            this->B_Begin->TabIndex = 1;
            this->B_Begin->Text = L"Начать турнир!";
            this->B_Begin->UseMnemonic = false;
            this->B_Begin->UseVisualStyleBackColor = true;
            this->B_Begin->Click += gcnew System::EventHandler(this, &MyForm::BeginTournament);
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->listView1);
            this->groupBox2->Font = (gcnew System::Drawing::Font(L"Candara", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->groupBox2->Location = System::Drawing::Point(317, 140);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(392, 402);
            this->groupBox2->TabIndex = 10;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Таблица команд с ведением счета";
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->B_Begin);
            this->groupBox3->Controls->Add(this->L_BeginErrors);
            this->groupBox3->Font = (gcnew System::Drawing::Font(L"Candara", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->groupBox3->Location = System::Drawing::Point(317, 548);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(392, 75);
            this->groupBox3->TabIndex = 11;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Панель управления турниром";
            // 
            // B_Winner
            // 
            this->B_Winner->BackColor = System::Drawing::SystemColors::ControlDark;
            this->B_Winner->Cursor = System::Windows::Forms::Cursors::Hand;
            this->B_Winner->Enabled = false;
            this->B_Winner->FlatStyle = System::Windows::Forms::FlatStyle::System;
            this->B_Winner->Font = (gcnew System::Drawing::Font(L"Candara", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                    static_cast<System::Byte>(204)));
            this->B_Winner->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->B_Winner->Location = System::Drawing::Point(323, 83);
            this->B_Winner->Name = L"B_Winner";
            this->B_Winner->Size = System::Drawing::Size(386, 51);
            this->B_Winner->TabIndex = 1;
            this->B_Winner->Text = L"Выбрать победителя!";
            this->B_Winner->UseMnemonic = false;
            this->B_Winner->UseVisualStyleBackColor = true;
            // 
            // MyForm
            // 
            this->AcceptButton = this->B_AddPlayer;
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->ClientSize = System::Drawing::Size(722, 638);
            this->Controls->Add(this->B_Winner);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->P_CurArena);
            this->Controls->Add(this->groupBox1);
            this->Cursor = System::Windows::Forms::Cursors::Default;
            this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximumSize = System::Drawing::Size(738, 672);
            this->MinimumSize = System::Drawing::Size(738, 672);
            this->Name = L"MyForm";
            this->Text = L"Black Axe";
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->P_CurArena->ResumeLayout(false);
            this->P_CurArena->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox3->ResumeLayout(false);
            this->groupBox3->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}
