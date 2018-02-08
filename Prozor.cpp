#include "Prozor.h"

const static double ParametriPodaci[][19]={
{1.8, 49.7,-0.18126,25.0, 1.0,1.0,12.0,12.0,16.0,20.0,14.0, 1.0,1.0,6.0,6.0,13.0,16.0,14.0, 0.66},
{0.5, 49.8,-0.18126,25.0, 1.0,1.0,5.0,5.0,12.0,20.0,14.0, 1.0,1.0,3.0,3.0,13.0,16.0,14.0, 0.66},
{2.75, 50.05,-0.18106,26.0, 0.95,0.95,6,6,4,8,12, 1.1,1.1,3.0,3.0,20,8,3,0.66},
{2.75, 47.96,-0.181164,22, 1,0.91,8,8,6,8,12, 1.8,0.9,3,3,25,5,1.9,0.66},
{1.2, 24.20,-0.178,20.5, 1.00,0.55,12,12,6,24,9, 2,2,4,4,25,8,3, 0.67},
{1.2, 48,-0.17785,80, 1,2,16,16,24,24,9, 0.5,0.5,5,5,30,12,12, 0.7},
{1.2, 48.0, -0.177850,80, 1,2,16,16,40,20,9, 0.50,0.50,16,16,26,12,12, 0.7}};
const static char ParametriPreklopnici[][2]={{2, 0},{2,1},{3,1},{3,1},{3,1},{3,0},{3,0}};

Prozor::Prozor(IOsnova *osnova) : wxProzor(NULL)
{
    wxGraphicsRenderer *renderer;
    int verzija[3];
    this->osnova=osnova;
    Bind(wxObradiObjekt, &Prozor::obradiObjekt, this);

    //renderer = wxGraphicsRenderer::GetDefaultRenderer();
    //renderer = wxGraphicsRenderer::GetDirect2DRenderer();
    renderer = wxGraphicsRenderer::GetGDIPlusRenderer();
    renderer->GetVersion(&(verzija[0]),&(verzija[1])+1,&(verzija[2]));
    std::cout << "wxGraphicsRenderer: " << renderer->GetName() << std::endl;
    std::cout << "Verzija: " << verzija[0] << "." << verzija[1] << "." << verzija[2] << std::endl;

    bitmap=new wxBitmap(wxSystemSettings::GetMetric ( wxSYS_SCREEN_X ) ,wxSystemSettings::GetMetric ( wxSYS_SCREEN_Y ) );
    memDC = new wxMemoryDC(*bitmap);

    panelCrtanje->SetBackgroundStyle(wxBG_STYLE_PAINT);
    memDC->Clear();
    wxInitAllImageHandlers();
}

Prozor::~Prozor()
{
    memDC->SelectObject(wxNullBitmap);
    delete bitmap;
    delete memDC;
}

void Prozor::onExit(wxCommandEvent& event)
{


}

