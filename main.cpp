//210501002 Erman Atik Bilgisayar Mühendisligi 3. Sinif Kocaeli Saglik ve Teknoloji Universitesi
//Yazýlým Lab. 1   1. Proje

//Cizim Paneli 

#include <wx/wx.h>							//Proje tasarlanmasinda wxWidgets kutuphanesinden yararlaniilmistir
#include <wx/wrapsizer.h>					//Wx kutuphanelerinden biri olan wrapsizer sayesinde ana panel boyutu kuculdugunde butonlar ve yan paneller pecereye uyum sagliyor


#include <string>
#include <vector>

#include "Uygulama.h"						//Uygulamanin calistirilmasi icin hazirlanan sinif.
#include "AnaPencere.h"						//Olusan pencerenin duzenini ve icerigini hazirlayan sinif.
#include "RenkPaneli.h"						//Kalemin rengini secmemiz icin secenek sunan renk paneli sinifi.
#include "KalemBoyutuBolmesi.h"				//Kalemin boyutunu secmemiz icin secenek sunan boyut bolme sinifi.

wxIMPLEMENT_APP(Uygulama);					//wxIMPLEMENT_APP makrosu uygulamanýn giris noktasini belirtmek icin kullanilir

