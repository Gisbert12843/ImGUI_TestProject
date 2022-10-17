#include "backend.h"

static bool checkSavefile()
{
	PWSTR PWSTRappData_path = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, NULL, NULL, &PWSTRappData_path);
	std::filesystem::path target_path = std::filesystem::path(PWSTRappData_path);
	std::filesystem::path target_folderpath = std::filesystem::path(PWSTRappData_path);
	std::filesystem::path target_filepath = std::filesystem::path(PWSTRappData_path);
	target_folderpath = (target_path.string()) + std::string("\\SWE-Software");
	target_filepath = (target_folderpath.string()) + std::string("\\savestate.txt");

	if (!std::filesystem::is_directory(target_folderpath))
	{
		//creates the custom directory at the location given
		std::filesystem::create_directory(target_folderpath);

		//creates a new file inside of the before created folder
		std::ofstream  outputfile;
		outputfile.open(target_filepath, std::ofstream::out | std::ofstream::trunc);
		outputfile << "Lager{\n" << "}Lager\n";
		outputfile << "Einkauf{\n" << "}Einkauf\n";
		outputfile << "Verkauf{\n" << "}Verkauf\n";
		outputfile << "Lieferanden{\n" << "}Lieferanden\n";
		outputfile.close();
		return false;
	}
	else
		if(!std::filesystem::exists(target_filepath))
	{		
		//creates a new file inside of the before created folder
		std::ofstream  outputfile;
		outputfile.open(target_filepath, std::ofstream::out | std::ofstream::trunc);
		outputfile << "Lager{\n" << "}Lager\n";
		outputfile << "Einkauf{\n" << "}Einkauf\n";
		outputfile << "Verkauf{\n" << "}Verkauf\n";
		outputfile << "Lieferanden{\n" << "}Lieferanden\n";
		outputfile.close();
			return false;
	}
	return true;
}

auto isEmptyOrBlank = [](const std::string& s) {
	return s.find_first_not_of(" \t") == std::string::npos;
};

std::string to_lower_string(std::string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		s.at(i) = towlower(s.at(i));
	}
	return s;
}

std::string wide_string_to_string(std::wstring wide_string)
{
	if (wide_string.empty())
	{
		return "";
	}
	const auto size_needed = WideCharToMultiByte(CP_UTF8, 0, &wide_string.at(0), (int)wide_string.size(), nullptr, 0, nullptr, nullptr);
	if (size_needed <= 0)
	{
		throw std::runtime_error("WideCharToMultiByte() failed: " + std::to_string(size_needed));
	}

	std::string result(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wide_string.at(0), (int)wide_string.size(), &result.at(0), size_needed, nullptr, nullptr);
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lager

SWESoftware::Lager::Lager(std::map<int, Produkt*> lager_from_int, std::vector<std::string>lagerplaetze)
{
	this->lager_from_int = lager_from_int;
	this->lagerplaetze = lagerplaetze;
}
SWESoftware::Lager::~Lager() { delete(this); }

bool SWESoftware::Lager::saveLagerToFile()
{
	//locates the users document folder and saves its path to target_path
	PWSTR PWSTRappData_path = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, NULL, NULL, &PWSTRappData_path);
	std::filesystem::path target_path = std::filesystem::path(PWSTRappData_path);
	std::filesystem::path target_folderpath = std::filesystem::path(PWSTRappData_path);
	std::filesystem::path target_filepath = std::filesystem::path(PWSTRappData_path);

	target_folderpath = (target_path.string()) + std::string("\\SWE-Software");
	target_filepath = (target_folderpath.string()) + std::string("\\savestate.txt");


	bool found = false;

	checkSavefile();

	std::ifstream  inputfile;
	inputfile.open(std::filesystem::directory_entry(target_filepath), std::ifstream::in);
	if (inputfile.rdstate() != std::ios_base::goodbit)
		return false;

	if (inputfile.good() && inputfile) // optional: filecontent as target
	{
		std::string checkedString;
		std::vector<std::string> vecOfStr; //File Content as Vector of Strings

		while (std::getline(inputfile, checkedString)) // Every line of the inputfile gets its own string in the vector
		{
			vecOfStr.push_back(checkedString);
		}
		inputfile.close();

		auto itPos = vecOfStr.begin();
		//std::map<int, Produkt*>::iterator LagerIter;
		// checks every string of the vector if its the desired context eg "Lager{", then it erases everything until it finds an "}Lager" from which it inserts all each product detail into its own row
		for (auto it = std::begin(vecOfStr); it != std::end(vecOfStr); ++it)
		{			
			if (!found && *it == "Lager{")
			{
				if (itPos + 1 != vecOfStr.end())
					itPos++;
				found = true;
				continue;
			}
			else if (!found)
			{
				if (itPos + 1 != vecOfStr.end())
					itPos++;
				continue;
			}

			if(*it == "}Lager")
			{
				for (auto const& x : lager_from_int) {
					std::string to_insert = "";
					to_insert += std::to_string(x.second->SWE_EAN) + ";";
					to_insert += x.second->name + ";";
					to_insert += std::to_string(x.second->menge) + ";";
					to_insert += x.second->lagerort + ";;";
					vecOfStr.insert(std::find(vecOfStr.begin(),vecOfStr.end(),"}Lager"), to_insert);
				}
				break;
			}
			else
			{
				it->erase(); // clears a line of info in the vector
				continue;
			}

		}
		vecOfStr.erase(std::remove_if(vecOfStr.begin(), vecOfStr.end(), isEmptyOrBlank), vecOfStr.end()); //erases empty lines in th vector



		std::ofstream  outputfile;


		//creates a new file inside of the before created folder
		outputfile.open(target_filepath.string(), std::ofstream::out | std::ofstream::trunc);
		
		//Inserts the vectors content into the outputfile
		for (auto it = std::begin(vecOfStr); it != std::end(vecOfStr); ++it) {
			outputfile << *it << "\n";
		}



		outputfile.close();
		return true;
	}
}
		
