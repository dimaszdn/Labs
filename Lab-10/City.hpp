#pragma once
#include<string>

class City
{
private:
	std::string m_title;
	int m_countPeople;

public:
	City(std::string title, int countPeople);

	~City();

	int retCountPeople();

	std::string retTitle();
};