#include "TuvaleCizim.h"

#include <wx/graphics.h>
#include <wx/dcbuffer.h>

//Tuval uzerinde gerceklesen olaylarin yakalamasi ve dogru cevabin verilmesi
//Bind fonksiyonu bir olayi nesneye baglamak icin kullanilir

TuvaleCizim::TuvaleCizim(wxWindow* ebeveyn, wxWindowID id, const wxPoint& pozisyon, const wxSize& boyut)
	:wxWindow(ebeveyn, id, pozisyon, boyut) {

	this->SetBackgroundStyle(wxBG_STYLE_PAINT);

	this->Bind(wxEVT_PAINT, &TuvaleCizim::OnPaint, this);
	this->Bind(wxEVT_LEFT_DOWN, &TuvaleCizim::FareAsagi, this);
	this->Bind(wxEVT_MOTION, &TuvaleCizim::FareHareketi, this);
	this->Bind(wxEVT_LEFT_UP, &TuvaleCizim::FareYukari, this);
	this->Bind(wxEVT_LEAVE_WINDOW, &TuvaleCizim::FareCikis, this);

	IcerikMenusuOlustur();

	this->Bind(wxEVT_CONTEXT_MENU, &TuvaleCizim::IcerikMenusuEventi, this);

}

//yazim olayi esnasinda grafik kutuphanesini kullanarak drawOnContext fonksiyonu cagrilir
void TuvaleCizim::OnPaint(wxPaintEvent&) {

	wxAutoBufferedPaintDC cizim(this);
	cizim.SetBackground(*wxWHITE_BRUSH);
	cizim.Clear();

	wxGraphicsContext* grafik = wxGraphicsContext::Create(cizim);

	if (grafik) {

		DrawOnContext(grafik);

		delete grafik;


	}


}

//bu fonksiyon mouse hareketlerinde dokundugu noktalari kaydeder ve halihazirda secili olan renge, kalem boyutuna gore tuvali cizer

void TuvaleCizim::DrawOnContext(wxGraphicsContext* grafik) {

	for (const auto& s : cizim)
	{
		auto noktaVektoru = s.noktalar;
		if (noktaVektoru.size() > 1)
		{
			grafik->SetPen(wxPen(s.renk, s.genislik));
			grafik->StrokeLines(noktaVektoru.size(), noktaVektoru.data());
		}
	}

}

//kayit kutusu kaydetmek istedigimizde tur ve kayit yerini gosteren kutudur.
//kayit islemi cagrildiginda isaretlenmis olan bitmapi dosya kutusuna kaydetme fonksiyonu cagrilir.
void TuvaleCizim::KayýtKutusunuGoster()
{
	//dosya kutusuna kaydetmek icin kullaniriz
	wxFileDialog dosyaKutusunuKaydet(this, _("Cizimi kaydet"), "", "", "PNG files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (dosyaKutusunuKaydet.ShowModal() == wxID_CANCEL)
		return;


	//bitmap butun tuvalin boyutu kadar deger alir 
	wxBitmap bitmap(this->GetSize() * this->GetContentScaleFactor());


	//hafiza cizim icerigi bitmapi tutar ve kaydetmede kullanir.
	wxMemoryDC hafizaCizimIcerigi;

	hafizaCizimIcerigi.SetUserScale(this->GetContentScaleFactor(), this->GetContentScaleFactor());

	hafizaCizimIcerigi.SelectObject(bitmap);
	hafizaCizimIcerigi.SetBackground(*wxWHITE_BRUSH);
	hafizaCizimIcerigi.Clear();


	wxGraphicsContext* grafik = wxGraphicsContext::Create(hafizaCizimIcerigi);

	if (grafik)
	{

		DrawOnContext(grafik);
		delete grafik;

	}

	bitmap.SaveFile(dosyaKutusunuKaydet.GetPath(), wxBITMAP_TYPE_PNG);

}


//olaylarin yakalandigi fonksiyonlar...
void TuvaleCizim::FareAsagi(wxMouseEvent&) {
	cizim.push_back({ {},currentRenk,currentBoyut });
	cizimYapiliyorMu = true;
}

void TuvaleCizim::FareHareketi(wxMouseEvent &event) {

	if (cizimYapiliyorMu) {
		auto nokta = event.GetPosition();
		auto& currentCizim = cizim.back();

		currentCizim.noktalar.push_back(nokta);
		Refresh();

	}
}

void TuvaleCizim::FareYukari(wxMouseEvent&) {
	cizimYapiliyorMu = false;
}

void TuvaleCizim::FareCikis(wxMouseEvent&) {
	cizimYapiliyorMu = false;
}



//Farenin Sag Tusuna tikladigimizda bize bir icerik menusu olusturur

void TuvaleCizim::IcerikMenusuOlustur() {

	auto temizle = icerikMenusu.Append(wxID_ANY, "&Temizle");
	auto kaydet = icerikMenusu.Append(wxID_ANY, "Farkli Kaydet...");

	this->Bind(wxEVT_MENU, [this](wxCommandEvent&){

		this->cizim.clear();
		this->Refresh();
	}, temizle->GetId());


	this->Bind(wxEVT_MENU, [this](wxCommandEvent&) {
		this->KayýtKutusunuGoster();
		}, kaydet->GetId());

}


//Farenin Sag Tusuna tikladigimizde karsimiza cikmasi gereken icerik menusunu dogru konumda yaratmaya yardimci olur
void TuvaleCizim::IcerikMenusuEventi(wxContextMenuEvent& olay) {

	auto clientPozisyonu = olay.GetPosition() == wxDefaultPosition ? wxPoint(this->GetSize().GetWidth() / 2, this->GetSize().GetHeight() / 2)
		: this->ScreenToClient(olay.GetPosition());

	PopupMenu(&this->icerikMenusu, clientPozisyonu);

}

