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
	class Lager
	{


	private:
		std::map<int, std::string> lager_map_fromInt;
		std::map<std::string, std::string> lager_map_fromString;


		Lager();
		~Lager();

	public:
		bool saveToFile();
		void DecrementProdukt();

	};

	class Produkt
	{
	public:
		std::string name;
		int menge;
		std::string lagerort;
		Produkt();
		~Produkt();

	private:

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

