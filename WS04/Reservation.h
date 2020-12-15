//NAME: Alexander Balandin
//ID: 132145194
//DATE: 10/19/2020
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
namespace sdds {
	const int MAXID = 8;
	class Reservation
	{
		std::string reservationID;
		std::string nameOfRes;
		std::string email;
		size_t numOfPeople;
		size_t day;
		size_t hour;
	public:
		Reservation();
		Reservation(const std::string& res);
		friend std::ostream& operator << (std::ostream& os, const Reservation& res);
	};

}
#endif