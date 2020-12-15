//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
namespace sdds {
	
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		template<typename T>
		void fixSpelling(T spellCheacker) {
			spellCheacker(m_description);
			spellCheacker(m_title);

		}
		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}
#endif

