#pragma once

#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <string>

#include "Country.h"

class CountryCatalogue
{
private:
	int _maxSize;
	int _curSize;
	Country** _catalogue;
	std::map<std::string, std::string> _countryContinent;
    
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

