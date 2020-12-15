//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/10/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iomanip>
#include "Pair.h"
namespace sdds {
	template<typename K, typename V>
	class PairSummable : public Pair<K, V>
	{
		static V initial;
		static size_t width;
	public:
		PairSummable() { width = 0u; }
		PairSummable(const K& key, const V& value = initial) : Pair<K, V>::Pair(key, value)
		{
			if (width < key.size()) {
				width = key.size();
			}
		}
		PairSummable& operator+=(const PairSummable& pairSum) {
			if (this->key() == pairSum.key() && this != &pairSum) {
				*this = PairSummable(Pair<K, V>::key(), Pair<K, V>::value() + pairSum.value());
			}
			return *this;
		}
		void display(std::ostream& os) const
		{
			os << std::left << std::setw(width);
			Pair<K, V>::display(os);
			os << std::right;
		}

	};
	template <typename K, typename V> 
	size_t PairSummable<K, V>::width = 0;



	template <>

	std::string PairSummable<std::string, std::string>::initial = std::string("");


	template <>

	int PairSummable<std::string, int>::initial = 0;


	template <>

	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string >& b)

	{

		if (this != &b && Pair<std::string, std::string>::key() == b.key())

			*this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string >::value() == "" ? b.value() : Pair<std::string, std::string>::value() + ", " + b.value());

		return *this;

	}
}
#endif
