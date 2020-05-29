#include "Country.h"

Country::Country()
{
	_name = "DEFAULT";
	_pop = 0;
	_area = 0;
	_continent = "DEFAULT";
}

Country::Country(std::string name, int pop, double area, std::string continent)
{
	// complete me
}

Country::~Country()
{
	// No need for anything
}

// fill in the rest based on the header