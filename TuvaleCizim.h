#pragma once

//Tuvale yapilan cizimler icin olan sinif
#include <wx/wx.h>
#include <vector>
#include "yol.h"


//Tuval uzerinde yapilan cizimleri, fare hareketlerini, icerik menusu icin sag tiklama islevini icinde bulundurur.
class TuvaleCizim : public wxWindow
{

public:
	TuvaleCizim(wxWindow* ebeveyn, wxWindowID id, const wxPoint& pozisyon, const wxSize& boyut);
	virtual ~TuvaleCizim() noexcept{}

	void KayýtKutusunuGoster();

	int currentBoyut{ 1 };
	wxColour currentRenk{ *wxBLACK };

private:

	void OnPaint(wxPaintEvent&);
	void DrawOnContext(wxGraphicsContext* grafik);

	void FareAsagi(wxMouseEvent&);
	void FareHareketi(wxMouseEvent&);
	void FareYukari(wxMouseEvent&);
	void FareCikis(wxMouseEvent&);

	bool cizimYapiliyorMu{};
	std::vector<Yol> cizim;

	wxMenu icerikMenusu;
	void IcerikMenusuOlustur();
	void IcerikMenusuEventi(wxContextMenuEvent&);

};

