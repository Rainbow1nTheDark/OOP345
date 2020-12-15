//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#include <iostream>
#include <iomanip>
#include <climits>
#include <string>
#include "Car.h"
#include "Racecar.h"

sdds::Car::Car(std::istream& istr)
{
	std::string str{};
	size_t count = 0;
	auto removeNBSP = [&]()
	{

		std::getline(istr, str, ',');
		if(str == " " && count==0)
			std::getline(istr, str, ',');
		count++;
		if (str != "" && str != " ") {
			while (str[0] == ' ' || str[0] == ',')
				str.erase(0, 1);
			while (str[str.length() - 1] == ' ')
				str.erase((str.length() - 1), 1);
		}
	};

	
	removeNBSP();
	m_marker = str;

	removeNBSP();
	if (str[0] == 'n' || str == "" || str == " ")
		m_condition = "new";
	else if (str == "u")
		m_condition = "used";
	else if (str == "b")
		m_condition = "broken";
	else
		throw "Invalid record!";
	removeNBSP();
	m_topSpeed = std::stod(str);
	
}

std::string sdds::Car::condition() const
{
	return m_condition;
}

double sdds::Car::topSpeed() const
{
	return m_topSpeed;
}



void sdds::Car::display(std::ostream& out) const
{
	out << "| " << std::setw(10) << m_marker << " | ";
	out << std::setw(6) << std::left << m_condition << std::right <<  " | ";
	out << std::setw(6) << std::fixed << std::setprecision(2)  << topSpeed()  << " |";
}