void SWESoftware::Lager::add_to_lager(SWESoftware::Produkt product_to_add)
{
	int SWE_EAN = product_to_add.SWE_EAN;
	std::string product_name = product_to_add.name;
	int amount_to_increment = product_to_add.menge;
	std::string lagerort = product_to_add.lagerort;

	std::map<int, SWESoftware::Produkt*>::iterator it = lager_from_int.find(SWE_EAN); //finds the product in the map
	if (it != lager_from_int.end())	//do this if the given iterator isnt the end of the map
	{
		it->second->menge += amount_to_increment; //the iterators second argument is the Product Pointer which we use to increase the stored amount
	}
	else
	{
		SWESoftware::Produkt* newProduct = new Produkt(product_name, amount_to_increment, lagerort, SWE_EAN); //Allocates the new product on the heap
		lager_from_int.insert(std::pair<int, Produkt*>(SWE_EAN, newProduct)); //and inserts it into the map
	}
}
void SWESoftware::Lager::add_to_lager(int SWE_EAN, std::string product_name, int amount_to_increment, std::string lagerort)
{
	std::map<int, SWESoftware::Produkt*>::iterator it = lager_from_int.find(SWE_EAN); //finds the product in the map
	if (it != lager_from_int.end())	//do this if the given iterator isnt the end of the map
	{
		it->second->menge += amount_to_increment; //the iterators second argument is the Product Pointer which we use to increase the stored amount
	}
	else
	{
		SWESoftware::Produkt *newProduct = new Produkt(product_name, amount_to_increment, lagerort, SWE_EAN); //Allocates the new product on the heap
		lager_from_int.insert(std::pair<int, Produkt*>(SWE_EAN, newProduct)); //and inserts it into the map
	}
}

bool SWESoftware::Lager::DecrementProdukt(int SWE_EAN, int amount_to_decrement)
{
	std::map<int, SWESoftware::Produkt*>::iterator it = lager_from_int.find(SWE_EAN); //finds the product in the map
	if (it != lager_from_int.end())	//do this if the given iterator isnt the end of the map
	{
		it->second->menge -= amount_to_decrement; //the iterators second argument is the Product Pointer which we use to decrease the stored amount
		return true;
	}
	return false;
}

//Lager
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Produkt
SWESoftware::Produkt::Produkt(std::string name, int menge, std::string lagerort, int SWE_EAN)
{
	this->name = name;
	this->menge = menge;
	this->lagerort = lagerort;
	this->SWE_EAN = SWE_EAN;
}

