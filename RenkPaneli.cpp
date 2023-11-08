#include "RenkPaneli.h"


RenkPaneli::RenkPaneli(wxWindow* ebeveyn, wxWindowID id, const wxColor& bolmeRengi, const wxPoint& pozisyon, const wxSize& boyut)
	:SecilebilenBolmeler(ebeveyn, id, pozisyon, boyut), renk(bolmeRengi)
{
	/*void*/
}

//Renklerin etrafini dikdortgen yapmada kullaniyoruz.
void RenkPaneli::IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const{
	
	grafik->SetPen(wxPen(renk));
	grafik->SetBrush(wxBrush(renk));

	grafik->DrawRoundedRectangle(dikdortgen.GetX(), dikdortgen.GetY(), dikdortgen.GetWidth(), dikdortgen.GetHeight(), roundness);

}