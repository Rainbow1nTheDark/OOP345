//NAME: Alexander Balandin
//ID: 132145194
//DATE: 10/19/2020
#include "Restaurant.h"
namespace sdds {
	Restaurant::Restaurant(Restaurant& reservation) noexcept
	{
		*this = reservation;
	}
	Restaurant::Restaurant(Restaurant&& reservation) noexcept
	{
		*this = std::move(reservation);
	}
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		this->numOfRes = cnt;
		this->reservation = new Reservation[cnt];
			for (auto i = 0u; i < cnt; i++)
			{
					reservation[i] = *reservations[i];
				
			}
		
	}
	Restaurant& Restaurant::operator=(Restaurant& res) noexcept
	{
		
			if (this->reservation != nullptr)
			{
				delete[] reservation;
				reservation = nullptr;
			}
			numOfRes = res.numOfRes;
			this->reservation = new Reservation[res.numOfRes];
			for (auto i = 0u; i < numOfRes; i++)
			{
				reservation[i] = res.reservation[i];

			
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& res) noexcept
	{
		if (this != &res) {
			delete[] this->reservation;
			this->reservation = res.reservation;
			this->numOfRes = res.numOfRes;
			res.reservation = nullptr;
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		if (this->reservation != nullptr)
		{
			delete[] reservation;
			reservation = nullptr;
		}
	}
	size_t Restaurant::size() const
	{
		return this->numOfRes;
	}
	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		 os << "--------------------------\nFancy Restaurant\n--------------------------\n";
		if (res.reservation == nullptr || res.numOfRes == 0)
		{
			os << "The object is empty!\n--------------------------\n";
		}
		else {
			for (auto i = 0u; i < res.numOfRes; i++)
			{
				os << res.reservation[i];
			}
			os << "--------------------------\n";
		}
		return os;
	}
}