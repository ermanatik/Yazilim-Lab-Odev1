#include "KalemBoyutuBolmesi.h"

KalemBoyutuBolmesi::KalemBoyutuBolmesi(wxWindow* ebeveyn, wxWindowID id, int kalemW, const wxPoint& pozisyon, const wxSize& boyut)
	:SecilebilenBolmeler(ebeveyn, id, pozisyon, boyut), kalemBoyutu(kalemW) 
{
	/*void*/
}


//IcerikCiz Fonksiyonunun amaci olusturmasini istedigimiz kalem boyutu ayarlayan simgelerin grafik kullanan bir kutuphane ile gosterilmesini saglamak.
//wxGraphicsContext sayesinde dikdortgen ve kenarlarýndan oval olacak sekilde birden fazla secenek yapabiliyoruz
void KalemBoyutuBolmesi::IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const {

	grafik->SetPen(*wxWHITE_PEN);
	grafik->SetBrush(*wxWHITE_BRUSH);

	grafik->DrawRoundedRectangle(dikdortgen.GetX(), dikdortgen.GetY(), dikdortgen.GetWidth(), dikdortgen.GetHeight(), roundness);

	grafik->SetPen(*wxBLACK_PEN);
	grafik->SetBrush(*wxBLACK_BRUSH);

	//kalem boyutu her tusta farkli oldugu icin ayarlama formulu...
	grafik->DrawEllipse(dikdortgen.GetX() + dikdortgen.GetWidth() / 2 - kalemBoyutu / 2,
		dikdortgen.GetY() + dikdortgen.GetHeight() / 2 - kalemBoyutu / 2,
		kalemBoyutu, kalemBoyutu);

}