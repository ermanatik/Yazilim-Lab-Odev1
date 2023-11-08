#include "Uygulama.h"

//Pencerenin adi ve gorunurlugu bu fonksiyonda tanimlanir
bool Uygulama::OnInit() {
	
	wxInitAllImageHandlers();
	

	AnaPencere* pencere = new AnaPencere("Cizim Paneli", wxDefaultPosition, wxDefaultSize);
	pencere->Show(true);
	return(true);

}
