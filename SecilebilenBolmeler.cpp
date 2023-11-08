#include "SecilebilenBolmeler.h"



SecilebilenBolmeler::SecilebilenBolmeler(wxWindow* ebeveyn, wxWindowID id, const wxPoint& pozisyon, const wxSize& boyut)
	: wxWindow(ebeveyn, id, pozisyon, boyut, wxFULL_REPAINT_ON_RESIZE) {
	
	/*Arkaplan stilini ve cizim olayini tanimladigimiz constructor*/

	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	Bind(wxEVT_PAINT, &SecilebilenBolmeler::OnPaint, this);
}


void SecilebilenBolmeler::OnPaint(wxPaintEvent& olay) {
	//Bu fonskiyonda cizme olayini tanimladik. Renklerin ve kalem boyutlarinin iclerinde bulunacagi dikdortgenleri olusturduk.

	wxAutoBufferedPaintDC cizim(this);
	cizim.SetBackground(wxBrush(this->GetParent()->GetBackgroundColour()));
	cizim.Clear();


	auto grafik= wxGraphicsContext::Create(cizim);
	if (grafik) {

		wxRect dikdortgen{ 0,0,this->GetSize().GetWidth(), this->GetSize().GetHeight() };
		dikdortgen.Deflate(FromDIP(1));

		wxRect icerikDikdortgeni = dikdortgen;
		icerikDikdortgeni.Deflate(FromDIP(2));

		const auto roundness = FromDIP(4); //dikdortgenin koselerinden yuvarlaklik verdik.

		//FromDIP (Device-Independent Pixel): Ekrandaki piksel degerlerini, cihaza bagimsiz olarak olculen degerlerine donusturmek icin kullanilir.

		IcerikCiz(grafik, icerikDikdortgeni, roundness);

		if (selected) {
			grafik->SetPen(wxSystemSettings::GetAppearance().IsDark() ? *wxWHITE_PEN : *wxBLACK_PEN);
			grafik->SetBrush(*wxTRANSPARENT_BRUSH);

			grafik->DrawRoundedRectangle(dikdortgen.GetX(), dikdortgen.GetY(), dikdortgen.GetWidth(), dikdortgen.GetHeight(), roundness);

		}
		delete grafik;

	}


}


