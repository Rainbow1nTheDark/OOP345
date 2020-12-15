//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>
const size_t MAX_ARRAY = 5;
namespace sdds {
	class SpellChecker
	{
		std::string m_badWords[MAX_ARRAY];
		std::string m_goodWords[MAX_ARRAY];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}
#endif

