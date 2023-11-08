#pragma once
#include "SecilebilenBolmeler.h"


//Kalem Boyut Bolmesi SecilebilenBolmelerin alt sinifidir.


class KalemBoyutuBolmesi : public SecilebilenBolmeler
{

public:

	KalemBoyutuBolmesi(wxWindow* ebeveyn, wxWindowID id, int kalemW, const wxPoint& pozisyon = wxDefaultPosition, const wxSize& boyut = wxDefaultSize);
	
	int kalemBoyutu;

private:
	virtual void IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const override;

};

