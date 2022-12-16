#include "Country.hpp"

#include<iostream>
#include<string>
#include<vector>


Country::Country(std::string title)
{
	m_title = title;
	m_populace = 0;
}

Country::~Country() {}

void Country::addCity(City* city)
{
	citys.push_back(city);
}

void Country::populace()
{
	for (int i = 0; i < citys.size(); ++i)
		m_populace += citys[i]->retCountPeople();
}

void Country::printCity()
{
	std::cout << "\nСтруктура страны: " << std::endl;
	for (int i = 0; i < citys.size(); ++i)
		std::cout << citys[i]->retTitle() << std::endl;
}

void Country::printPopulace()
{
	std::cout << "Количество населения: "
		<< m_populace << " тыс. человек." << std::endl;
}
