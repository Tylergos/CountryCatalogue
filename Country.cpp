//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca


#include "Country.h"


	Country::Country()
	{
		//Default constructor sets up Country object with default parameters
		_name = "DEFAULT";
		_pop = 0;
		_area = 0;
		_continent = "DEFAULT";
	}

	Country::Country(std::string name, int pop, double area, std::string continent)
	{
		//Constructor sets up Country object with parameters input
		_name = name;
		_pop = pop;
		_area = area;
		_continent = continent;
	}

	Country::~Country()
	{
		// No need for anything
	}

	std::string Country::getName()
	{
		//returns the name of the Country
		return _name;
	}

	int Country::getPopulation()
	{
		//returns the population of the Country
		return _pop;
	}

	double Country::getArea()
	{
		//returns the area of the Country
		return _area;
	}

	std::string Country::getContinent()
	{
		//returns the continent of the Country
		return _continent;
	}

	double Country::getPopulationDensity()
	{
		//returns the population density of the Country
		return _pop / _area;
	}

	void Country::setPopulation(int newPop)
	{
		//sets the population of the Country
		_pop = newPop;
	}

	std::string Country::to_string()
	{
		//returns a string form of the Country object
		return _name + " in " + _continent;
	}
