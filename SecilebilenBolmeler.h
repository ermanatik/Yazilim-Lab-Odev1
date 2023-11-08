#pragma once
#include <wx/wx.h>

#include <wx/graphics.h>
#include <wx/settings.h>
#include <wx/dcbuffer.h>

//Bu sinif renklerin ve kalem boyutlarinin olusturulmasinda ebeveyn sinif olmak icin var. 
//Sinifin kendisi de wxWindow'un cocuk sinifidir.

class SecilebilenBolmeler : public wxWindow
{

public:
	SecilebilenBolmeler(wxWindow* ebeveyn, wxWindowID id = wxID_ANY, const wxPoint& pozisyon = wxDefaultPosition, const wxSize& boyut = wxDefaultSize);

	wxSize DoGetBestSize() const override {

		return FromDIP(wxSize(45, 45));
	}

	bool selected = false; //Hangi renk ve kalemin secili oldugunu gosterir

protected:
	virtual void IcerikCiz(wxGraphicsContext* grafik, const wxRect& dikdortgen, int roundness) const = 0;
	//Graphics Context sinifi nesnelerini kullanarak cizer

private:
	void OnPaint(wxPaintEvent& olay);
};

