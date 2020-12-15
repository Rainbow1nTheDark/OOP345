//NAME: Alexander Balandin
//ID: 132145194
//DATE: 10/19/2020
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender{
		const sdds::Reservation** reserv{ nullptr };
		size_t count;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cs) noexcept;
		ConfirmationSender(ConfirmationSender&& cs) noexcept;
		~ConfirmationSender();
		ConfirmationSender& operator=(const ConfirmationSender& res) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& res) noexcept;
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
	};
}
#endif

