#pragma once
#include "SecilebilenBolmeler.h"

//Renklerin bolmelendirilmesinde kullandigimiz sinif
//Secilebilen bolmeler sinifinda sanal olarak tanimlanan IcerikCiz() fonksiyonunu kullaniyoruz


class RenkPaneli : public SecilebilenBolmeler
{
public:
	RenkPaneli(wxWindow* ebeveyn, wxWindowID id, const wxColor& bolmeRengi, const wxPoint& pozisyon = wxDefaultPosition, const wxSize& boyut = wxDefaultSize);

	wxColour renk;

private:
	virtual void IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const override;

};

