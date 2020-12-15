//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/10/2020
//EMAIL: abalandin@myseneca.ca#pragma once
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds {
	template<typename T, size_t N>
	class SetSummable : public Set<T, N>
	{

	public:
        T accumulate(const std::string& filter) const
        {
            T sum(filter);
            for (size_t i = 0; i < this->size(); i++)
            {
                sum += (*this)[i];
            }
            return sum;
        }
	};
}

#endif