void Prozor::obradiObjekt(wxCommandEvent& event)
{
    //Objekt *objekt = wxDynamicCast(event.GetEventObject(),Objekt);
    //podaci = (std::vector<Podatak*> *)event.GetClientData();


}
void Prozor::PodesiParametre( wxCommandEvent& event )
{
    int indeks;
    wxButton *gumb = wxDynamicCast(event.GetEventObject(),wxButton);
    wxWindowID id=gumb->GetId();
    switch(id)
    {
    case wxID_Primjer1:
        indeks=0;
        break;
    case wxID_Primjer2:
        indeks=1;
        break;
    case wxID_Primjer3:
        indeks=2;
        break;
    case wxID_Primjer4:
        indeks=3;
        break;
    case wxID_Primjer5:
        indeks=4;
        break;
    case wxID_Primjer6:
        indeks=5;
        break;
    case wxID_Primjer7:
        indeks=6;
        break;
    }
    m_textCtrl_tenzija->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][0]));
    m_radioBox_detalj->SetSelection(ParametriPreklopnici[indeks][0]);
    m_textCtrl_R->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][1]));
    m_textCtrl_r->SetValue(wxString::Format(wxT("%.6f"), ParametriPodaci[indeks][2]));
    m_textCtrl_p->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][3]));
    m_textSuper_a->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][4]));
    m_textSuper_b->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][5]));
    m_textSuper_m1->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][6]));
    m_textSuper_m2->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][7]));
    m_textSuper_n1->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][8]));
    m_textSuper_n2->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][9]));
    m_textSuper_n3->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][10]));
    m_textSuper2_a->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][11]));
    m_textSuper2_b->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][12]));
    m_textSuper2_m1->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][13]));
    m_textSuper2_m2->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][14]));
    m_textSuper2_n1->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][15]));
    m_textSuper2_n2->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][16]));
    m_textSuper2_n3->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][17]));
    m_checkBox_rot->SetValue(ParametriPreklopnici[indeks][1]);
    m_textCtrl_skala->SetValue(wxString::Format(wxT("%.2f"), ParametriPodaci[indeks][18]));
}
void Prozor::Nacrtaj( wxPaintEvent& event )
{
    int w, h;
    wxPanel *panel;
    wxGraphicsRenderer *renderer;
    wxGraphicsContext *gc;
    panel = wxDynamicCast(event.GetEventObject(),wxPanel);
    panel->GetSize(&w,&h);

    /* preiranje konteksta iz renderera */
    //gc=renderer->CreateContext(hdc);
    //kreiranje konteksta direktno
    //wxPaintDC hdc(panel);
    /* kreiranje buffered konteksta */
    //wxBufferedPaintDC hdc(panel);
    /* auto ne radi bez SetBackgroundStyle(wxBG_STYLE_PAINT) */
    /* ako sustav ima double buffer to postaje wxPaintDC*/
    wxAutoBufferedPaintDC hdc(panel);
    //hdc.Clear();

    //hdc.SetUserScale(2.0,2.0);
    hdc.Blit(0,0,w,h,memDC,0,0);
    //hdc.SetUserScale(1.0,1.0);
}

void Prozor::PrikaziSpiro( wxCommandEvent& event )
{
    bool res;
    panelCrtanje->GetSize(&(p.w),&(p.h));

    sp.detalj=m_radioBox_detalj->GetSelection()+1;
    p.vrsta=VrstaIzracuna::SPIRO;
    res=m_textCtrl_tenzija->GetValue().ToDouble(&(sp.tenzija));
    if(!res)
    {
        m_textCtrl_tenzija->SetValue(m_textCtrl_tenzija->GetLabel());
        m_textCtrl_tenzija->GetLabel().ToDouble(&(sp.tenzija));
    }
    res=m_textCtrl_R->GetValue().ToDouble(&(p.R));
    if(!res)
    {
        m_textCtrl_R->SetValue(m_textCtrl_R->GetLabel());
        m_textCtrl_R->GetLabel().ToDouble(&(p.R));
    }
    res=m_textCtrl_r->GetValue().ToDouble(&(p.r));
    if(!res)
    {
        m_textCtrl_r->SetValue(m_textCtrl_r->GetLabel());
        m_textCtrl_r->GetLabel().ToDouble(&(p.r));
    }
    res=m_textCtrl_p->GetValue().ToDouble(&(p.p));
    if(!res)
    {
        m_textCtrl_p->SetValue(m_textCtrl_p->GetLabel());
        m_textCtrl_p->GetLabel().ToDouble(&(p.p));
    }
    CrtajUMemDC(p,sp);
}
void Prozor::PrikaziSuper( wxCommandEvent& event )
{
    bool res, proslijedi;
    sp.detalj=m_radioBox_detalj->GetSelection()+1;
    panelCrtanje->GetSize(&(p.w),&(p.h));
    event.GetEventObject()==m_buttonSuper?proslijedi=false:proslijedi=true;
    res=m_textCtrl_tenzija->GetValue().ToDouble(&(sp.tenzija));
    if(!res)
    {
        m_textCtrl_tenzija->SetValue(m_textCtrl_tenzija->GetLabel());
        m_textCtrl_tenzija->GetLabel().ToDouble(&(sp.tenzija));
    }
    res=m_textSuper_a->GetValue().ToDouble(&(p.a));
    if(!res)
    {
        m_textSuper_a->SetValue(m_textSuper_a->GetLabel());
        m_textSuper_a->GetLabel().ToDouble(&(p.a));
    }
    res=m_textSuper_b->GetValue().ToDouble(&(p.b));
    if(!res)
    {
        m_textSuper_b->SetValue(m_textSuper_b->GetLabel());
        m_textSuper_b->GetLabel().ToDouble(&(p.b));
    }
    res=m_textSuper_m1->GetValue().ToDouble(&(p.m1));
    if(!res)
    {
        m_textSuper_m1->SetValue(m_textSuper_m1->GetLabel());
        m_textSuper_m1->GetLabel().ToDouble(&(p.m1));
    }
    res=m_textSuper_m2->GetValue().ToDouble(&(p.m2));
    if(!res)
    {
        m_textSuper_m2->SetValue(m_textSuper_m2->GetLabel());
        m_textSuper_m2->GetLabel().ToDouble(&(p.m2));
    }
    res=m_textSuper_n1->GetValue().ToDouble(&(p.n1));
    if(!res)
    {
        m_textSuper_n1->SetValue(m_textSuper_n1->GetLabel());
        m_textSuper_n1->GetLabel().ToDouble(&(p.n1));
    }
    res=m_textSuper_n2->GetValue().ToDouble(&(p.n2));
    if(!res)
    {
        m_textSuper_n2->SetValue(m_textSuper_n2->GetLabel());
        m_textSuper_n2->GetLabel().ToDouble(&(p.n2));
    }
    res=m_textSuper_n3->GetValue().ToDouble(&(p.n3));
    if(!res)
    {
        m_textSuper_n3->SetValue(m_textSuper_n3->GetLabel());
        m_textSuper_n3->GetLabel().ToDouble(&(p.n3));
    }
    p.sekundarna=false;
    p.vrsta=VrstaIzracuna::SUPER;
    if(!proslijedi)
        CrtajUMemDC(p,sp);
    else
    {
        osnova->IzracunavanjeSuper(p,sp);
        PrikaziSuper2(p);
    }
}


