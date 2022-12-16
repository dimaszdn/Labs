#pragma once
#include<string>
#include<vector>
#include "City.hpp"

class Country
{
private:
	std::string m_title;
	int m_populace;
	std::vector<City* > citys;

public:
	Country(std::string title);

	~Country();

	void addCity(City* city);

	void populace();

	void printCity();

	void printPopulace();
};