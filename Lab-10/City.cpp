#include "City.hpp"
#include<string>


City::City(std::string title, int countPeople)
{
	m_title = title;
	m_countPeople = countPeople;
}

City::~City() {}

int City::retCountPeople()
{
	return m_countPeople;
}

std::string City::retTitle()
{
	return m_title;
}
