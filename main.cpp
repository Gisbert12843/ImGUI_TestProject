#include "includeHeader.h"
#include "rendering.h"
#include "backend.h"
#include "frontend.h"
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//imguiMain();

	SWESoftware::Produkt newProduct("orange", 10, "B1", 123456);
	SWESoftware::Produkt newProduct2("apfel", 100, "A2", 2441243);
	SWESoftware::Lager* theLager = new SWESoftware::Lager({},{});
	SWESoftware::Lieferand* derLieferand = new SWESoftware::Lieferand("ALDI",{ &newProduct, &newProduct2 });
	SWESoftware::Lieferanden_Liste LieferandenListe = {derLieferand};
	theLager->add_to_lager(newProduct);
	theLager->add_to_lager(newProduct2);
	theLager->saveLagerToFile();
	LieferandenListe.saveLieferandenToFile();



	return 0;
}
