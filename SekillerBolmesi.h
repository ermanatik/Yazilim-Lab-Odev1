#pragma once
#include "SecilebilenBolmeler.h"

class SekillerBolmesi : public SecilebilenBolmeler {
public:
    SekillerBolmesi(wxWindow* ebeveyn, wxWindowID id = wxID_ANY, const wxPoint& pozisyon = wxDefaultPosition, const wxSize& boyut = wxDefaultSize);

protected:
    void IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const override;
};
