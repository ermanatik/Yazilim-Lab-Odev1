#pragma once
#include <wx/wx.h>

class Sekiller
{
public: 
	Sekiller(const wxPoint& baslangicNoktasi, const wxPoint& bitisNoktasi, const wxColour& renk, int cizgiUzunlugu);
		
	virtual ~Sekiller() = default;

	virtual void ciz(wxDC& cizim) const = 0;

protected:

	wxPoint setBaslangicNoktasi;
	wxPoint setBitisNoktasi;
	wxColour setRenk;
	int setCizgiUzunlugu;

};

