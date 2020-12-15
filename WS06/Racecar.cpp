//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#include <sstream>
#include <string>
#include "Racecar.h"
namespace sdds
{


	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string line{};
		std::getline(in, line);
		m_booster = std::stod(line);
	}
	void Racecar::display(std::ostream& out) const
	{
		
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (m_booster + 1);
	}

}