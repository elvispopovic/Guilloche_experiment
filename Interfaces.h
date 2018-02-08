#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED
#include <wx/dcsvg.h>
#include <windows.h>
//#include <gdiplus.h>

enum VrstaIzracuna:unsigned char{DEFAULT=0, SPIRO=1, SUPER=2};

struct Parametri
{
    VrstaIzracuna vrsta;
    int w, h;
    double R, r, p;
    double a, b, m1, m2, n1, n2, n3;
    double minx, miny, maxx, maxy;
    double cx, cy, skala;
    bool sekundarna, rotiranje;
};

struct SplineParametri
{
    double tenzija;
    int detalj;
};

struct SplineTocke
{
    double x;
    double y;
    double mx;
    double my;
};

class IOsnova
{
public:
    virtual int IzracunavanjeSpiro(Parametri &p, SplineParametri &sp)=0;
    virtual int IzracunavanjeSuper(Parametri &p, SplineParametri &sp, double rotacija=0.0)=0;
    virtual void CrtanjaPanela(wxGraphicsContext *gc)=0;
    //virtual void CrtanjaPanela(Gdiplus::Graphics* gdiPlus, Parametri p, SplineParametri sp)=0;
    virtual void CrtanjaPanela(wxGraphicsContext *gc, Parametri p, SplineParametri sp, wxSVGFileDC *svgDC) = 0;
};


#endif // INTERFACES_H_INCLUDED
