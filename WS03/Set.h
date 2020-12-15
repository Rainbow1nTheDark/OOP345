//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/10/2020
//EMAIL: abalandin@myseneca.ca
#ifndef  SDDS_SET_H
#define SDDS_SET_H
namespace sdds {
	template<typename T, size_t N>
	class Set {
	private:
		T array[N];
		size_t sizeOf;
	public:
		Set() {
			sizeOf = 0;
		}
		size_t size() const {
			return sizeOf;
		}
		const T& operator[](size_t idx) const {
			return array[idx];
		}
		void operator+=(const T& item) {
			if (sizeOf < N) {
				
				array[sizeOf] = item;
				sizeOf++;
			}
		}
		
	};
	


}


#endif //  SET_H

