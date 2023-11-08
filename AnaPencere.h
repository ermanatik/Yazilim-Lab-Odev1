#pragma once
#include <wx/wx.h>							//Proje tasarlanmasinda wxWidgets kutuphanesinden yararlaniilmistir
#include <wx/wrapsizer.h>					//wrapsizer sayesinde pencere boyutu degistiginde icerisindeki sekmelerde bulunan nesneler pencereye sigmaya calisir
#include <wx/splitter.h>					//splitter sayesinde renk, boyut ve cizim panelleri pencere icinde ayrilir ve genisletilebilir hale gelir

#include <vector>

#include "RenkPaneli.h"						
#include "KalemBoyutuBolmesi.h"
#include "TuvaleCizim.h"

//Ana pencere sinifi icerisinde uygulamayi baslattigimiz andan itibaren karsimiza cikacak olan gorel ogeler bulunur
//Bu gorsel ogelerin olusturulmasinda Ana pencere sinifini kullaniriz
//Ana pencere sinifi wxWidgets icinde bulunan wxFrame(pencere) sinifindan turetilmistir. Kalitimla sahip oldugu bazi fonksiyonlar vardir.
class AnaPencere  : public wxFrame
{
public: 

	AnaPencere(const wxString& baslik, const wxPoint& pozisyon, const wxSize& boyut);

private:

	//kontrol paneli olusturmak icin kullaniriz
	wxPanel* KontrolPaneliOlustur(wxWindow* ebeveyn);

	//renk ve kalem bolmeleri icin
	void RenkPaneliKur(wxWindow* ebeveyn, wxSizer* sizer);
	void KalemBolmesiKur(wxWindow* ebeveyn, wxSizer* sizer);

	//fare ile renk ve boyut sectigimize dair fonksiyonlar
	void RenkBolmesiSec(RenkPaneli* bolme);
	void KalemBolmesiSec(KalemBoyutuBolmesi* bolme);

	//renklerin cesitlerini, kalem boyutlarini iclerinde tutan vektorler
	std::vector<RenkPaneli*> renkBolmeleri{};
	std::vector<KalemBoyutuBolmesi*> kalemBolmeleri{};
	
	//renk ve boyut panelleri disinda tuval icin de bir panel olusturduk
	TuvaleCizim* tuval;


	//11 tane renk tanimladik
	const std::vector<std::string>renkler{
		"#000000","#ffffff","#fd7f6f",
		"#7eb0d5","#b2e061","#bd7ebe",
		"#ffb55a","#ffee65","#beb9db",
		"#fdcce5","#8bd3c7" };

	//8 tane kalem boyutu
	const int kalemSayisi = 8;


	const std::string aydinlikArkaPlan = "#f4f3f3";
	const std::string karanlikArkaPlan = "#2c2828";


};

