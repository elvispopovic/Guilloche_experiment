///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXPROZOR_H__
#define __WXPROZOR_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/scrolwin.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_Primjer1 1000
#define wxID_Primjer2 1001
#define wxID_Primjer3 1002
#define wxID_Primjer4 1003
#define wxID_Primjer5 1004
#define wxID_Primjer6 1005
#define wxID_Primjer7 1006

///////////////////////////////////////////////////////////////////////////////
/// Class wxProzor
///////////////////////////////////////////////////////////////////////////////
class wxProzor : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl_tenzija;
		wxStaticLine* m_staticline2;
		wxStaticText* m_staticText20;
		wxButton* m_buttonPrimjer1;
		wxButton* m_buttonPrimjer2;
		wxButton* m_buttonPrimjer3;
		wxButton* m_buttonPrimjer4;
		wxButton* m_buttonPrimjer5;
		wxButton* m_buttonPrimjer6;
		wxButton* m_buttonPrimjer7;
		wxStaticLine* m_staticline21;
		wxButton* m_buttonSnimi;
		wxPanel* panelCrtanje;
		wxRadioBox* m_radioBox_detalj;
		wxScrolledWindow* m_scrolledWindow1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl_R;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrl_r;
		wxStaticText* m_staticText111;
		wxTextCtrl* m_textCtrl_p;
		wxButton* m_buttonSpiro;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textSuper_a;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_textSuper_b;
		wxStaticText* m_staticText511;
		wxTextCtrl* m_textSuper_m1;
		wxStaticText* m_staticText5111;
		wxTextCtrl* m_textSuper_m2;
		wxStaticText* m_staticText51111;
		wxTextCtrl* m_textSuper_n1;
		wxStaticText* m_staticText511111;
		wxTextCtrl* m_textSuper_n2;
		wxStaticText* m_staticText5111111;
		wxTextCtrl* m_textSuper_n3;
		wxButton* m_buttonSuper;
		wxStaticText* m_staticText52;
		wxTextCtrl* m_textSuper2_a;
		wxStaticText* m_staticText512;
		wxTextCtrl* m_textSuper2_b;
		wxStaticText* m_staticText5112;
		wxTextCtrl* m_textSuper2_m1;
		wxStaticText* m_staticText51112;
		wxTextCtrl* m_textSuper2_m2;
		wxStaticText* m_staticText511112;
		wxTextCtrl* m_textSuper2_n1;
		wxStaticText* m_staticText5111121;
		wxTextCtrl* m_textSuper2_n2;
		wxStaticText* m_staticText51111111;
		wxTextCtrl* m_textSuper2_n3;
		wxStaticLine* m_staticline1;
		wxCheckBox* m_checkBox_rot;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCtrl_skala;
		wxButton* m_buttonSuper2;
		
		// Virtual event handlers, overide them in your derived class
		virtual void PodesiParametre( wxCommandEvent& event ) { event.Skip(); }
		virtual void SnimiSliku( wxCommandEvent& event ) { event.Skip(); }
		virtual void Nacrtaj( wxPaintEvent& event ) { event.Skip(); }
		virtual void PrikaziSpiro( wxCommandEvent& event ) { event.Skip(); }
		virtual void PrikaziSuper( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		wxProzor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Guiloché-ove krivulje"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~wxProzor();
	
};

#endif //__WXPROZOR_H__
