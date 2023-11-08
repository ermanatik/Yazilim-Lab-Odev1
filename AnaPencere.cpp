#include "AnaPencere.h"
//Ana pencere sinifinda bulunan fonksiyonlarin gerceklestirildigi yer



AnaPencere::AnaPencere(const wxString& baslik, const wxPoint& pozisyon, const wxSize& boyut)
	: wxFrame(nullptr, wxID_ANY, baslik, pozisyon, boyut) {

	//Ana pencere olustururken icinde bulunacaklari ve birbirlerine gore baslangic konumlarinin tanimlandigi yer
	wxSplitterWindow* splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_BORDER | wxSP_LIVE_UPDATE);

	splitter->SetMinimumPaneSize(FromDIP(150));

	auto kontrolPaneli = KontrolPaneliOlustur(splitter);
	tuval = new TuvaleCizim(splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	splitter->SplitVertically(kontrolPaneli, tuval);
	splitter->SetSashPosition(FromDIP(220));

	this->SetSize(FromDIP(800), FromDIP(500));
	this->SetMinSize({FromDIP(400),FromDIP(200) });

	RenkBolmesiSec(renkBolmeleri[0]);
	KalemBolmesiSec(kalemBolmeleri[0]);


}



wxPanel* AnaPencere::KontrolPaneliOlustur(wxWindow* ebeveyn) {

	//Kontrol paneli olusturur.wxScrolled gozukmeyen tuslar icin kontrol cubugu olusturmamizi saglar.
	auto kontrolPaneli = new wxScrolled<wxPanel>(ebeveyn, wxID_ANY);
	kontrolPaneli->SetScrollRate(0, FromDIP(10));

	//Karanlik temaysa karanlik arka plan aydinlik temaysa aydinlik arka plan yapar
	bool karanlikMi = wxSystemSettings::GetAppearance().IsDark();
	kontrolPaneli->SetBackgroundColour(wxColour(karanlikMi ? karanlikArkaPlan : aydinlikArkaPlan));

	//Ana boyutlandirici wxBoxSizer kullanarak 
	auto mainSizer = new wxBoxSizer(wxVERTICAL);

	//Renklerin bulundugu bolmenin basligi
	auto text = new wxStaticText(kontrolPaneli, wxID_ANY, "Renkler");
	mainSizer->Add(text, 0, wxALL, FromDIP(5));

	//renkBolmesinin boyutunu ayarlar
	auto renkBolmesiBoyutu = new wxWrapSizer(wxHORIZONTAL);
	RenkPaneliKur(kontrolPaneli, renkBolmesiBoyutu);

	mainSizer->Add(renkBolmesiBoyutu, 0, wxALL, FromDIP(5));

	//kalemlerin bulundugu bolmenin basligi
	text = new wxStaticText(kontrolPaneli, wxID_ANY, "Kalem Boyutlari");
	mainSizer->Add(text, 0, wxALL, FromDIP(5));
	
	//kalemBolmesiSizer kalem boyutlarini basligin altinda yatay bir sekilde konumlandirir
	auto kalemBolmesiSizer = new wxWrapSizer(wxHORIZONTAL);
	KalemBolmesiKur(kontrolPaneli, kalemBolmesiSizer);
	mainSizer->Add(kalemBolmesiSizer, 0, wxALL, FromDIP(5));

	//Kaydetme tusu olusturur.
	auto button = new wxButton(kontrolPaneli, wxID_ANY, "Farklý Kaydet...");
	//kaydetme tusuna islem atadik, kaydetmek icin kullandigi KayýtKutusunuGoster() fonksiyonunu ayni zamanda sag tikla da ulasabildigimiz secim kutusunun da kullandigi fonksiyondur
	button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& olay)
		{tuval->KayýtKutusunuGoster(); });


	mainSizer->AddStretchSpacer();
	mainSizer->Add(button, 0, wxALL, FromDIP(5));
	mainSizer->AddSpacer(FromDIP(5));

	kontrolPaneli->SetSizer(mainSizer);

	return kontrolPaneli;
}



void AnaPencere::RenkPaneliKur(wxWindow* ebeveyn, wxSizer* sizer) {


	//Ana menu sinifinda tanimli olan renkBolmelerine renkleri atar ve sizer'ýn add komutu ile uygulama penceresine ekler.

	for (const auto& color : renkler) {

		auto renkBolmesi = new RenkPaneli(ebeveyn, wxID_ANY, wxColour(color));

		//uzerine tiklanan rengi secer
		renkBolmesi->Bind(wxEVT_LEFT_DOWN, [this, renkBolmesi](wxMouseEvent& olay) 
			{ RenkBolmesiSec(renkBolmesi); });



		renkBolmeleri.push_back(renkBolmesi);
		sizer->Add(renkBolmesi, 0, wxRIGHT | wxBOTTOM, FromDIP(5));

	}
	

}


void AnaPencere::KalemBolmesiKur(wxWindow* ebeveyn, wxSizer* sizer) {


	//Ana menu sinifinda tanimli olan kalemBolmelerine boyutlari atar ve pencereye ekler.

	for (int i = 0; i < kalemSayisi; i++) {

		auto kalemBolmesi = new KalemBoyutuBolmesi(ebeveyn, wxID_ANY, i * FromDIP(4) + FromDIP(1));
		//uzerine tiklanan boyutu secer
		kalemBolmesi->Bind(wxEVT_LEFT_DOWN, [this, kalemBolmesi](wxMouseEvent& olay)
			{ KalemBolmesiSec(kalemBolmesi); });

		kalemBolmeleri.push_back(kalemBolmesi);
		sizer->Add(kalemBolmesi, 0, wxRIGHT | wxBOTTOM, FromDIP(5));

	}


}

//Uzerine tiklanan rengi secmek icin kullaniriz
void AnaPencere::RenkBolmesiSec(RenkPaneli* bolme) {


	for (auto renkBolmesi : renkBolmeleri) {

		renkBolmesi->selected = (renkBolmesi == bolme);
		renkBolmesi->Refresh();

	}
	
	tuval->currentRenk = bolme->renk;

}

//Uzerine tiklanan boyutu secmek icin kullaniriz
void AnaPencere::KalemBolmesiSec(KalemBoyutuBolmesi* bolme) {


	for (auto boyutBolmesi : kalemBolmeleri) {

		boyutBolmesi->selected = (boyutBolmesi == bolme);
		boyutBolmesi->Refresh();

	}

	tuval->currentBoyut = bolme->kalemBoyutu;

}
