#include "Osnova.h"

using namespace std;
//using namespace Gdiplus;

wxDEFINE_EVENT(wxObradiObjekt, wxCommandEvent);

wxIMPLEMENT_APP(Osnova);

bool Osnova::OnInit()
{
    poljeRjesenja1 = new wxRealPoint[5*360];
    poljeRjesenja2 = new wxRealPoint[5*360];
    prozor = new Prozor(this);
    wxGlavnaFormaDest = (wxEvtHandler*)prozor;
    prozor->Show( true );
	return true;
}

int Osnova::OnExit()
{
    delete[] poljeRjesenja1;
    delete[] poljeRjesenja2;
    return 0;
}

void Osnova::ObradiObjekt()
{
    wxCommandEvent event(wxObradiObjekt);
    event.SetEventObject( (wxObject *)this );
    //event.SetClientData(objekt);

    //wxQueueEvent( wxGlavnaFormaDest, &event );
    wxPostEvent( wxGlavnaFormaDest,event );
}

void Osnova::AzurirajRaspon(Parametri &p, double x, double y, bool reset)
{
    if(reset)
    {
        p.minx=p.miny=10000;
        p.maxx=p.maxy=-10000;
        return;
    }
    if(x<p.minx) p.minx=x;
    if(y<p.miny) p.miny=y;
    if(x>p.maxx) p.maxx=x;
    if(y>p.maxy) p.maxy=y;
}

int Osnova::IzracunavanjeSpiro(Parametri &p, SplineParametri &sp)
{
    int i;
    double Rplusr, rplusp, Rpror, theta, dtheta;
    if(abs(p.r)<0.00001) return 0;
    dtheta=2.0*M_PI/(sp.detalj*360.0);
    cout << "Detalj: " << sp.detalj << endl;
    Rplusr=p.R+p.r;
    rplusp=p.r+p.p;
    Rpror=Rplusr/p.r;
    AzurirajRaspon(p, 0,0, true);
    for(theta=M_PI/2.0, i=0; i<sp.detalj*360; i++, theta+=dtheta)
    {
        (poljeRjesenja1+i)->x=p.cx+(Rplusr*cos(theta)+rplusp*cos(Rpror*theta));
        (poljeRjesenja1+i)->y=p.cy+(Rplusr*sin(theta)-rplusp*sin(Rpror*theta));
        AzurirajRaspon(p, (poljeRjesenja1+i)->x, (poljeRjesenja1+i)->y, false);
    }

    return i;
}

int Osnova::IzracunavanjeSuper(Parametri &p, SplineParametri &sp, double rotacija)
{
    int i, j;
    double x,y,fi, dfi, a1, a2, invn1, r;
    double sinrot, cosrot;
    sinrot=sin(rotacija);
    cosrot=cos(rotacija);

    invn1=-1.0/p.n1;
    if(p.sekundarna==false)
    {
        dfi=2.0*M_PI/(0.5*sp.detalj)/360.0;
        AzurirajRaspon(p, 0,0, true);
        for(fi=M_PI/2.0, i=0; i<sp.detalj*360/2; i++, fi+=dfi)
        {
            a1=abs(cos(p.m1*fi/4.0)/p.a);
            a2=abs(sin(p.m2*fi/4.0)/p.b);
            r=pow(pow(a1,p.n2)+pow(a2,p.n3),invn1);
            (poljeRjesenja1+i)->x=p.cx+r*cos(fi);
            (poljeRjesenja1+i)->y=p.cy+r*sin(fi);

            AzurirajRaspon(p, (poljeRjesenja1+i)->x, (poljeRjesenja1+i)->y, false);
        }
        for(fi=5*M_PI/2.0, i=0; i<sp.detalj*360/2; i++, fi+=dfi)
        {
            a1=abs(cos(p.m1*fi/4.0)/p.a);
            a2=abs(sin(p.m2*fi/4.0)/p.b);
            r=pow(pow(a1,p.n2)+pow(a2,p.n3),invn1);
            (poljeRjesenja1+i)->x=((poljeRjesenja1+i)->x+p.cx+r*cos(fi))/2.0;
            (poljeRjesenja1+i)->y=((poljeRjesenja1+i)->y+p.cy+r*sin(fi))/2.0;
        }
        return i;
    }
    else
    {
        dfi=2.0*M_PI/(0.25*sp.detalj)/360.0;
        for(fi=M_PI/2.0, i=0; i<sp.detalj*360/4; i++, fi+=dfi)
        {
            a1=abs(cos(p.m1*fi/4.0)/p.a);
            a2=abs(sin(p.m2*fi/4.0)/p.b);
            r=pow(pow(a1,p.n2)+pow(a2,p.n3),invn1);
            x=r*cos(fi);
            y=r*sin(fi);

            if(p.rotiranje)
            {
                (poljeRjesenja2+i)->x=x*cosrot-y*sinrot;
                (poljeRjesenja2+i)->y=y*cosrot+x*sinrot;
            }
            else
            {
                (poljeRjesenja2+i)->x=x;
                (poljeRjesenja2+i)->y=y;
            }
        }
        return i;
    }
}

//void Osnova::CrtanjaPanela(Gdiplus::Graphics* gdiPlus, Parametri p, SplineParametri sp)
void Osnova::CrtanjaPanela(wxGraphicsContext *gc, Parametri p, SplineParametri sp, wxSVGFileDC *svgDC)
{
    int i,j, podjela, N;
    double scale, kut, y;
    wxRealPoint centar(p.w/2,p.h/2);
    wxRealPoint kosina;
    wxColor colors[]={wxColor(51,208,180),wxColor(75,160,239),wxColor(245,131,193),wxColor(208,184,51),wxColor(51,208,180)};
    wxColor *intColors;

    p.cx=p.cy=0.0;
    podjela=12/sp.detalj;
    switch(p.vrsta)
    {
    case VrstaIzracuna::SPIRO:
        N = IzracunavanjeSpiro(p, sp);
        intColors = new wxColor[N];
        InterpolirajBoje(colors,5,intColors,N/5);

        scale=0.85*p.h/(p.maxy-p.miny);
        for(i=0; i<N; i++)
        {
            poljeRjesenja2[i].x=centar.x+scale*poljeRjesenja1[i].x;
            poljeRjesenja2[i].y=centar.y+scale*poljeRjesenja1[i].y;
        }
        //CrtajKrivulju(gdiPlus,points,5);
        CrtajStazu(gc,poljeRjesenja2,N,podjela,intColors,sp.tenzija,svgDC);

        break;
    case VrstaIzracuna::SUPER:
        if(p.sekundarna==false)
        {
            N = IzracunavanjeSuper(p,sp,0.0);
            intColors = new wxColor[N];
            InterpolirajBoje(colors,5,intColors,N/5);

            scale=p.h/(p.maxy-p.miny);
            for(i=0; i<N; i++)
            {
                poljeRjesenja2[i].x=centar.x+scale*poljeRjesenja1[i].x;
                poljeRjesenja2[i].y=centar.y+scale*poljeRjesenja1[i].y;
            }
            CrtajStazu(gc,poljeRjesenja2,N,podjela,intColors,sp.tenzija,svgDC);
        }
        else
        {
            AzurirajRaspon(p, 0,0, true);
            for(j=0; j<sp.detalj*360/2-1; j++)
            {
                kosina=poljeRjesenja1[j+1]-poljeRjesenja1[j];
                kut=atan2(kosina.x,kosina.y);
                N = IzracunavanjeSuper(p,sp,kut);
                intColors = new wxColor[N];
                InterpolirajBoje(colors,5,intColors,N/5);
                for(i=0; i<N; i++)
                {
                    y=((poljeRjesenja1[j].x+p.skala*poljeRjesenja2[i].y));
                    AzurirajRaspon(p, 0, y, false);
                }
            }
            scale=0.85*p.h/(p.maxy-p.miny);
            j=0;
            for(j=0; j<sp.detalj*360/2; j++)
            {
                if(j<sp.detalj*360/2-1)
                    kosina=poljeRjesenja1[j+1]-poljeRjesenja1[j];
                else
                    kosina=((poljeRjesenja1[j]-poljeRjesenja1[j-1])+(poljeRjesenja1[1]-poljeRjesenja1[0]));
                kut=atan2(kosina.y/2.0,kosina.x/2.0);

                N = IzracunavanjeSuper(p,sp,kut);
                if(p.skala==0) p.skala=1.0;
                for(i=0; i<N; i++)
                {
                    poljeRjesenja2[i].x=centar.x+scale*((poljeRjesenja1[j].x+p.skala*poljeRjesenja2[i].x));
                    poljeRjesenja2[i].y=centar.y+scale*((poljeRjesenja1[j].y+p.skala*poljeRjesenja2[i].y));
                }
                CrtajStazu(gc,poljeRjesenja2,N,podjela, intColors,sp.tenzija,svgDC);
            }
        }
        break;
    }
    delete[] intColors;

    //HermiteTest(gc,sp.tenzija);
}

