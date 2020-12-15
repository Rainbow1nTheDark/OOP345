//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle
	{
	
		std::string m_marker;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car() {}
		Car(std::istream& istr);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		
	};
}

#endif