void Prozor::PrikaziSuper2( Parametri p1 )
{
    bool res;
    sp.detalj=m_radioBox_detalj->GetSelection()+1;
    panelCrtanje->GetSize(&(p.w),&(p.h));
    res=m_textCtrl_tenzija->GetValue().ToDouble(&(sp.tenzija));
    p.rotiranje=m_checkBox_rot->GetValue();
    if(!res)
    {
        m_textCtrl_tenzija->SetValue(m_checkBox_rot->GetLabel());
        m_checkBox_rot->GetLabel().ToDouble(&(sp.tenzija));
    }
    res=m_textSuper2_a->GetValue().ToDouble(&(p.a));
    if(!res)
    {
        m_textSuper2_a->SetValue(m_textSuper2_a->GetLabel());
        m_textSuper2_a->GetLabel().ToDouble(&(p.a));
    }
    res=m_textSuper2_b->GetValue().ToDouble(&(p.b));
    if(!res)
    {
        m_textSuper2_b->SetValue(m_textSuper2_b->GetLabel());
        m_textSuper2_b->GetLabel().ToDouble(&(p.b));
    }
    res=m_textSuper2_m1->GetValue().ToDouble(&(p.m1));
    if(!res)
    {
        m_textSuper2_m1->SetValue(m_textSuper2_m1->GetLabel());
        m_textSuper2_m1->GetLabel().ToDouble(&(p.m1));
    }
    res=m_textSuper2_m2->GetValue().ToDouble(&(p.m2));
    if(!res)
    {
        m_textSuper2_m2->SetValue(m_textSuper2_m2->GetLabel());
        m_textSuper2_m2->GetLabel().ToDouble(&(p.m2));
    }
    res=m_textSuper2_n1->GetValue().ToDouble(&(p.n1));
    if(!res)
    {
        m_textSuper2_n1->SetValue(m_textSuper2_n1->GetLabel());
        m_textSuper2_n1->GetLabel().ToDouble(&(p.n1));
    }
    res=m_textSuper2_n2->GetValue().ToDouble(&(p.n2));
    if(!res)
    {
        m_textSuper2_n2->SetValue(m_textSuper2_n2->GetLabel());
        m_textSuper2_n2->GetLabel().ToDouble(&(p.n2));
    }
    res=m_textSuper2_n3->GetValue().ToDouble(&(p.n3));
    if(!res)
    {
        m_textSuper2_n3->SetValue(m_textSuper2_n3->GetLabel());
        m_textSuper2_n3->GetLabel().ToDouble(&(p.n3));
    }
    res=m_textCtrl_skala->GetValue().ToDouble(&(p.skala));
    if(!res)
    {
        m_textCtrl_skala->SetValue(m_textCtrl_skala->GetLabel());
        m_textCtrl_skala->GetLabel().ToDouble(&(p.skala));
    }
    /* izracunava vodilju koja se sprema u poljeRjesenja*/
    p1.vrsta=VrstaIzracuna::SUPER;
    osnova->IzracunavanjeSuper(p1,sp,0.0);
    p.miny=p1.miny; p.maxy=p1.maxy;
    /* ide dalje po protokolu za sekundarnu krivulju koja ce se spremati u poljeRjesenja2 i crtati */
    p.vrsta=VrstaIzracuna::SUPER;
    p.sekundarna=true;
    CrtajUMemDC(p,sp);
}

