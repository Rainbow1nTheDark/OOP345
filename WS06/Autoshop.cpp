//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#include "Autoshop.h"
namespace sdds {
    Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)
    {
        m_vehicle.push_back(theVehicle);
        return *this;
    }
    void Autoshop::display(std::ostream& out) const
    {
        out << "--------------------------------\n";
        out << "| Cars in the autoshop!        |\n";
        out << "--------------------------------\n";
        
        for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
            (*i)->display(out);
            out << '\n';
        }
        out << "--------------------------------\n";
    }
    Autoshop::~Autoshop()
    {
        for (auto i = m_vehicle.begin(); i != m_vehicle.end(); i++) {
            delete (*i);
        }
    }
}