//NAME: Alexander Balandin
//ID: 132145194
//DATE: 10/19/2020
#include "ConfirmationSender.h"

namespace sdds {
	ConfirmationSender::ConfirmationSender() : reserv{nullptr}
	{
		count = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) noexcept
	{
		count = cs.count;
		reserv = new const Reservation*[cs.count];
		for (auto i = 0u; i < cs.count; i++)
		{
			reserv[i] = cs.reserv[i];
		}
	}
	ConfirmationSender::ConfirmationSender( ConfirmationSender&& cs) noexcept
	{
		*this = std::move(cs);
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] this->reserv;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res)noexcept
	{
		if (res.reserv != nullptr)
		{
			delete[] this->reserv;
			
			for (auto i = 0u; i < res.count; i++)
			{
				reserv[i] = res.reserv[i];
			}
			count = res.count;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res) noexcept
	{
		if (this != &res) {
			/*delete[] this->reserv;*/
			this->reserv = res.reserv;
			res.reserv = nullptr;
			count = res.count;

		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool found = false;
		for (auto i = 0u; i < count; i++)
		{
			if (reserv[i] == &res) {
				found = true;
				//break the loop
				i = count;
			}

		}
		if (!found) {
			const Reservation** temp = nullptr;
			temp = new const Reservation * [count+1];
			
			for (auto i = 0u; i < count; i++)
			{
				temp[i] = reserv[i];
			}
			
			count++;
			temp[count - 1] = &res;
			delete[] reserv;
			reserv = temp;
			temp = nullptr;
		}

		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool found = false;
		for (auto i = 0u; i < count; i++) {
			if (reserv[i] == &res) {
				
				reserv[i] = nullptr;
			}
		}
		if (found) {
			bool detected = false;
			const Reservation** temp = nullptr;
			temp = new const Reservation* [count - 1];
			
			for (auto i = 0u; i < count; i++)
			{
				if (reserv[i] != nullptr && !detected) {
					temp[i] = reserv[i];
				}
				else if(detected){
					temp[i - 1] = reserv[i];
				}
				else {
					detected = true;
				}
			}
			count--;
			reserv = temp;
			temp = nullptr;
		}
		return *this;

	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs)
	{
		os << "--------------------------\nConfirmations to Send\n--------------------------\n";
		if (cs.reserv == nullptr)
			os << "The object is empty!\n--------------------------\n";
		else {
			for (auto i = 0u; i < cs.count; i++)
			{
				if(cs.reserv[i] != nullptr)
					os << *cs.reserv[i];
			}
			os << "--------------------------\n";
		}
		return os;
	}
}