//Name: Alexander Balandin
//ID: 132145194
//DATE: 11/8/2020
//EMAIL: abalandin@myseneca.ca
#include <sstream>
#include "Car.h"
#include "Racecar.h"
#include "Utilities.h"
namespace sdds {
    Vehicle* createInstance(std::istream& in)
    {
        Vehicle* vehicle = nullptr;
        
        std::string line{};
        std::string vehicleType{};
        std::getline(in, line, '\n');
        std::stringstream sStream(line);
        sStream >> vehicleType;
        if (vehicleType[0] == 'C' || vehicleType[0] == 'c')
        {
            vehicle = new Car(sStream);
            
        }
        else if(vehicleType[0] == 'r' || vehicleType[0] == 'R')
        {
            vehicle = new Racecar(sStream);
        }
        else if(isalpha(vehicleType[0])){
            vehicleType.erase(1, 1);
            throw("Unrecognized record type: [" + vehicleType + "]");
            
        }
        else {
            return nullptr;
        }
        return vehicle;
    }
}