/* samo za testiranje i usporedbu - GraphicsContext je zamijenjen nativnim Windows GDI+ sustavom */
void Osnova::CrtanjaPanela(wxGraphicsContext *gc)
{
        gc->SetPen( *wxRED_PEN );
        wxGraphicsPath path = gc->CreatePath();
        path.AddCircle( 50.0, 50.0, 50.0 );
        path.MoveToPoint(0.0, 50.0);
        path.AddLineToPoint(100.0, 50.0);
        path.MoveToPoint(50.0, 0.0);
        path.AddLineToPoint(50.0, 100.0 );
        path.CloseSubpath();
        path.AddRectangle(25.0, 25.0, 50.0, 50.0);
        gc->StrokePath(path);
}
/*
void Osnova::CrtajStazu(Graphics* gdiPlus, PointF points[], int numPoints, Color colors[], Point gradientPoints[], REAL tenzija)
{
    GraphicsPath path;
    path.AddCurve(points,numPoints);
    LinearGradientBrush brush(gradientPoints[0], gradientPoints[1],colors[0],colors[1]);
    brush.SetBlendTriangularShape(0.5);
    Pen pero(&brush,1);
    //gdiPlus->DrawPath(&pero, &path);
    gdiPlus->DrawClosedCurve(&pero, points,numPoints,tenzija);
    //gdiPlus->DrawCurve(&pero, points,numPoints,tenzija);
}
*/
void Osnova::CrtajStazu(wxGraphicsContext *gc, wxRealPoint points[], int numPoints, int podjela, wxColor colors[], double tenzija, wxSVGFileDC *svgDC)
{
    int i,j,st;
    wxCoord koordinate;
    wxRealPoint *interpolirano, *tangente;
    wxPoint *interpolirano2;
    wxPen pero(colors[0],1);
    interpolirano = new wxRealPoint[numPoints*podjela];
    interpolirano2= new wxPoint[podjela+1];

    tangente = new wxRealPoint[numPoints];

    KardinalniSpline(points,numPoints,interpolirano,podjela,tenzija, tangente);

    if(svgDC==NULL)
        for(j=0,st=0; j<numPoints; j++,st+=podjela)
        {
            gc->SetPen(wxPen(colors[j],1.0));
            if(j<numPoints-1)
                for(i=0; i<podjela; i++)
                    gc->StrokeLine(interpolirano[st+i].x,interpolirano[st+i].y,interpolirano[st+i+1].x,interpolirano[st+i+1].y);
            else
                for(i=0; i<podjela-1; i++)
                    gc->StrokeLine(interpolirano[st+i].x,interpolirano[st+i].y,interpolirano[st+i+1].x,interpolirano[st+i+1].y);
        }
    else
        for(j=0,st=0; j<numPoints; j++,st+=podjela)
        {
            svgDC->SetPen(wxPen(colors[j],1.0));
            if(j<numPoints-1)
                for(i=0; i<podjela; i++)
                    svgDC->DrawLine(100.0*interpolirano[st+i].x,100.0*interpolirano[st+i].y,100.0*interpolirano[st+i+1].x,100.0*interpolirano[st+i+1].y);
            else
                for(i=0; i<podjela-1; i++)
                    svgDC->DrawLine(100.0*interpolirano[st+i].x,100.0*interpolirano[st+i].y,100.0*interpolirano[st+i+1].x,100.0*interpolirano[st+i+1].y);
        }
    delete[] tangente;
    delete[] interpolirano2;
    delete[] interpolirano;
}

