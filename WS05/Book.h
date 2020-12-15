#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#include <string>
namespace sdds {
	
	class Book
	{
	private:
		std::string author;
		std::string titleOfBook;
		std::string publicationCountry;
		size_t publicationYear;
		double bookPrice;
		std::string description;
	public:
		Book();
		template<typename T>
		void fixSpelling(T spellChecker) {
			spellChecker(description);
		}
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		friend std::ostream& operator<<( std::ostream& os, const Book& book);
	};
	
}
#endif

