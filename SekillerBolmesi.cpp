#include "SekillerBolmesi.h"

SekillerBolmesi::SekillerBolmesi(wxWindow* ebeveyn, wxWindowID id, const wxPoint& pozisyon, const wxSize& boyut)
    : SecilebilenBolmeler(ebeveyn, id, pozisyon, boyut) {}

void SekillerBolmesi::IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const {

  
    grafik->SetPen(wxPen(wxColour("blue")));
    grafik->SetBrush(wxBrush(wxColour("blue")));
    grafik->DrawEllipse(dikdortgen.GetX(), dikdortgen.GetY(), dikdortgen.GetWidth(), dikdortgen.GetHeight());
    
}