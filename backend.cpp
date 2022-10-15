#include "backend.h"

SWESoftware::Produkt::Produkt() { ; }

SWESoftware::Produkt::~Produkt() { delete(this); }





SWESoftware::Lager::Lager() { ; }
SWESoftware::Lager::~Lager() { delete(this); }

bool SWESoftware::Lager::saveToFile() {
	

	std::ofstream  outputfile;

	//locates the users document folder and saves its path to target_path
	PWSTR PWSTRappData_path = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, NULL, NULL, &PWSTRappData_path);
	std::filesystem::path target_path = std::filesystem::path(PWSTRappData_path);

	//creates the custom directory at the location from above
	target_path = (target_path.c_str()) + std::wstring(L"\\SWE-Software");
	std::filesystem::create_directory(target_path);

	//creates a new file inside of the before created folder
	target_path = (target_path.c_str()) + std::wstring(L"\\savestate.txt");
	outputfile.open(target_path.string(), std::ofstream::out | std::ofstream::trunc);

	

	//File content goes here



	outputfile.close();
	return true;


}

void SWESoftware::Lager::DecrementProdukt(Produkt toDecrement) {

}



SWESoftware::Lieferer::Lieferer()
{
}

SWESoftware::Lieferer::~Lieferer() { delete(this); }

