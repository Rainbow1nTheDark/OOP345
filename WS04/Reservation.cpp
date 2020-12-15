//NAME: Alexander Balandin
//ID: 132145194
//DATE: 10/19/2020
#define _CTR_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"
using namespace std;
namespace sdds {
	Reservation::Reservation()
	{
	
		numOfPeople = 0u;
		day = 0u;
		hour = 0u;

	}

	Reservation::Reservation(const std::string& res)
	{
		if (res.length() != 0) {
			//delete white spaces
			string newRes = res;
			newRes.erase(std::remove_if(newRes.begin(), newRes.end(), ::isspace), newRes.end());
			std::string::size_type end = newRes.find(':');
			std::string::size_type start = 0;
			reservationID = newRes.substr(start, end);
			start = end +1;
			end = newRes.find(',', start);
			nameOfRes = newRes.substr(start, end - start);
			start = end + 1;
			end = newRes.find(',', start);
			email = newRes.substr(start, end - start);
			start = end + 1;
			end = newRes.find(',', start);
			numOfPeople = std::stoi(newRes.substr(start, end - start));
			start = end + 1;
			end = newRes.find(',', start);
			day = stoi(newRes.substr(start, end - start));
			hour = stoi(newRes.substr(++end));
		}
		else {
		
			numOfPeople = 0u;
			day = 0u;
			hour = 0u;
		}
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& res)
	{
		os << "Reservation " << res.reservationID << ": " << setw(10) << right  << res.nameOfRes  << left << "  <" << setw(22) <<  res.email+'>' << right;
		if (res.hour >= 6 && res.hour <= 9) os << " Breakfast";
		else if (res.hour >= 11 && res.hour <= 15) os << " Lunch";
		else if (res.hour >= 17 && res.hour <= 21) os << " Dinner";
		else os << " Drinks";
		os << " on day " << res.day << " @ " << res.hour << ":00 for " << res.numOfPeople << " people." << endl;
		return os;
	}
}