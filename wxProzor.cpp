///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxProzor.h"

///////////////////////////////////////////////////////////////////////////

wxProzor::wxProzor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("tenzija"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL, 5 );
	
	m_textCtrl_tenzija = new wxTextCtrl( this, wxID_ANY, wxT("1.8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_tenzija->SetForegroundColour( wxColour( 255, 128, 64 ) );
	m_textCtrl_tenzija->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer7->Add( m_textCtrl_tenzija, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer7->Add( m_staticline2, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("primjeri:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer7->Add( m_staticText20, 0, wxALL, 5 );
	
	m_buttonPrimjer1 = new wxButton( this, wxID_Primjer1, wxT("1"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer1, 0, wxALL, 5 );
	
	m_buttonPrimjer2 = new wxButton( this, wxID_Primjer2, wxT("2"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer2, 0, wxALL, 5 );
	
	m_buttonPrimjer3 = new wxButton( this, wxID_Primjer3, wxT("3"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer3, 0, wxALL, 5 );
	
	m_buttonPrimjer4 = new wxButton( this, wxID_Primjer4, wxT("4"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer4, 0, wxALL, 5 );
	
	m_buttonPrimjer5 = new wxButton( this, wxID_Primjer5, wxT("5"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer5, 0, wxALL, 5 );
	
	m_buttonPrimjer6 = new wxButton( this, wxID_Primjer6, wxT("6"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer6, 0, wxALL, 5 );
	
	m_buttonPrimjer7 = new wxButton( this, wxID_Primjer7, wxT("7"), wxDefaultPosition, wxSize( 20,20 ), 0 );
	bSizer7->Add( m_buttonPrimjer7, 0, wxALL, 5 );
	
	m_staticline21 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer7->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );
	
	m_buttonSnimi = new wxButton( this, wxID_ANY, wxT("Snimi"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_buttonSnimi, 0, wxALL, 5 );
	
	
	bSizer25->Add( bSizer7, 0, wxEXPAND, 5 );
	
	
	bSizer2->Add( bSizer25, 0, wxEXPAND, 5 );
	
	panelCrtanje = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	bSizer2->Add( panelCrtanje, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	bSizer3->SetMinSize( wxSize( 180,-1 ) ); 
	wxString m_radioBox_detaljChoices[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5") };
	int m_radioBox_detaljNChoices = sizeof( m_radioBox_detaljChoices ) / sizeof( wxString );
	m_radioBox_detalj = new wxRadioBox( this, wxID_ANY, wxT("Detaljnost"), wxDefaultPosition, wxDefaultSize, m_radioBox_detaljNChoices, m_radioBox_detaljChoices, 1, wxRA_SPECIFY_ROWS );
	m_radioBox_detalj->SetSelection( 1 );
	bSizer3->Add( m_radioBox_detalj, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, wxT("Spirograf") ), wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("R"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	m_staticText1->SetMinSize( wxSize( 10,-1 ) );
	
	bSizer4->Add( m_staticText1, 0, wxLEFT, 5 );
	
	m_textCtrl_R = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxT("49.8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_R->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textCtrl_R->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer4->Add( m_textCtrl_R, 0, wxLEFT|wxRIGHT, 5 );
	
	
	sbSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("r"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	m_staticText11->SetMinSize( wxSize( 10,-1 ) );
	
	bSizer5->Add( m_staticText11, 0, wxLEFT, 5 );
	
	m_textCtrl_r = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxT("-0.18126"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_r->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textCtrl_r->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer5->Add( m_textCtrl_r, 0, wxLEFT|wxRIGHT, 5 );
	
	
	sbSizer1->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText111 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("p"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	m_staticText111->SetMinSize( wxSize( 10,-1 ) );
	
	bSizer51->Add( m_staticText111, 0, wxLEFT, 5 );
	
	m_textCtrl_p = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxT("25.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_p->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textCtrl_p->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer51->Add( m_textCtrl_p, 0, wxLEFT|wxRIGHT, 5 );
	
	
	sbSizer1->Add( bSizer51, 1, wxEXPAND, 5 );
	
	m_buttonSpiro = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Prikaži"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_buttonSpiro, 0, wxLEFT, 20 );
	
	
	bSizer15->Add( sbSizer1, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, wxT("Superformula baza") ), wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("a"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer8->Add( m_staticText5, 0, wxLEFT, 3 );
	
	m_textSuper_a = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_a->SetForegroundColour( wxColour( 128, 255, 255 ) );
	m_textSuper_a->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer8->Add( m_textSuper_a, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer8, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("b"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer81->Add( m_staticText51, 0, wxLEFT, 3 );
	
	m_textSuper_b = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_b->SetForegroundColour( wxColour( 128, 255, 255 ) );
	m_textSuper_b->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer81->Add( m_textSuper_b, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer81, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer811;
	bSizer811 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText511 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("m1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511->Wrap( -1 );
	m_staticText511->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer811->Add( m_staticText511, 0, wxLEFT, 3 );
	
	m_textSuper_m1 = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("12.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_m1->SetForegroundColour( wxColour( 255, 128, 64 ) );
	m_textSuper_m1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer811->Add( m_textSuper_m1, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer811, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8111;
	bSizer8111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5111 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("m2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5111->Wrap( -1 );
	m_staticText5111->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer8111->Add( m_staticText5111, 0, wxLEFT, 3 );
	
	m_textSuper_m2 = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("12.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_m2->SetForegroundColour( wxColour( 255, 128, 64 ) );
	m_textSuper_m2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer8111->Add( m_textSuper_m2, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer8111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer81111;
	bSizer81111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51111 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("n1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51111->Wrap( -1 );
	m_staticText51111->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer81111->Add( m_staticText51111, 0, wxLEFT, 3 );
	
	m_textSuper_n1 = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("16.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_n1->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textSuper_n1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer81111->Add( m_textSuper_n1, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer81111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer811111;
	bSizer811111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText511111 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("n2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511111->Wrap( -1 );
	m_staticText511111->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer811111->Add( m_staticText511111, 0, wxLEFT, 3 );
	
	m_textSuper_n2 = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("20.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_n2->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textSuper_n2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer811111->Add( m_textSuper_n2, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer811111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8111111;
	bSizer8111111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5111111 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, wxT("n3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5111111->Wrap( -1 );
	m_staticText5111111->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer8111111->Add( m_staticText5111111, 0, wxLEFT, 3 );
	
	m_textSuper_n3 = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxT("14.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper_n3->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textSuper_n3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer8111111->Add( m_textSuper_n3, 0, wxLEFT, 5 );
	
	
	sbSizer2->Add( bSizer8111111, 1, wxEXPAND, 5 );
	
	m_buttonSuper = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, wxT("Prikaži"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_buttonSuper, 0, wxLEFT, 25 );
	
	
	bSizer15->Add( sbSizer2, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, wxT("Superformula sekundarna") ), wxVERTICAL );
	
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText52 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("a"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer82->Add( m_staticText52, 0, wxLEFT, 3 );
	
	m_textSuper2_a = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_a->SetForegroundColour( wxColour( 128, 255, 255 ) );
	m_textSuper2_a->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer82->Add( m_textSuper2_a, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer82, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer812;
	bSizer812 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText512 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("b"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText512->Wrap( -1 );
	m_staticText512->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer812->Add( m_staticText512, 0, wxLEFT, 3 );
	
	m_textSuper2_b = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_b->SetForegroundColour( wxColour( 128, 255, 255 ) );
	m_textSuper2_b->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer812->Add( m_textSuper2_b, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer812, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8112;
	bSizer8112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5112 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("m1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5112->Wrap( -1 );
	m_staticText5112->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer8112->Add( m_staticText5112, 0, wxLEFT, 3 );
	
	m_textSuper2_m1 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("6.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_m1->SetForegroundColour( wxColour( 255, 128, 64 ) );
	m_textSuper2_m1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer8112->Add( m_textSuper2_m1, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer8112, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer81112;
	bSizer81112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51112 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("m2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51112->Wrap( -1 );
	m_staticText51112->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer81112->Add( m_staticText51112, 0, wxLEFT, 3 );
	
	m_textSuper2_m2 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("6.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_m2->SetForegroundColour( wxColour( 255, 128, 64 ) );
	m_textSuper2_m2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer81112->Add( m_textSuper2_m2, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer81112, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer811112;
	bSizer811112 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText511112 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("n1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511112->Wrap( -1 );
	m_staticText511112->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer811112->Add( m_staticText511112, 0, wxLEFT, 3 );
	
	m_textSuper2_n1 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("13.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_n1->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textSuper2_n1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer811112->Add( m_textSuper2_n1, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer811112, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8111121;
	bSizer8111121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5111121 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("n2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5111121->Wrap( -1 );
	m_staticText5111121->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer8111121->Add( m_staticText5111121, 0, wxLEFT, 3 );
	
	m_textSuper2_n2 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("16.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_n2->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textSuper2_n2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer8111121->Add( m_textSuper2_n2, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer8111121, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer81111111;
	bSizer81111111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51111111 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("n3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51111111->Wrap( -1 );
	m_staticText51111111->SetMinSize( wxSize( 18,-1 ) );
	
	bSizer81111111->Add( m_staticText51111111, 0, wxLEFT, 3 );
	
	m_textSuper2_n3 = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("14.0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textSuper2_n3->SetForegroundColour( wxColour( 0, 255, 0 ) );
	m_textSuper2_n3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer81111111->Add( m_textSuper2_n3, 0, wxLEFT, 5 );
	
	
	sbSizer4->Add( bSizer81111111, 0, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( sbSizer4->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	sbSizer4->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer811111111;
	bSizer811111111 = new wxBoxSizer( wxVERTICAL );
	
	m_checkBox_rot = new wxCheckBox( sbSizer4->GetStaticBox(), wxID_ANY, wxT("rotiranje"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
	bSizer811111111->Add( m_checkBox_rot, 0, wxLEFT, 25 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( sbSizer4->GetStaticBox(), wxID_ANY, wxT("Skala"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	m_staticText21->SetMinSize( wxSize( 35,-1 ) );
	
	bSizer26->Add( m_staticText21, 0, wxLEFT, 5 );
	
	m_textCtrl_skala = new wxTextCtrl( sbSizer4->GetStaticBox(), wxID_ANY, wxT("0.66"), wxDefaultPosition, wxDefaultSize, 0 );
	m_textCtrl_skala->SetForegroundColour( wxColour( 0, 128, 128 ) );
	m_textCtrl_skala->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_textCtrl_skala->SetMinSize( wxSize( 95,-1 ) );
	
	bSizer26->Add( m_textCtrl_skala, 0, 0, 25 );
	
	
	bSizer811111111->Add( bSizer26, 1, wxEXPAND|wxTOP, 5 );
	
	
	sbSizer4->Add( bSizer811111111, 1, wxBOTTOM|wxEXPAND, 5 );
	
	m_buttonSuper2 = new wxButton( sbSizer4->GetStaticBox(), wxID_ANY, wxT("Prikaži"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( m_buttonSuper2, 0, wxLEFT, 25 );
	
	
	bSizer15->Add( sbSizer4, 0, wxEXPAND, 5 );
	
	
	m_scrolledWindow1->SetSizer( bSizer15 );
	m_scrolledWindow1->Layout();
	bSizer15->Fit( m_scrolledWindow1 );
	bSizer3->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_buttonPrimjer1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonSnimi->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::SnimiSliku ), NULL, this );
	panelCrtanje->Connect( wxEVT_PAINT, wxPaintEventHandler( wxProzor::Nacrtaj ), NULL, this );
	m_buttonSpiro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PrikaziSpiro ), NULL, this );
	m_buttonSuper->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PrikaziSuper ), NULL, this );
	m_buttonSuper2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PrikaziSuper ), NULL, this );
}

wxProzor::~wxProzor()
{
	// Disconnect Events
	m_buttonPrimjer1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonPrimjer7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PodesiParametre ), NULL, this );
	m_buttonSnimi->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::SnimiSliku ), NULL, this );
	panelCrtanje->Disconnect( wxEVT_PAINT, wxPaintEventHandler( wxProzor::Nacrtaj ), NULL, this );
	m_buttonSpiro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PrikaziSpiro ), NULL, this );
	m_buttonSuper->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PrikaziSuper ), NULL, this );
	m_buttonSuper2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxProzor::PrikaziSuper ), NULL, this );
	
}
