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
		Produkt(std::string name, int menge, std::string lagerort, int SWE_EAN = 0);
		~Produkt();
		std::string name = "";
		int menge = 0;
		std::string lagerort;
		int SWE_EAN = 0;
		

	private:

	};

	class Lager
	{

	private:


	public:

		Lager(std::map<int, Produkt*> lager_from_int, std::vector<std::string>lagerplaetze = {});
		~Lager();

		std::map<int, Produkt*> lager_from_int = {};
		std::vector <std::string> lagerplaetze = {};

		std::map<int, Produkt*> get_lager() { return lager_from_int; }
		
		void add_to_lager(SWESoftware::Produkt product_to_add);

		void add_to_lager(int SWE_EAN, std::string product_name, int amount_to_increment, std::string lagerort);
		bool saveLagerToFile();
		bool DecrementProdukt(int SWE_EAN, int amount_to_decrement);

		
	};

	class Lieferand
	{
	public:
		Lieferand(std::string name, std::vector<Produkt*>produktangebot = {});
		~Lieferand();
		std::string name = "";
		std::vector<Produkt*>produktangebot = {};
	private:

	};

	class Lieferanden_Liste
	{
	public:
		Lieferanden_Liste(Lieferand *neuerLieferand);
		~Lieferanden_Liste();
		std::vector<Lieferand* >vec_Lieferanden_Liste = {};
		bool saveLieferandenToFile();
	private:

	};


	



	class Bestellung
	{
	public:

		Bestellung(Lieferand* derLieferand=nullptr, std::vector<Produkt*> produkte_in_dieser_bestellung = {});
		~Bestellung();


	private:
		Lieferand * derLieferand = nullptr;
		std::vector<Produkt*> produkte_in_dieser_bestellung ={};

	};

}