/* interpolacija boja */
int Osnova::InterpolirajBoje(wxColor boje[], int brojBoja, wxColor interpolirano[], int podjela, double tenzija)
{
    int i;
    wxRealPoint *tocke1, *tocke2, *interpolirano1, *interpolirano2, *normale;
    tocke1 = new wxRealPoint[brojBoja];
    tocke2 = new wxRealPoint[brojBoja];
    normale= new wxRealPoint[brojBoja];

    interpolirano1 = new wxRealPoint[brojBoja*podjela];
    interpolirano2 = new wxRealPoint[brojBoja*podjela];
    for(i=0; i<brojBoja; i++)
    {
        tocke1[i].x = boje[i].Red();
        tocke1[i].y = boje[i].Green();
        tocke2[i].x = boje[i].Blue();
        tocke2[i].y = boje[i].Alpha();
    }
    KardinalniSpline(tocke1,brojBoja,interpolirano1,podjela,tenzija,normale);
    KardinalniSpline(tocke2,brojBoja,interpolirano2,podjela,tenzija,normale);
    for(i=0; i<brojBoja*podjela; i++)
    {
        if(interpolirano1[i].x<0.0) interpolirano1[i].x=0.0;
        if(interpolirano1[i].x>255.0) interpolirano1[i].x=255.0;
        if(interpolirano1[i].y<0.0) interpolirano1[i].y=0.0;
        if(interpolirano1[i].y>255.0) interpolirano1[i].y=255.0;
        if(interpolirano2[i].x<0.0) interpolirano2[i].x=0.0;
        if(interpolirano2[i].x>255.0) interpolirano2[i].x=255.0;
        interpolirano[i].Set(interpolirano1[i].x,interpolirano1[i].y,interpolirano2[i].x);
    }

    delete[] interpolirano2;
    delete[] interpolirano1;
    delete[] tocke2;
    delete[] tocke1;
}

void Osnova::KardinalniSpline(wxRealPoint points[], int numPoints, wxRealPoint interpolirano[], int podjela, double tenzija,  wxRealPoint tangente[])
{
    int i, indeks;
    wxRealPoint p0,p1,p2,p3, delp, m1, m2;
    double h00[podjela], h10[podjela], h01[podjela], h11[podjela];
    double t,t2,t3,tf,invp;
    if(numPoints<2)
    {
        interpolirano[0].x=points[0].x;
        interpolirano[0].y=points[0].y;
        return;
    }
    //hermiteova baza
    for(i=1, invp=1.0/podjela; i<podjela; i++)
    {
        t=invp*i;
        t2=t*t;
        t3=t2*t;
        h00[i]=2.0*t3-3.0*t2+1.0;
        h10[i]=t3-2.0*t2+t;
        h01[i]=-2.0*t3+3.0*t2;
        h11[i]=t3-t2;
    }
    tf=0.5*(1.0-tenzija);
    for(int k=0; k<numPoints; k++)
    {
        p0=points[((k-1)%numPoints+numPoints)%numPoints];
        p1=points[k];
        p2=points[((k+1)%numPoints+numPoints)%numPoints];
        p3=points[((k+2)%numPoints+numPoints)%numPoints];

        //tangente
        m1=tf*(p2-p0);
        m2=tf*(p3-p1);
        tangente[k]=m1;

        indeks=k*podjela;
        interpolirano[indeks].x=p1.x;
        interpolirano[indeks].y=p1.y;
        for(i=1; i<podjela; i++)
        {
            indeks=k*podjela+i;
            interpolirano[indeks].x=h00[i]*p1.x+h10[i]*m1.x+h01[i]*p2.x+h11[i]*m2.x;
            interpolirano[indeks].y=h00[i]*p1.y+h10[i]*m1.y+h01[i]*p2.y+h11[i]*m2.y;
        }
    }
}

