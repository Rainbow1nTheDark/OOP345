//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"
namespace sdds {
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar() {}
		Racecar(std::istream & in);
		void display(std::ostream& out) const;
		double topSpeed() const;
		
	};
}
#endif
