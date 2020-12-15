//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#include <iomanip>
#include "Movie.h"
namespace sdds {
	sdds::Movie::Movie()
	{
		m_year = 0;
	}

	sdds::Movie::Movie(const std::string& strMovie)
	{
		std::string stringMovie = strMovie;

		std::string::size_type end = strMovie.find(",");
		std::string::size_type start = 0;
		while (stringMovie[end - 1] == ' ')
		{
			stringMovie.erase(end - 1, 1);
			end--;
		}
		while (stringMovie[start] == ' ')
		{
			stringMovie.erase(start, 1);
			end--;
		}
		m_title = stringMovie.substr(start, end);
		stringMovie.erase(start, end - start);

		start = stringMovie.find_first_not_of(" ,");
		end = stringMovie.find(',', start);
		while (stringMovie[end - 1] == ' ')
		{
			stringMovie.erase(end - 1, 1);
			end--;
		}

		m_year = std::stoi(stringMovie.substr(start, end - start));
		stringMovie.erase(start, end - start);

		start = stringMovie.find_first_not_of(" ,");
		end = stringMovie.find('.', start);
		m_description = stringMovie.substr(start, end + 1 - start);




	}

	const std::string& sdds::Movie::title() const
	{
		return m_title;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << std::right << std::setw(40) << movie.m_title << " | ";
		os << std::setw(4) << movie.m_year << " | ";
		os << movie.m_description << std::endl;
		return os;
	}
}