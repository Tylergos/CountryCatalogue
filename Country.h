#pragma once
#include <string>

class Country
{

private:
	std::string _name;
	int _pop;
	double _area;
	std::string _continent;


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

