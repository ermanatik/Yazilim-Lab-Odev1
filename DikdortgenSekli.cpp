#include "DikdortgenSekli.h"

DikdortgenSekil::DikdortgenSekil(const wxPoint& baslangicNoktasi, const wxPoint& bitisNoktasi, const wxColour& renk, int cizgiUzunlugu)
    : Sekiller(baslangicNoktasi, bitisNoktasi, renk, cizgiUzunlugu) {}

void DikdortgenSekil::ciz(wxDC& cizim) const {

    cizim.SetPen(wxPen(setRenk, setCizgiUzunlugu));
    cizim.DrawRectangle(setBaslangicNoktasi.x, setBaslangicNoktasi.y,
        setBitisNoktasi.x - setBaslangicNoktasi.x, setBitisNoktasi.y - setBaslangicNoktasi.y);

}