/* samo za testiranje algoritma za kardinalni spline */
void Osnova::HermiteTest(wxGraphicsContext *gc, double tenzija)
{
    int i,j, n;
    double t,t2,t3,tf,invp;
    double h00[20], h10[20], h01[20], h11[20];
    wxRealPoint tocke[5];
    wxRealPoint m1,m2,interpolirani;
    wxGraphicsPath path = gc->CreatePath();
    wxGraphicsPath path2 = gc->CreatePath();
    wxPen pero(wxColor(255,0,0),1);
    wxPen pero2(wxColor(0,128,0),1);
    gc->SetPen(pero);
    tocke[0]=wxRealPoint(210.0,180.0);
    tocke[1]=wxRealPoint(200.0,200.0);
    tocke[2]=wxRealPoint(400.0,220.0);
    tocke[3]=wxRealPoint(420.0,500.0);
    tocke[4]=wxRealPoint(140.0,300.0);

    //Hermiteova baza
    for(i=1, invp=1.0/20.0; i<20; i++)
    {
        t=invp*i;
        t2=t*t;
        t3=t2*t;
        h00[i]=2.0*t3-3.0*t2+1.0;
        h10[i]=t3-2.0*t2+t;
        h01[i]=-2.0*t3+3.0*t2;
        h11[i]=t3-t2;
    }

    tf=0.5*(1.0-tenzija);
    n=5;
    for(i=0; i<n; i++)
    {
        path.AddCircle(tocke[i].x,tocke[i].y,4.0);
        m1=tf*(tocke[((i+1)%n+n)%n]-tocke[((i-1)%n+n)%n]);
        m2=tf*(tocke[((i+2)%n+n)%n]-tocke[((i)%n+n)%n]);
        path.AddCircle(tocke[i].x+m1.x,tocke[i].y+m1.y,2.0);
        path.MoveToPoint(tocke[i].x,tocke[i].y);
        path.AddLineToPoint(tocke[i].x+m1.x,tocke[i].y+m1.y);

        path.AddCircle(tocke[((i+1)%n+n)%n].x-m2.x,tocke[((i+1)%n+n)%n].y-m2.y,2.0);
        path.MoveToPoint(tocke[((i+1)%n+n)%n].x,tocke[((i+1)%n+n)%n].y);
        path.AddLineToPoint(tocke[((i+1)%n+n)%n].x-m2.x,tocke[((i+1)%n+n)%n].y-m2.y);


        path.AddCircle(tocke[i].x,tocke[i].y,2.0);
        path2.MoveToPoint(tocke[i].x,tocke[i].y);
        for(j=1; j<20; j++)
        {
            interpolirani.x=h00[j]*tocke[i].x+h10[j]*m1.x+h01[j]*tocke[((i+1)%n+n)%n].x+h11[j]*m2.x;
            interpolirani.y=h00[j]*tocke[i].y+h10[j]*m1.y+h01[j]*tocke[((i+1)%n+n)%n].y+h11[j]*m2.y;
            path.AddCircle(interpolirani.x,interpolirani.y,1);
            path2.AddLineToPoint(interpolirani.x,interpolirani.y);
        }
        path2.AddLineToPoint(tocke[((i+1)%n+n)%n].x,tocke[((i+1)%n+n)%n].y);
    }


    gc->SetPen(pero2);
    gc->StrokePath(path2);
    gc->SetPen(pero);
    gc->StrokePath(path);


}