SWESoftware::Produkt::~Produkt() {  }

//Produkt
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lieferand

SWESoftware::Lieferand::Lieferand(std::string name, std::vector<Produkt*>produktangebot)
{
	this->name = name;
	this->produktangebot = produktangebot;
}

SWESoftware::Lieferand::~Lieferand() { delete(this); }



bool SWESoftware::Lieferanden_Liste::saveLieferandenToFile()
{
	//locates the users document folder and saves its path to target_path
	PWSTR PWSTRappData_path = NULL;
	SHGetKnownFolderPath(FOLDERID_Documents, NULL, NULL, &PWSTRappData_path);
	std::filesystem::path target_path = std::filesystem::path(PWSTRappData_path);
	std::filesystem::path target_folderpath = std::filesystem::path(PWSTRappData_path);
	std::filesystem::path target_filepath = std::filesystem::path(PWSTRappData_path);

	target_folderpath = (target_path.string()) + std::string("\\SWE-Software");
	target_filepath = (target_folderpath.string()) + std::string("\\savestate.txt");


	bool found = false;

	checkSavefile();

	std::ifstream  inputfile;
	inputfile.open(std::filesystem::directory_entry(target_filepath), std::ifstream::in);
	if (inputfile.rdstate() != std::ios_base::goodbit)
		return false;

	if (inputfile.good() && inputfile) // optional: filecontent as target
	{
		std::string checkedString;
		std::vector<std::string> vecOfStr; //File Content as Vector of Strings

		while (std::getline(inputfile, checkedString)) // Every line of the inputfile gets its own string in the vector
		{
			vecOfStr.push_back(checkedString);
		}
		inputfile.close();

		auto itPos = vecOfStr.begin();
		//std::map<int, Produkt*>::iterator LagerIter;
		// checks every string of the vector if its the desired context eg "Lager{", then it erases everything until it finds an "}Lager" from which it inserts all each product detail into its own row
		for (auto it = std::begin(vecOfStr); it != std::end(vecOfStr); ++it)
		{
			if (!found && *it == "Lieferanden{")
			{
				if (itPos + 1 != vecOfStr.end())
					itPos++;
				found = true;
				continue;
			}
			else if (!found)
			{
				if (itPos + 1 != vecOfStr.end())
					itPos++;
				continue;
			}

			if (*it == "}Lieferanden")
			{
				for (auto const& x : vec_Lieferanden_Liste) {
					std::string to_insert = "";
					to_insert += (x->name) + ";";
					for (auto const& y : x->produktangebot)
					{
						to_insert += "(";
						to_insert += std::to_string(y->SWE_EAN) + ";";
						to_insert += y->name + ";";
						to_insert += std::to_string(y->menge) + ";";
						to_insert += y->lagerort;
						to_insert += ")";

					}
					to_insert += ";;";			
					vecOfStr.insert(std::find(vecOfStr.begin(), vecOfStr.end(), "}Lieferanden"), to_insert);
				}
				break;
			}
			else
			{
				it->erase(); // clears a line of info in the vector
				continue;
			}

		}
		vecOfStr.erase(std::remove_if(vecOfStr.begin(), vecOfStr.end(), isEmptyOrBlank), vecOfStr.end()); //erases empty lines in th vector



		std::ofstream  outputfile;


		//creates a new file inside of the before created folder
		outputfile.open(target_filepath.string(), std::ofstream::out | std::ofstream::trunc);

		//Inserts the vectors content into the outputfile
		for (auto it = std::begin(vecOfStr); it != std::end(vecOfStr); ++it) {
			outputfile << *it << "\n";
		}



		outputfile.close();
		return true;
	}
}


SWESoftware::Lieferanden_Liste::Lieferanden_Liste(Lieferand *neuerLieferand)
{
	this->vec_Lieferanden_Liste.push_back(neuerLieferand);
}

SWESoftware::Lieferanden_Liste::~Lieferanden_Liste()
{
}
//Lieferand
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Bestellung
SWESoftware::Bestellung::Bestellung(Lieferand* derLieferand, std::vector<Produkt*> produkte_in_dieser_bestellung)
{
	this->derLieferand = derLieferand;
	this->produkte_in_dieser_bestellung = produkte_in_dieser_bestellung;
}
