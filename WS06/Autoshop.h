//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <list>
#include <vector>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicle;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			
				for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
					if (test(*i))
					{
						vehicles.push_back(*i);
					}
				}
			
		}
		~Autoshop();
	};
}
#endif
