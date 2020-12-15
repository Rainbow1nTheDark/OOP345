//NAME: Alexander Balandin
//ID: 132145194
//DATE: 10/19/2020
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds {
	class Restaurant
	{
		Reservation* reservation{ nullptr };
		size_t numOfRes;
	public:
		Restaurant(Restaurant& reservation) noexcept;
		Restaurant(Restaurant&& reservation) noexcept;
		Restaurant(Reservation* reservations[], size_t cnt) ;
		Restaurant& operator=(Restaurant& res) noexcept;
		Restaurant& operator=(Restaurant&& res) noexcept;
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif

