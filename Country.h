//David Tyler Gosbee
//201905838
//x2019fep@stfx.ca
#pragma once
#include <string>

class Country
{

private:
	std::string _name;//Name of the Country
	int _pop;//Population of the Country
	double _area;//Area of the Country
	std::string _continent;//Continent of the population


public:
	Country();
	Country(std::string name, int pop, double area, std::string continent);
	~Country();

	std::string getName();
	int getPopulation();
	double getArea();
	std::string getContinent();
	double getPopulationDensity();

	void setPopulation(int newPop);

	std::string to_string();

};