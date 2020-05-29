// If using visual studio, 
// This can help you find memory leaks
// https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2017
//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h>  

#include <iostream>

#include "Country.h"
#include "CountryCatalogue.h"


int main()
{


	CountryCatalogue* cc = new CountryCatalogue("continent_cpp.txt", "country_cpp.txt");
	cc->printCountryCatalogue();
	
	// Find
	std::cout << cc->findCountry("Canada")->getName() << std::endl;

	// Add
	cc->addCountry("A", 1, 1, "B");
	std::cout << cc->findCountry("A")->getName() << std::endl;
	cc->printCountryCatalogue();

	// Remove
	cc->removeCountry("A");
	std::cout << (cc->findCountry("A") == nullptr) << std::endl;
	cc->printCountryCatalogue();

	// Filter continent 
	// Wouldn't need the num if we used a std::array
	int num = cc->numCountriesInContinent("Europe");
	Country** filtered = cc->filterCountriesByContinent("Europe", 2);
	for (int i = 0; i < num; i++)
	{
		std::cout << filtered[i]->to_string() << std::endl;
	}
	// We delete the array, but NOT the contents
	// The contents are pointers to the countries 
	// in the catalogue, so that must be left alone
	delete[] filtered;

	// Set Population
	int cPop = cc->findCountry("Canada")->getPopulation();
	std::cout << cPop << std::endl;
	cc->setPopulationOfSelectedCountry("Canada", cPop + 1);
	cPop = cc->findCountry("Canada")->getPopulation();
	std::cout << cPop << std::endl;

	// Largest Population, Smallest Area and Largest continent by area
	std::cout << cc->findCountryWithLargestPop()->getName() << std::endl;
	std::cout << cc->findCountryWithSmallestArea()->getName() << std::endl;
	std::cout << cc->findMostPopulousContinent() << std::endl;

	// Save
	std::cout << cc->saveCountryCatalogue("saved_a1_file.txt");

	// We're going to be good and delete 
	// the CountryCatalogue object from RAM
	delete cc;

	// If using visual studio, 
	// This can help you find memory leaks
	// (See top of this code)
	//_CrtDumpMemoryLeaks();

}

