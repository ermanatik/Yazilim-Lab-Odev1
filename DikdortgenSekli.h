#pragma once
#include "Sekiller.h"


class DikdortgenSekil : public Sekiller {
public:
    DikdortgenSekil(const wxPoint& baslangicNoktasi, const wxPoint& bitisNoktasi, const wxColour& renk, int cizgiUzunlugu);
    void ciz(wxDC& dc) const override;
};
