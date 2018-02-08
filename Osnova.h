#ifndef VJEZBA_H_INCLUDED
#define VJEZBA_H_INCLUDED


#ifndef WX_PRECOMP
    #include <wx/wxprec.h>
    #include <wx/wx.h>
#endif
#include <iostream>
#include "Prozor.h"

class Osnova : public wxApp, IOsnova
{
public:
    virtual bool OnInit();
    virtual int OnExit();
    virtual void ObradiObjekt();
protected:
    wxRealPoint *poljeRjesenja1, *poljeRjesenja2;
    virtual void AzurirajRaspon(Parametri &p, double x, double y, bool reset);
    virtual int IzracunavanjeSpiro(Parametri &p, SplineParametri &sp);
    virtual int IzracunavanjeSuper(Parametri &p, SplineParametri &sp, double rotacija=0.0);
    virtual void CrtanjaPanela(wxGraphicsContext *gc);
    //virtual void CrtanjaPanela(Gdiplus::Graphics* gdiPlus, Parametri p, SplineParametri sp);
    virtual void CrtanjaPanela(wxGraphicsContext *gc, Parametri p, SplineParametri sp, wxSVGFileDC *svgDC);
private:
    Prozor *prozor;
    wxEvtHandler *wxGlavnaFormaDest;
    //void CrtajStazu(Gdiplus::Graphics* gdiPlus, Gdiplus::PointF points[], int numPoints, Gdiplus::Color colors[], Gdiplus::Point gradientPoints[], Gdiplus::REAL tenzija);
    void CrtajStazu(wxGraphicsContext *gc, wxRealPoint points[], int numPoints, int podjela, wxColor colors[], double tenzija, wxSVGFileDC *svgDC);
    void KardinalniSpline(wxRealPoint points[], int numPoints, wxRealPoint interpolirano[], int podjela, double tenzija,  wxRealPoint normale[]);
    int InterpolirajBoje(wxColor boje[], int brojBoja, wxColor interpolirano[], int podjela, double tenzija=0.0);
    void HermiteTest(wxGraphicsContext *gc, double tenzija);
};


#endif // VJEZBA_H_INCLUDED