void Prozor::CrtajUMemDC(Parametri p, SplineParametri sp)
{
    //Gdiplus::Graphics *gdiPlus;
    wxGraphicsContext *gc;
    memDC->Clear();
    gc = wxGraphicsContext::Create( *memDC );
    /* nativni Windows GDI+ */
    //gdiPlus=(Gdiplus::Graphics*)(gc->GetNativeContext());
    if(gc)
    {
        //osnova->CrtanjaPanela(gc);
        osnova->CrtanjaPanela(gc, p, sp, NULL);
        delete gc;
    }
    panelCrtanje->Refresh();
}

void Prozor::SnimiSliku( wxCommandEvent& event )
{
    int w, h;
    bool res;
    wxMemoryDC memDCSnimanje;
    wxBitmap *bitmapaSnimanje;
    wxFileDialog *dijalogSnimanje;
    wxString izlaznaDatoteka;
    panelCrtanje->GetSize(&w,&h);

    dijalogSnimanje = new wxFileDialog(this,
                              wxT("Snimanje prikazane krivulje"),wxStandardPaths::Get().GetDocumentsDir(),
                              wxT("Guiloche"),
                              wxT("JPEG datoteke (*.jpg)|*.jpg|PNG datoteke (*.png)|*.png|TIFF datoteke (*.tif)|*.tif|BMP datoteke (*.bmp)|*.bmp|SVG vektorski format (*.svg)|*.svg"),
                              wxFD_SAVE | wxFD_OVERWRITE_PROMPT,
                              wxDefaultPosition,
                              wxDefaultSize);
    if (dijalogSnimanje->ShowModal() == wxID_OK)
    {
        izlaznaDatoteka = dijalogSnimanje->GetPath();
        bitmapaSnimanje = new wxBitmap(w,h);
        memDCSnimanje.SelectObject(*bitmapaSnimanje);
        memDCSnimanje.Blit(0,0, w, h, memDC, 0, 0);
        memDCSnimanje.SelectObject(wxNullBitmap);

        if( (izlaznaDatoteka.Matches(wxT("*.jpg")) || izlaznaDatoteka.Matches(wxT("*.jpeg"))) )
            bitmapaSnimanje->ConvertToImage().SaveFile(izlaznaDatoteka,wxBITMAP_TYPE_JPEG);
        else if (izlaznaDatoteka.Matches(wxT("*.png")))
            bitmapaSnimanje->ConvertToImage().SaveFile(izlaznaDatoteka,wxBITMAP_TYPE_PNG);
        else if (izlaznaDatoteka.Matches(wxT("*.bmp")))
            bitmapaSnimanje->ConvertToImage().SaveFile(izlaznaDatoteka,wxBITMAP_TYPE_BMP);
        else if( (izlaznaDatoteka.Matches(wxT("*.tif")) || izlaznaDatoteka.Matches(wxT("*.tiff"))) )
            bitmapaSnimanje->ConvertToImage().SaveFile(izlaznaDatoteka,wxBITMAP_TYPE_TIF);
        else if(izlaznaDatoteka.Matches(wxT("*.svg")))
        {
            wxSVGFileDC svgDC(izlaznaDatoteka,100*p.w,100*p.h,4800.0);
            osnova->CrtanjaPanela(NULL,p,sp,&svgDC);
        }
        else
        {
            izlaznaDatoteka += wxT(".jpg");
            bitmapaSnimanje->ConvertToImage().SaveFile(izlaznaDatoteka,wxBITMAP_TYPE_JPEG);
        }

        //bitmapaSnimanje->ConvertToImage().SaveFile(dijalogSnimanje->GetPath());
        delete bitmapaSnimanje;
    }


    delete dijalogSnimanje;

}
