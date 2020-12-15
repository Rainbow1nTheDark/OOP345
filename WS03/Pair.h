//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/10/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
namespace sdds {
	template<typename K, typename V>
	class Pair {
		K keyV;
		V valueV;
	public:
		Pair() {
			
		}
		Pair(const K& key, const V& value) {
			this->keyV = key;
			this->valueV = value;
		}
		const K& key() const {
			return keyV;
		}
		const V& value() const {
			return valueV;
		}
		virtual void display(std::ostream& os) const {
			os << this->keyV << " : " << this->valueV << '\n';
		}
		
};
	template<typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {

		pair.display(os);
		return os;
	}
}
#endif
