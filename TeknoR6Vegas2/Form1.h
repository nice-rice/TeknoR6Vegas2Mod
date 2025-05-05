#pragma once
#include "Manager.h"
#include <windows.h>
#include <time.h>

namespace TeknoR6Vegas2 {
	ModManager* m_pManager;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Security::Cryptography;
	using namespace System::IO;
	using namespace System::Threading;
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(ModManager& ptr){
			m_pManager = &ptr;
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1(){
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ TitlePictureBox;

	protected:

	private: System::Windows::Forms::GroupBox^ HostOptions; //groupBox1
		private: System::Windows::Forms::CheckBox^ IsHostBox; //checkBox2
		private: System::Windows::Forms::Label^ ServerNameLabel;
		private: System::Windows::Forms::TextBox^ ServerNameBox;
		private: System::Windows::Forms::Label^ ServerPWLabel;
		private: System::Windows::Forms::TextBox^ PasswordBox;
		private: System::Windows::Forms::Label^ RespawnCountLabel;
		private: System::Windows::Forms::ComboBox^ RespawnDrop; //comboBox3
			   //checkBox5
		private: System::Windows::Forms::Label^ DifficultyLabel;
		private: System::Windows::Forms::ComboBox^ DifficultyDrop;
			   //checkBox6

	private: System::Windows::Forms::GroupBox^ TerrorHuntGroup;
		private: System::Windows::Forms::Label^ SpawnRateLabel;
		private: System::Windows::Forms::ComboBox^ SpawnRateDrop;
		private: System::Windows::Forms::Label^ TerrorCountLabel;//label2
		private: System::Windows::Forms::ComboBox^ TerrorCountDrop; //comboBox2
			   //checkBox3
		private: System::Windows::Forms::Label^ MaxPlayersLabel;//label 1
			   // comboBox1
			   //checkBox4
		private: System::Windows::Forms::Label^ SelectMapLabel;
		private: System::Windows::Forms::ComboBox^ MapListDrop;
	
	private: System::Windows::Forms::GroupBox^ LaunchBoxGroup; //groupBox3
		private: System::Windows::Forms::Button^ LaunchButton; //button1	  
		private: System::Windows::Forms::RichTextBox^ LogTextBox; //richTextBox1
		private: System::Windows::Forms::Label^ GameRunningLabel; //label15
	

	private: System::Windows::Forms::GroupBox^ OtherModsGroup;
		   //checkBox7
			   //checkBox1


	private: System::Windows::Forms::GroupBox^ OtherOptionsGroup; //groupBox2
		private: System::Windows::Forms::ComboBox^ TimeLimitDrop;
		private: System::Windows::Forms::Label^ TimeLimitLabel;
	private: System::Windows::Forms::Button^ ApplyButton;
	private: System::Windows::Forms::ComboBox^ MaxPlayersDrop;
	private: System::Windows::Forms::CheckBox^ ReadyUpCheck;
	private: System::Windows::Forms::CheckBox^ SoundPatchBox;
	private: System::Windows::Forms::CheckBox^ InternetBox;
	private: System::Windows::Forms::CheckBox^ GraphicsBox;

	private: System::Windows::Forms::ComboBox^ GameModeBox;
	private: System::Windows::Forms::Label^ GameModeLabel;
	private: System::Windows::Forms::CheckBox^ GadgetsCheckbox;
	private: System::Windows::Forms::CheckBox^ AmmoCheckbox;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
void InitializeComponent(void){
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
	this->TitlePictureBox = (gcnew System::Windows::Forms::PictureBox());
	this->MaxPlayersLabel = (gcnew System::Windows::Forms::Label());
	this->TerrorCountLabel = (gcnew System::Windows::Forms::Label());
	this->LaunchButton = (gcnew System::Windows::Forms::Button());
	this->HostOptions = (gcnew System::Windows::Forms::GroupBox());
	this->GameModeBox = (gcnew System::Windows::Forms::ComboBox());
	this->GameModeLabel = (gcnew System::Windows::Forms::Label());
	this->ServerPWLabel = (gcnew System::Windows::Forms::Label());
	this->ServerNameBox = (gcnew System::Windows::Forms::TextBox());
	this->TimeLimitDrop = (gcnew System::Windows::Forms::ComboBox());
	this->TimeLimitLabel = (gcnew System::Windows::Forms::Label());
	this->PasswordBox = (gcnew System::Windows::Forms::TextBox());
	this->ServerNameLabel = (gcnew System::Windows::Forms::Label());
	this->RespawnDrop = (gcnew System::Windows::Forms::ComboBox());
	this->RespawnCountLabel = (gcnew System::Windows::Forms::Label());
	this->IsHostBox = (gcnew System::Windows::Forms::CheckBox());
	this->DifficultyDrop = (gcnew System::Windows::Forms::ComboBox());
	this->DifficultyLabel = (gcnew System::Windows::Forms::Label());
	this->LogTextBox = (gcnew System::Windows::Forms::RichTextBox());
	this->GameRunningLabel = (gcnew System::Windows::Forms::Label());
	this->LaunchBoxGroup = (gcnew System::Windows::Forms::GroupBox());
	this->ApplyButton = (gcnew System::Windows::Forms::Button());
	this->OtherOptionsGroup = (gcnew System::Windows::Forms::GroupBox());
	this->MapListDrop = (gcnew System::Windows::Forms::ComboBox());
	this->MaxPlayersDrop = (gcnew System::Windows::Forms::ComboBox());
	this->ReadyUpCheck = (gcnew System::Windows::Forms::CheckBox());
	this->SelectMapLabel = (gcnew System::Windows::Forms::Label());
	this->OtherModsGroup = (gcnew System::Windows::Forms::GroupBox());
	this->GadgetsCheckbox = (gcnew System::Windows::Forms::CheckBox());
	this->AmmoCheckbox = (gcnew System::Windows::Forms::CheckBox());
	this->GraphicsBox = (gcnew System::Windows::Forms::CheckBox());
	this->SoundPatchBox = (gcnew System::Windows::Forms::CheckBox());
	this->InternetBox = (gcnew System::Windows::Forms::CheckBox());
	this->TerrorHuntGroup = (gcnew System::Windows::Forms::GroupBox());
	this->TerrorCountDrop = (gcnew System::Windows::Forms::ComboBox());
	this->SpawnRateDrop = (gcnew System::Windows::Forms::ComboBox());
	this->SpawnRateLabel = (gcnew System::Windows::Forms::Label());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TitlePictureBox))->BeginInit();
	this->HostOptions->SuspendLayout();
	this->LaunchBoxGroup->SuspendLayout();
	this->OtherOptionsGroup->SuspendLayout();
	this->OtherModsGroup->SuspendLayout();
	this->TerrorHuntGroup->SuspendLayout();
	this->SuspendLayout();
	// 
	// TitlePictureBox
	// 
	this->TitlePictureBox->BackColor = System::Drawing::Color::Transparent;
	this->TitlePictureBox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"TitlePictureBox.Image")));
	this->TitlePictureBox->Location = System::Drawing::Point(559, 1);
	this->TitlePictureBox->Name = L"TitlePictureBox";
	this->TitlePictureBox->Size = System::Drawing::Size(466, 101);
	this->TitlePictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
	this->TitlePictureBox->TabIndex = 0;
	this->TitlePictureBox->TabStop = false;
	// 
	// MaxPlayersLabel
	// 
	this->MaxPlayersLabel->AutoSize = true;
	this->MaxPlayersLabel->BackColor = System::Drawing::Color::Transparent;
	this->MaxPlayersLabel->Location = System::Drawing::Point(11, 57);
	this->MaxPlayersLabel->Name = L"MaxPlayersLabel";
	this->MaxPlayersLabel->Size = System::Drawing::Size(64, 13);
	this->MaxPlayersLabel->TabIndex = 2;
	this->MaxPlayersLabel->Text = L"Max Players";
	// 
	// TerrorCountLabel
	// 
	this->TerrorCountLabel->AutoSize = true;
	this->TerrorCountLabel->BackColor = System::Drawing::Color::Transparent;
	this->TerrorCountLabel->Location = System::Drawing::Point(6, 86);
	this->TerrorCountLabel->Name = L"TerrorCountLabel";
	this->TerrorCountLabel->Size = System::Drawing::Size(76, 13);
	this->TerrorCountLabel->TabIndex = 4;
	this->TerrorCountLabel->Text = L"Terrorist Count";
	// 
	// LaunchButton
	// 
	this->LaunchButton->Location = System::Drawing::Point(144, 227);
	this->LaunchButton->Name = L"LaunchButton";
	this->LaunchButton->Size = System::Drawing::Size(75, 23);
	this->LaunchButton->TabIndex = 5;
	this->LaunchButton->Text = L"Launch";
	this->LaunchButton->UseVisualStyleBackColor = true;
	this->LaunchButton->Click += gcnew System::EventHandler(this, &Form1::LaunchButton_Click);
	// 
	// HostOptions
	// 
	this->HostOptions->Controls->Add(this->GameModeBox);
	this->HostOptions->Controls->Add(this->GameModeLabel);
	this->HostOptions->Controls->Add(this->ServerPWLabel);
	this->HostOptions->Controls->Add(this->ServerNameBox);
	this->HostOptions->Controls->Add(this->TimeLimitDrop);
	this->HostOptions->Controls->Add(this->TimeLimitLabel);
	this->HostOptions->Controls->Add(this->PasswordBox);
	this->HostOptions->Controls->Add(this->ServerNameLabel);
	this->HostOptions->Controls->Add(this->RespawnDrop);
	this->HostOptions->Controls->Add(this->RespawnCountLabel);
	this->HostOptions->Controls->Add(this->IsHostBox);
	this->HostOptions->Location = System::Drawing::Point(63, 69);
	this->HostOptions->Name = L"HostOptions";
	this->HostOptions->Size = System::Drawing::Size(264, 293);
	this->HostOptions->TabIndex = 7;
	this->HostOptions->TabStop = false;
	this->HostOptions->Text = L"Host options";
	// 
	// GameModeBox
	// 
	this->GameModeBox->FormattingEnabled = true;
	this->GameModeBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
		L"CoopTerroristHunt", L"AttackDefend", L"Deathmatch",
			L"TeamDeathmatch", L"TeamLeader", L"Conquest", L"Sharpshooter", L"TeamSharpshooter"
	});
	this->GameModeBox->Location = System::Drawing::Point(10, 166);
	this->GameModeBox->Name = L"GameModeBox";
	this->GameModeBox->Size = System::Drawing::Size(218, 21);
	this->GameModeBox->TabIndex = 25;
	// 
	// GameModeLabel
	// 
	this->GameModeLabel->AutoSize = true;
	this->GameModeLabel->BackColor = System::Drawing::Color::Transparent;
	this->GameModeLabel->Location = System::Drawing::Point(11, 150);
	this->GameModeLabel->Name = L"GameModeLabel";
	this->GameModeLabel->Size = System::Drawing::Size(65, 13);
	this->GameModeLabel->TabIndex = 24;
	this->GameModeLabel->Text = L"Game Mode";
	// 
	// ServerPWLabel
	// 
	this->ServerPWLabel->AutoSize = true;
	this->ServerPWLabel->BackColor = System::Drawing::Color::Transparent;
	this->ServerPWLabel->Location = System::Drawing::Point(11, 98);
	this->ServerPWLabel->Name = L"ServerPWLabel";
	this->ServerPWLabel->Size = System::Drawing::Size(87, 13);
	this->ServerPWLabel->TabIndex = 19;
	this->ServerPWLabel->Text = L"Server Password";
	// 
	// ServerNameBox
	// 
	this->ServerNameBox->Location = System::Drawing::Point(10, 66);
	this->ServerNameBox->Name = L"ServerNameBox";
	this->ServerNameBox->Size = System::Drawing::Size(217, 20);
	this->ServerNameBox->TabIndex = 17;
	// 
	// TimeLimitDrop
	// 
	this->TimeLimitDrop->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->TimeLimitDrop->FormattingEnabled = true;
	this->TimeLimitDrop->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"3", L"5", L"10", L"15", L"20" });
	this->TimeLimitDrop->Location = System::Drawing::Point(9, 254);
	this->TimeLimitDrop->Name = L"TimeLimitDrop";
	this->TimeLimitDrop->Size = System::Drawing::Size(218, 21);
	this->TimeLimitDrop->TabIndex = 21;
	// 
	// TimeLimitLabel
	// 
	this->TimeLimitLabel->AutoSize = true;
	this->TimeLimitLabel->BackColor = System::Drawing::Color::Transparent;
	this->TimeLimitLabel->Location = System::Drawing::Point(10, 238);
	this->TimeLimitLabel->Name = L"TimeLimitLabel";
	this->TimeLimitLabel->Size = System::Drawing::Size(89, 13);
	this->TimeLimitLabel->TabIndex = 20;
	this->TimeLimitLabel->Text = L"Round Time Limit";
	// 
	// PasswordBox
	// 
	this->PasswordBox->Location = System::Drawing::Point(11, 114);
	this->PasswordBox->Name = L"PasswordBox";
	this->PasswordBox->Size = System::Drawing::Size(217, 20);
	this->PasswordBox->TabIndex = 18;
	// 
	// ServerNameLabel
	// 
	this->ServerNameLabel->AutoSize = true;
	this->ServerNameLabel->BackColor = System::Drawing::Color::Transparent;
	this->ServerNameLabel->Location = System::Drawing::Point(11, 50);
	this->ServerNameLabel->Name = L"ServerNameLabel";
	this->ServerNameLabel->Size = System::Drawing::Size(69, 13);
	this->ServerNameLabel->TabIndex = 11;
	this->ServerNameLabel->Text = L"Server Name";
	// 
	// RespawnDrop
	// 
	this->RespawnDrop->DisplayMember = L"1";
	this->RespawnDrop->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->RespawnDrop->FormattingEnabled = true;
	this->RespawnDrop->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"None", L"1", L"2", L"3", L"Unlimited" });
	this->RespawnDrop->Location = System::Drawing::Point(11, 206);
	this->RespawnDrop->Name = L"RespawnDrop";
	this->RespawnDrop->Size = System::Drawing::Size(216, 21);
	this->RespawnDrop->TabIndex = 10;
	// 
	// RespawnCountLabel
	// 
	this->RespawnCountLabel->AutoSize = true;
	this->RespawnCountLabel->BackColor = System::Drawing::Color::Transparent;
	this->RespawnCountLabel->Location = System::Drawing::Point(11, 190);
	this->RespawnCountLabel->Name = L"RespawnCountLabel";
	this->RespawnCountLabel->Size = System::Drawing::Size(83, 13);
	this->RespawnCountLabel->TabIndex = 11;
	this->RespawnCountLabel->Text = L"Respawn Count";
	// 
	// IsHostBox
	// 
	this->IsHostBox->AutoSize = true;
	this->IsHostBox->Checked = true;
	this->IsHostBox->CheckState = System::Windows::Forms::CheckState::Checked;
	this->IsHostBox->Location = System::Drawing::Point(11, 25);
	this->IsHostBox->Name = L"IsHostBox";
	this->IsHostBox->Size = System::Drawing::Size(78, 17);
	this->IsHostBox->TabIndex = 9;
	this->IsHostBox->Text = L"Run SADS";
	this->IsHostBox->UseVisualStyleBackColor = true;
	this->IsHostBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::IsHostBox_CheckedChanged);
	// 
	// DifficultyDrop
	// 
	this->DifficultyDrop->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->DifficultyDrop->FormattingEnabled = true;
	this->DifficultyDrop->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Easy", L"Normal", L"Realistic" });
	this->DifficultyDrop->Location = System::Drawing::Point(6, 156);
	this->DifficultyDrop->Name = L"DifficultyDrop";
	this->DifficultyDrop->Size = System::Drawing::Size(218, 21);
	this->DifficultyDrop->TabIndex = 19;
	// 
	// DifficultyLabel
	// 
	this->DifficultyLabel->AutoSize = true;
	this->DifficultyLabel->BackColor = System::Drawing::Color::Transparent;
	this->DifficultyLabel->Location = System::Drawing::Point(7, 140);
	this->DifficultyLabel->Name = L"DifficultyLabel";
	this->DifficultyLabel->Size = System::Drawing::Size(47, 13);
	this->DifficultyLabel->TabIndex = 4;
	this->DifficultyLabel->Text = L"Difficulty";
	// 
	// LogTextBox
	// 
	this->LogTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
	this->LogTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->LogTextBox->Location = System::Drawing::Point(0, 51);
	this->LogTextBox->Name = L"LogTextBox";
	this->LogTextBox->Size = System::Drawing::Size(264, 158);
	this->LogTextBox->TabIndex = 9;
	this->LogTextBox->Text = L"";
	// 
	// GameRunningLabel
	// 
	this->GameRunningLabel->AutoSize = true;
	this->GameRunningLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->GameRunningLabel->Location = System::Drawing::Point(6, 227);
	this->GameRunningLabel->Name = L"GameRunningLabel";
	this->GameRunningLabel->Size = System::Drawing::Size(132, 20);
	this->GameRunningLabel->TabIndex = 10;
	this->GameRunningLabel->Text = L"Game is Running";
	this->GameRunningLabel->Visible = false;
	// 
	// LaunchBoxGroup
	// 
	this->LaunchBoxGroup->Controls->Add(this->ApplyButton);
	this->LaunchBoxGroup->Controls->Add(this->LaunchButton);
	this->LaunchBoxGroup->Controls->Add(this->GameRunningLabel);
	this->LaunchBoxGroup->Controls->Add(this->LogTextBox);
	this->LaunchBoxGroup->Location = System::Drawing::Point(388, 285);
	this->LaunchBoxGroup->Name = L"LaunchBoxGroup";
	this->LaunchBoxGroup->Size = System::Drawing::Size(264, 270);
	this->LaunchBoxGroup->TabIndex = 11;
	this->LaunchBoxGroup->TabStop = false;
	// 
	// ApplyButton
	// 
	this->ApplyButton->Location = System::Drawing::Point(144, 14);
	this->ApplyButton->Name = L"ApplyButton";
	this->ApplyButton->Size = System::Drawing::Size(75, 23);
	this->ApplyButton->TabIndex = 11;
	this->ApplyButton->Text = L"Apply";
	this->ApplyButton->UseVisualStyleBackColor = true;
	this->ApplyButton->Click += gcnew System::EventHandler(this, &Form1::ApplyButton_Click);
	// 
	// OtherOptionsGroup
	// 
	this->OtherOptionsGroup->Controls->Add(this->MapListDrop);
	this->OtherOptionsGroup->Controls->Add(this->MaxPlayersDrop);
	this->OtherOptionsGroup->Controls->Add(this->ReadyUpCheck);
	this->OtherOptionsGroup->Controls->Add(this->MaxPlayersLabel);
	this->OtherOptionsGroup->Controls->Add(this->SelectMapLabel);
	this->OtherOptionsGroup->Location = System::Drawing::Point(725, 146);
	this->OtherOptionsGroup->Name = L"OtherOptionsGroup";
	this->OtherOptionsGroup->Size = System::Drawing::Size(264, 150);
	this->OtherOptionsGroup->TabIndex = 12;
	this->OtherOptionsGroup->TabStop = false;
	this->OtherOptionsGroup->Text = L"Other Options";
	// 
	// MapListDrop
	// 
	this->MapListDrop->Location = System::Drawing::Point(10, 119);
	this->MapListDrop->Name = L"MapListDrop";
	this->MapListDrop->Size = System::Drawing::Size(218, 21);
	this->MapListDrop->TabIndex = 21;
	// 
	// MaxPlayersDrop
	// 
	this->MaxPlayersDrop->FormattingEnabled = true;
	this->MaxPlayersDrop->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
		L"1", L"2", L"3", L"4", L"5", L"6", L"7",
			L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16"
	});
	this->MaxPlayersDrop->Location = System::Drawing::Point(10, 73);
	this->MaxPlayersDrop->Name = L"MaxPlayersDrop";
	this->MaxPlayersDrop->Size = System::Drawing::Size(218, 21);
	this->MaxPlayersDrop->TabIndex = 22;
	// 
	// ReadyUpCheck
	// 
	this->ReadyUpCheck->AutoSize = true;
	this->ReadyUpCheck->Location = System::Drawing::Point(13, 26);
	this->ReadyUpCheck->Name = L"ReadyUpCheck";
	this->ReadyUpCheck->Size = System::Drawing::Size(120, 17);
	this->ReadyUpCheck->TabIndex = 23;
	this->ReadyUpCheck->Text = L"Ready Up Required";
	this->ReadyUpCheck->UseVisualStyleBackColor = true;
	// 
	// SelectMapLabel
	// 
	this->SelectMapLabel->AutoSize = true;
	this->SelectMapLabel->BackColor = System::Drawing::Color::Transparent;
	this->SelectMapLabel->Location = System::Drawing::Point(11, 103);
	this->SelectMapLabel->Name = L"SelectMapLabel";
	this->SelectMapLabel->Size = System::Drawing::Size(61, 13);
	this->SelectMapLabel->TabIndex = 14;
	this->SelectMapLabel->Text = L"Select Map";
	// 
	// OtherModsGroup
	// 
	this->OtherModsGroup->Controls->Add(this->GadgetsCheckbox);
	this->OtherModsGroup->Controls->Add(this->AmmoCheckbox);
	this->OtherModsGroup->Controls->Add(this->GraphicsBox);
	this->OtherModsGroup->Controls->Add(this->SoundPatchBox);
	this->OtherModsGroup->Controls->Add(this->InternetBox);
	this->OtherModsGroup->Location = System::Drawing::Point(63, 400);
	this->OtherModsGroup->Name = L"OtherModsGroup";
	this->OtherModsGroup->Size = System::Drawing::Size(264, 155);
	this->OtherModsGroup->TabIndex = 13;
	this->OtherModsGroup->TabStop = false;
	this->OtherModsGroup->Text = L"Other Mods";
	// 
	// GadgetsCheckbox
	// 
	this->GadgetsCheckbox->AutoSize = true;
	this->GadgetsCheckbox->Checked = true;
	this->GadgetsCheckbox->CheckState = System::Windows::Forms::CheckState::Checked;
	this->GadgetsCheckbox->Location = System::Drawing::Point(9, 115);
	this->GadgetsCheckbox->Name = L"GadgetsCheckbox";
	this->GadgetsCheckbox->Size = System::Drawing::Size(93, 17);
	this->GadgetsCheckbox->TabIndex = 4;
	this->GadgetsCheckbox->Text = L"Extra Gadgets";
	this->GadgetsCheckbox->UseVisualStyleBackColor = true;
	// 
	// AmmoCheckbox
	// 
	this->AmmoCheckbox->AutoSize = true;
	this->AmmoCheckbox->Checked = true;
	this->AmmoCheckbox->CheckState = System::Windows::Forms::CheckState::Checked;
	this->AmmoCheckbox->Location = System::Drawing::Point(9, 90);
	this->AmmoCheckbox->Name = L"AmmoCheckbox";
	this->AmmoCheckbox->Size = System::Drawing::Size(82, 17);
	this->AmmoCheckbox->TabIndex = 3;
	this->AmmoCheckbox->Text = L"Extra Ammo";
	this->AmmoCheckbox->UseVisualStyleBackColor = true;
	// 
	// GraphicsBox
	// 
	this->GraphicsBox->AutoSize = true;
	this->GraphicsBox->Checked = true;
	this->GraphicsBox->CheckState = System::Windows::Forms::CheckState::Checked;
	this->GraphicsBox->Location = System::Drawing::Point(9, 67);
	this->GraphicsBox->Name = L"GraphicsBox";
	this->GraphicsBox->Size = System::Drawing::Size(115, 17);
	this->GraphicsBox->TabIndex = 2;
	this->GraphicsBox->Text = L"Improved Graphics";
	this->GraphicsBox->UseVisualStyleBackColor = true;
	// 
	// SoundPatchBox
	// 
	this->SoundPatchBox->AutoSize = true;
	this->SoundPatchBox->Checked = true;
	this->SoundPatchBox->CheckState = System::Windows::Forms::CheckState::Checked;
	this->SoundPatchBox->Location = System::Drawing::Point(9, 43);
	this->SoundPatchBox->Name = L"SoundPatchBox";
	this->SoundPatchBox->Size = System::Drawing::Size(92, 17);
	this->SoundPatchBox->TabIndex = 1;
	this->SoundPatchBox->Text = L"Sound Patch*";
	this->SoundPatchBox->UseVisualStyleBackColor = true;
	// 
	// InternetBox
	// 
	this->InternetBox->AutoSize = true;
	this->InternetBox->Checked = true;
	this->InternetBox->CheckState = System::Windows::Forms::CheckState::Checked;
	this->InternetBox->Location = System::Drawing::Point(9, 20);
	this->InternetBox->Name = L"InternetBox";
	this->InternetBox->Size = System::Drawing::Size(85, 17);
	this->InternetBox->TabIndex = 0;
	this->InternetBox->Text = L"Fast Internet";
	this->InternetBox->UseVisualStyleBackColor = true;
	// 
	// TerrorHuntGroup
	// 
	this->TerrorHuntGroup->Controls->Add(this->TerrorCountDrop);
	this->TerrorHuntGroup->Controls->Add(this->DifficultyDrop);
	this->TerrorHuntGroup->Controls->Add(this->DifficultyLabel);
	this->TerrorHuntGroup->Controls->Add(this->SpawnRateDrop);
	this->TerrorHuntGroup->Controls->Add(this->SpawnRateLabel);
	this->TerrorHuntGroup->Controls->Add(this->TerrorCountLabel);
	this->TerrorHuntGroup->Location = System::Drawing::Point(725, 350);
	this->TerrorHuntGroup->Name = L"TerrorHuntGroup";
	this->TerrorHuntGroup->Size = System::Drawing::Size(264, 205);
	this->TerrorHuntGroup->TabIndex = 17;
	this->TerrorHuntGroup->TabStop = false;
	this->TerrorHuntGroup->Text = L"Terrorist Hunt";
	// 
	// TerrorCountDrop
	// 
	this->TerrorCountDrop->FormattingEnabled = true;
	this->TerrorCountDrop->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Default", L"50", L"99", L"999", L"2" });
	this->TerrorCountDrop->Location = System::Drawing::Point(6, 102);
	this->TerrorCountDrop->Name = L"TerrorCountDrop";
	this->TerrorCountDrop->Size = System::Drawing::Size(218, 21);
	this->TerrorCountDrop->TabIndex = 20;
	// 
	// SpawnRateDrop
	// 
	this->SpawnRateDrop->FormattingEnabled = true;
	this->SpawnRateDrop->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"Default", L"16", L"32", L"64", L"99" });
	this->SpawnRateDrop->Location = System::Drawing::Point(6, 50);
	this->SpawnRateDrop->Name = L"SpawnRateDrop";
	this->SpawnRateDrop->Size = System::Drawing::Size(218, 21);
	this->SpawnRateDrop->TabIndex = 18;
	// 
	// SpawnRateLabel
	// 
	this->SpawnRateLabel->AutoSize = true;
	this->SpawnRateLabel->BackColor = System::Drawing::Color::Transparent;
	this->SpawnRateLabel->Location = System::Drawing::Point(6, 34);
	this->SpawnRateLabel->Name = L"SpawnRateLabel";
	this->SpawnRateLabel->Size = System::Drawing::Size(66, 13);
	this->SpawnRateLabel->TabIndex = 2;
	this->SpawnRateLabel->Text = L"Spawn Rate";
	// 
	// Form1
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
	this->ClientSize = System::Drawing::Size(1023, 577);
	this->Controls->Add(this->TerrorHuntGroup);
	this->Controls->Add(this->OtherModsGroup);
	this->Controls->Add(this->OtherOptionsGroup);
	this->Controls->Add(this->LaunchBoxGroup);
	this->Controls->Add(this->HostOptions);
	this->Controls->Add(this->TitlePictureBox);
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	this->MaximizeBox = false;
	this->Name = L"Form1";
	this->Text = L"Reaver\'s RSV2 Toolkit (nice-rice v0.5)";
	this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TitlePictureBox))->EndInit();
	this->HostOptions->ResumeLayout(false);
	this->HostOptions->PerformLayout();
	this->LaunchBoxGroup->ResumeLayout(false);
	this->LaunchBoxGroup->PerformLayout();
	this->OtherOptionsGroup->ResumeLayout(false);
	this->OtherOptionsGroup->PerformLayout();
	this->OtherModsGroup->ResumeLayout(false);
	this->OtherModsGroup->PerformLayout();
	this->TerrorHuntGroup->ResumeLayout(false);
	this->TerrorHuntGroup->PerformLayout();
	this->ResumeLayout(false);

}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e){
				Control::CheckForIllegalCrossThreadCalls = false;
				 if(File::Exists("../Binaries/RainbowSixVegas2_SADS.exe") == false)
				 {
					 MessageBox::Show("Unable to find RainbowSixVegas2 game files", "Error");
					 Application::Exit();
					 return;
				 }
				//Populate map list by grabbing from Modmanager -> IniConfig class
				array< System::Object^  >^ mapList = gcnew array< System::Object^  >(17);
				for (int i = 0; i < 17; ++i) {
					mapList[i] = gcnew String(m_pManager->GetMapName(i).c_str());
				}
				MapListDrop->Items->AddRange(mapList);
				
				//Set Default Values on startup
				 MaxPlayersDrop->SelectedIndex = 15;
				 TerrorCountDrop->SelectedIndex = 2;
				 MapListDrop->SelectedIndex = 0;
				 SpawnRateDrop->SelectedIndex = 2;
				 DifficultyDrop->SelectedIndex = 2;
				 TimeLimitDrop->SelectedIndex = 4;
				 RespawnDrop->SelectedIndex = 4;
				 GameModeBox->SelectedIndex = 0;

	}
	private: void WriteLog(String^ Writto){
	   LogTextBox->Text = LogTextBox->Text + Writto + "\n";
	   LogTextBox->SelectionStart = LogTextBox->Text->Length;
	   LogTextBox->ScrollToCaret();
	}
	private: System::Void EyeMonitorBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void IsHostBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e){

		m_pManager->SetServer(IsHostBox->Checked, ServerNameBox->Text,PasswordBox->Text);
		
		ServerNameBox->Enabled = !ServerNameBox->Enabled;
		PasswordBox->Enabled = !PasswordBox->Enabled;
		GameModeBox->Enabled = !GameModeBox->Enabled;
		TimeLimitDrop->Enabled = !TimeLimitDrop->Enabled;
		ReadyUpCheck->Enabled = !ReadyUpCheck->Enabled;
		MapListDrop->Enabled = !MapListDrop->Enabled;
		DifficultyDrop->Enabled = !DifficultyDrop->Enabled;

		
	}
	private: System::Void LaunchButton_Click(System::Object^  sender, System::EventArgs^  e){
		
		SendData();
		WriteLog("Launching Game with the following settings:");
		WriteLog("Server Name: "+(ServerNameBox->Text));
		WriteLog("Server Password: "+PasswordBox->Text);
		WriteLog("Difficulty: "+DifficultyDrop->Text);
		WriteLog("Time Limit (min): "+TimeLimitDrop->Text);
		WriteLog("Terror Spawn Rate: "+SpawnRateDrop->Text);
		WriteLog("Terror Count: "+TerrorCountDrop->Text);
		WriteLog("Max Player Count: "+MaxPlayersDrop->Text);
		WriteLog("Map Selection: "+MapListDrop->Text); 
		time_t timetoday;
		time(&timetoday);

		System::String^ launch_time_t = gcnew String(asctime(localtime(&timetoday)));
		WriteLog("Time Started: "+ launch_time_t);
		
		//Enable or disable mods that write to ini files
		m_pManager->SetOtherMods(InternetBox->Checked, SoundPatchBox->Checked, GraphicsBox->Checked, AmmoCheckbox->Checked, GadgetsCheckbox->Checked);
		
		//Begin launching the game
		m_pManager->StartProcess(true);
		
	}

	private: System::Void ApplyButton_Click(System::Object^ sender, System::EventArgs^ e) {
		SendData();
		WriteLog("Settings Applied");

	}
	void SendData() {
		if (ServerNameBox->Text == "") {
			ServerNameBox->Text = "T-Hunt-Server";
		}
		m_pManager->SetGameMode(GameModeBox->Text);
		m_pManager->SetServer(IsHostBox->Checked, ServerNameBox->Text, PasswordBox->Text);
		m_pManager->SetMap(MapListDrop->SelectedIndex);
		m_pManager->SetRespawn(RespawnDrop->Text);
		m_pManager->SetDifficulty(DifficultyDrop->Text);
		m_pManager->SetTimeLimit(Convert::ToInt32(TimeLimitDrop->SelectedItem));
		m_pManager->SetMaxPlayers(Convert::ToInt32(MaxPlayersDrop->SelectedItem));
		m_pManager->SetReadyUp(ReadyUpCheck->Checked);
		m_pManager->SetSpawnRate(SpawnRateDrop->SelectedItem);
		m_pManager->SetTerrorCount(TerrorCountDrop->SelectedItem);
		
	}

};
}

