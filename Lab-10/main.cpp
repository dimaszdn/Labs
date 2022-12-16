#include<iostream>
#include<string>
#include<vector>
#include "City.hpp"
#include "Country.hpp"

int main()
{
	setlocale(LC_ALL, "RUS");
	
	Country* country1 = new Country("England");
	City* city1 = new City("London", 10000);
	City* city2 = new City("Birmingem", 1068);
	City* city3 = new City("Liverpool", 441);

	country1->addCity(city1);
	country1->addCity(city2);
	country1->addCity(city3);

	country1->populace();
	
	country1->printPopulace();
	
	country1->printCity();

	delete country1;
	delete city1;
	delete city2;
	delete city3;

	return 0;
}