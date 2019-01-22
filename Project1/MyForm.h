#pragma once
#define HealMarker " [+]"



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
            bCanCheckTextInTextBox = true;

			InitializeComponent();
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

        System::ComponentModel::IContainer^  components;
    public:
    
        void RemovePlayer(System::Object^  sender, System::EventArgs^  e);
        void RemoveAllPlayers(System::Object^  sender, System::EventArgs^  e);
        void AddPlayerInList(System::Object^  sender, System::EventArgs^  e);

        void TextCorrecter(System::Object^  sender, System::EventArgs^  e);

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>

        bool bCanCheckTextInTextBox;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
            
            this->components = (gcnew System::ComponentModel::Container());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->HealerCheck = (gcnew System::Windows::Forms::CheckBox());
            this->TB_AddPlayerTextBox = (gcnew System::Windows::Forms::TextBox());
            this->B_RemoveAll = (gcnew System::Windows::Forms::Button());
            this->B_Remove = (gcnew System::Windows::Forms::Button());
            this->B_AddPlayer = (gcnew System::Windows::Forms::Button());
            this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
            this->LB_PlayerList = (gcnew System::Windows::Forms::ListBox());
            this->groupBox1->SuspendLayout();
            this->SuspendLayout();
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
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Candara", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                     static_cast<System::Byte>(204)));
            this->groupBox1->Location = System::Drawing::Point(12, 12);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(329, 603);
            this->groupBox1->TabIndex = 4;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Регистрация на турнир";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(172, 19);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(67, 14);
            this->label1->TabIndex = 4;
            this->label1->Text = L"Ник игрока";
            // 
            // HealerCheck
            // 
            this->HealerCheck->AutoSize = true;
            this->HealerCheck->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                                       static_cast<System::Byte>(204)));
            this->HealerCheck->Location = System::Drawing::Point(269, 34);
            this->HealerCheck->Name = L"HealerCheck";
            this->HealerCheck->Size = System::Drawing::Size(56, 22);
            this->HealerCheck->TabIndex = 3;
            this->HealerCheck->Text = L"Хил\?";
            this->HealerCheck->UseVisualStyleBackColor = true;
            // 
            // TB_AddPlayerTextBox
            // 
            this->TB_AddPlayerTextBox->Location = System::Drawing::Point(171, 34);
            this->TB_AddPlayerTextBox->MaxLength = 12;
            this->TB_AddPlayerTextBox->Name = L"TB_AddPlayerTextBox";
            this->TB_AddPlayerTextBox->Size = System::Drawing::Size(95, 22);
            this->TB_AddPlayerTextBox->TabIndex = 0;
            this->toolTip1->SetToolTip(this->TB_AddPlayerTextBox, L"Напишите ник участника");
            this->TB_AddPlayerTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::TextCorrecter);
            // 
            // B_RemoveAll
            // 
            this->B_RemoveAll->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                       static_cast<System::Byte>(204)));
            this->B_RemoveAll->Location = System::Drawing::Point(171, 503);
            this->B_RemoveAll->Name = L"B_RemoveAll";
            this->B_RemoveAll->Size = System::Drawing::Size(145, 52);
            this->B_RemoveAll->TabIndex = 1;
            this->B_RemoveAll->Text = L"Очистить список";
            this->toolTip1->SetToolTip(this->B_RemoveAll, L"Удаление всех игроков из списка");
            this->B_RemoveAll->UseVisualStyleBackColor = true;
            this->B_RemoveAll->Click += gcnew System::EventHandler(this, &MyForm::RemoveAllPlayers);
            // 
            // B_Remove
            // 
            this->B_Remove->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                    static_cast<System::Byte>(204)));
            this->B_Remove->Location = System::Drawing::Point(171, 211);
            this->B_Remove->Name = L"B_Remove";
            this->B_Remove->Size = System::Drawing::Size(145, 52);
            this->B_Remove->TabIndex = 1;
            this->B_Remove->Text = L"Удалить игрока";
            this->B_Remove->UseVisualStyleBackColor = true;
            this->B_Remove->Click += gcnew System::EventHandler(this, &MyForm::RemovePlayer);
            // 
            // B_AddPlayer
            // 
            this->B_AddPlayer->Font = (gcnew System::Drawing::Font(L"Candara", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                                       static_cast<System::Byte>(204)));
            this->B_AddPlayer->Location = System::Drawing::Point(171, 62);
            this->B_AddPlayer->Name = L"B_AddPlayer";
            this->B_AddPlayer->Size = System::Drawing::Size(145, 52);
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
            this->LB_PlayerList->Location = System::Drawing::Point(15, 19);
            this->LB_PlayerList->Name = L"LB_PlayerList";
            this->LB_PlayerList->Size = System::Drawing::Size(150, 536);
            this->LB_PlayerList->TabIndex = 2;
            // 
            // MyForm
            // 
            this->AcceptButton = this->B_AddPlayer;
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
            this->ClientSize = System::Drawing::Size(1355, 658);
            this->Controls->Add(this->groupBox1);
            this->Cursor = System::Windows::Forms::Cursors::Default;
            this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Name = L"MyForm";
            this->Text = L"Black Axe";
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    };
}
