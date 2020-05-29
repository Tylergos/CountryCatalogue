//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca
#pragma once
#include <string>
#include <map>
#include "Country.h"


class CountryCatalogue
{
private:
	int _maxSize;//The maximum size of the array
	int _curSize;//the current amount of Country objects in the array
	Country** _catalogue;//Array of Country objects
	std::map<std::string, std::string> _countryContinent;//map of Countries and respective Continents

	void expandCapacity();

public:
	CountryCatalogue();
	CountryCatalogue(std::string continentFileName, std::string countryFileName);
	~CountryCatalogue();

	void addCountry(std::string name, int pop, double area, std::string continent);
	void removeCountry(std::string name);
	Country* findCountry(std::string name);
	int numCountriesInContinent(std::string cotinentName);
	Country** filterCountriesByContinent(std::string cotinentName, int num);
	void printCountryCatalogue();
	void setPopulationOfSelectedCountry(std::string name, int pop);
	Country* findCountryWithLargestPop();
	Country* findCountryWithSmallestArea();
	std::string findMostPopulousContinent();
	int saveCountryCatalogue(std::string outputFileName);
};