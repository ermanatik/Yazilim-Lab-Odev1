#pragma once
#include <wx/wx.h>
#include <vector>


//farenin izledigi yollari saklar
struct Yol {

	std::vector<wxPoint2DDouble> noktalar;
	wxColour renk;
	int genislik;


};