#ifndef PROZOR_H
#define PROZOR_H
#include <wx/graphics.h>
#include <wx/dcclient.h>
#include <wx/dcgraph.h>
#include <wx/dcbuffer.h>
#include <wx/stdpaths.h>
#include "Interfaces.h"
#include "wx/wx.h"
#include "wxProzor.h"

wxDECLARE_EVENT(wxObradiObjekt, wxCommandEvent);

class Prozor : public wxProzor
{
    public:
        Prozor(IOsnova *osnova);
        virtual ~Prozor();
        virtual void onExit(wxCommandEvent& event);
    protected:
        IOsnova *osnova;
        wxBitmap *bitmap;
        wxMemoryDC *memDC;
        void obradiObjekt(wxCommandEvent& event);
        virtual void Nacrtaj( wxPaintEvent& event );
        virtual void PrikaziSpiro( wxCommandEvent& event );
        virtual void PrikaziSuper( wxCommandEvent& event );
        virtual void PrikaziSuper2( Parametri p1);
        virtual void CrtajUMemDC(Parametri p, SplineParametri sp);
        virtual void PodesiParametre( wxCommandEvent& event );
        virtual void SnimiSliku( wxCommandEvent& event );
    private:
        SplineParametri sp;
        Parametri p;
};

#endif // PROZOR_H
