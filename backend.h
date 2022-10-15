#pragma once
#include "includeHeader.h"
#include "frontend.h"

#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <filesystem>
#include <shlobj.h>


namespace SWESoftware {

	class Produkt
	{
	public:
		std::string name = "";
		int menge = 0;;
		std::string lagerort = "";
		Produkt(std::string name = "", int menge = 0, std::string lagerort = "");
		~Produkt();

	private:

	};

	class Lager
	{

	private:
		typedef std::map<int, Produkt*> lager_map_fromInt;
		lager_map_fromInt lager_from_int;
		typedef std::map<std::string, Produkt*> lager_map_fromString;
		lager_map_fromString lager_from_string;

		Lager();
		~Lager();

	public:
		void add_to_lager(std::string name = "", int menge = 0, std::string lagerort = "");
		bool saveToFile();
		void DecrementProdukt();

	};

	


	class Lieferer
	{
	public:
		

	private:
		std::string name;
		std::vector<Produkt>produktangebot={};
		Lieferer();
		~Lieferer();
	};
}

