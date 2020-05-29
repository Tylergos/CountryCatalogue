//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca
#include "CountryCatalogue.h"
#include <iostream>
#include <fstream>

CountryCatalogue::CountryCatalogue()
{
	//Default constructor generates an array with a size of 10 of Country objects
	_maxSize = 10;
	_curSize = 0;
	_catalogue = new Country*[_maxSize];
}

CountryCatalogue::CountryCatalogue(std::string continentFileName, std::string countryFileName)
{
	//Constructor that generates a map with countries and their continents and an array with
	//Country objects

	//Open up the files
	std::ifstream continentFile;
	std::ifstream countryFile;
	continentFile.open(continentFileName);
	countryFile.open(countryFileName);


	// Read the continent file
	// While there is still stuff to read in the file
	std::string line[3];
	_maxSize = 0;
	while (std::getline(continentFile, line[0]))
	{
		std::cout << line[0];
		// Read the 2nd line
		std::getline(continentFile, line[1]);

		// Add the country/continent to the map
		_countryContinent.insert(std::make_pair(line[0], line[1]));

		// Keep track of how many countries there will be
		_maxSize++;
	}

	// close file
	continentFile.close();

	// make the array and set _curSize
	_catalogue = new Country*[_maxSize];
	_curSize = 0;

	// Read the country file
	// While there is still stuff to read in the file
	while (std::getline(countryFile, line[0]))
	{
		// Read lines 2 and 3
		std::getline(countryFile, line[1]);
		std::getline(countryFile, line[2]);

		// Add the country to the catalogue
		addCountry(line[0], std::stoi(line[1]), std::stod(line[2]), _countryContinent[line[0]]);
	}
	// close file
	countryFile.close();
}

CountryCatalogue::~CountryCatalogue()
{
	//Deconstructor which deletes both the Country objects created and the array containing them
	for (int i = 0; i < _curSize; i++)
	{
		delete _catalogue[i];
	}
	delete[] _catalogue;
}

void CountryCatalogue::expandCapacity()
{
	//doubles the capacity of the Country array
	_maxSize *= 2;
	Country** temp = new Country*[_maxSize];
	for (int i = 0; i < _curSize; i++)
	{
		temp[i] = _catalogue[i];
	}
	delete[] _catalogue;
	_catalogue = temp;
}

void CountryCatalogue::addCountry(std::string name, int pop, double area, std::string continent)
{
	//Creates and adds a Country object to the Country array
	if (_curSize >= _maxSize) 
	{
		expandCapacity();
	}
	Country* country = new Country(name, pop, area, continent);
	CountryCatalogue::_countryContinent.insert(std::make_pair(name, continent));
	_catalogue[_curSize] = country;
	_curSize++;
}

void CountryCatalogue::removeCountry(std::string name)
{
	//Removes the Country from the Country array and adjusts the array
	//to prevent empty indexes
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getName() == name) 
		{
			delete _catalogue[i];
			_catalogue[i] = _catalogue[_curSize];
			_curSize--;
		}
	}
}

Country* CountryCatalogue::findCountry(std::string name)
{
	//Finds the Country object in the Country array and returns the pointer, if the
	//Country is not found, returns nullptr
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getName() == name)
		{
			return _catalogue[i];
		}
	}
	return nullptr;
}

int CountryCatalogue::numCountriesInContinent(std::string continentName)
{
	//returns the number of Countries in the continent
	int count = 0;
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getContinent() == continentName)
		{
			count++;
		}
	}
	return count;
}

Country** CountryCatalogue::filterCountriesByContinent(std::string continentName, int num)
{
	//Returns an array of Country objects in a continent, if no Country objects are found
	//returns null pointer
	Country** countries = new Country*[num];
	int count = 0;
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getContinent() == continentName)
		{
			countries[count] = _catalogue[i];
			count++;
		}
	}
	if (count == 0)
	{
		delete[] countries;
		return nullptr;
	}
	return countries;
}

void CountryCatalogue::printCountryCatalogue()
{
	//Prints the Countries in the Country array
	for (int i = 0; i < _curSize; i++)
	{
		std::cout << _catalogue[i]->to_string() << std::endl;
	}
}

void CountryCatalogue::setPopulationOfSelectedCountry(std::string name, int pop)
{
	//Sets the population of the Country object
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getName() == name)
		{
			_catalogue[i]->setPopulation(pop);
			break;
		}
	}
}

Country* CountryCatalogue::findCountryWithLargestPop()
{
	//Finds the Country object with the largest population
	int max = -1;
	Country* largestPop = nullptr;
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getPopulation() > max)
		{
			largestPop = _catalogue[i];
			max = _catalogue[i]->getPopulation();
		}
	}
	return largestPop;
}

Country* CountryCatalogue::findCountryWithSmallestArea()
{
	//Finds the Country object with the smallest area
	double min = INFINITY;
	Country* smallestCountry = nullptr;
	for (int i = 0; i < _curSize; i++)
	{
		if (_catalogue[i]->getArea() < min)
		{
			smallestCountry = _catalogue[i];
			min = _catalogue[i]->getArea();
		}
	}
	return smallestCountry;
}

std::string CountryCatalogue::findMostPopulousContinent()
{
	//Finds the Continent with the largest population and returns the string of the continent
	std::map<std::string, int> continentPop;
	int max = -1;
	std::string maxContinent;
	for (int i = 0; i < _curSize;i++)
	{
		//if the Continent is already in the map, add the population of the new country
		if (continentPop.count(_catalogue[i]->getContinent()) > 0)
		{
			continentPop.at(_catalogue[i]->getContinent()) += _catalogue[i]->getPopulation();
			//If the Continents population is larger than the max, set the max as the new
			//maximum, and the maxContinent as the continent
			if (continentPop.at(_catalogue[i]->getContinent()) > max)
			{
				max = continentPop.at(_catalogue[i]->getContinent());
				maxContinent = _catalogue[i]->getContinent();
			}
		}
		//If the continent is not yet in the map, add it to the map
		else
		{
			continentPop.insert(std::make_pair(_catalogue[i]->getContinent(), _catalogue[i]->getPopulation()));
			//If the Continents population is larger than the max, set the max as the new
			//maximum, and the maxContinent as the continent
			if (continentPop.at(_catalogue[i]->getContinent()) > max)
			{
				max = continentPop.at(_catalogue[i]->getContinent());
				maxContinent = _catalogue[i]->getContinent();
			}
		}
	}

	return maxContinent;
}

int CountryCatalogue::saveCountryCatalogue(std::string outputFileName)
{
	//Saves the Country array as a file and returns the number of lines printed
	std::ofstream fileOut;
	fileOut.open(outputFileName);
	fileOut << "NAME|CONTINENT|POPULATION|POPULATIONDENSITY \n";
	int count = 0;
	while (count < _curSize)
	{
		fileOut << _catalogue[count]->getName() + "|" + _catalogue[count]->getContinent() + "|" + std::to_string(_catalogue[count]->getPopulation()) + "|" + std::to_string(_catalogue[count]->getPopulationDensity()) + "\n";
		count++;
	}
	fileOut.close();
	return count;
}