//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#include <iomanip>
#include "Book.h"

namespace sdds {
	
	Book::Book()
	{
		bookPrice = 0;
		publicationYear = 0;
	}
	const std::string& Book::title() const
	{
		return this->titleOfBook;
	}
	const std::string& Book::country() const
	{
		return publicationCountry;
	}
	const size_t& Book::year() const
	{
		return publicationYear;
	}
	double& Book::price()
	{
		return bookPrice;
	}
	Book::Book(const std::string& strBook)
	{
		bookPrice = 0;
		publicationYear = 0;
		if (strBook.length() != 0)
		{

			std::string stringBook = strBook;
			
			std::string::size_type end = strBook.find(",");
			std::string::size_type start = 0;
			while (stringBook[end - 1] == ' ')
			{
				end--;
			}
			author = stringBook.substr(start, end);
			stringBook.erase(start, end - start);

			start = stringBook.find_first_not_of(" ,");
			end = stringBook.find(',', start);
			while (stringBook[end - 1] == ' ')
			{
				stringBook.erase(end - 1, 1);
				end--;
			}
			
			titleOfBook = stringBook.substr(start, end - start);
			stringBook.erase(start, end - start);
			
			start = stringBook.find_first_not_of(" ,");
			end = stringBook.find(',', start);
			while (stringBook[end - 1] == ' ')
			{
				stringBook.erase(end - 1, 1);
				end--;
			}
			publicationCountry = stringBook.substr(start, end - start);
			stringBook.erase(start, end - start);

			start = stringBook.find_first_not_of(" ,");
			end = stringBook.find(',', start);
			bookPrice = std::stod(stringBook.substr(start, end - start));
			stringBook.erase(start, end - start);

			start = stringBook.find_first_not_of(" ,");
			end = stringBook.find(',', start);
			publicationYear = std::stoi(stringBook.substr(start, end - start));
			stringBook.erase(start, end - start);

			start = stringBook.find_first_not_of(" ,");
			end = stringBook.find('.', start);
			description = stringBook.substr(start, end + 1 - start);

		}
		
		

	}
	std::ostream& operator<<(std::ostream& os, const Book& book)
	{
		os << std::right << std::setw(20) << book.author << " | ";
		os << std::right << std::setw(22) << book.titleOfBook << " | ";
		os << std::right << std::setw(5) << book.publicationCountry << " | ";
		os << std::setw(4) << book.publicationYear << " | ";
		os << std::right << std::setw(6) << std::fixed << std::setprecision(2) << book.bookPrice << " | ";
		os << book.description << std::endl;
		return os;
	}
}