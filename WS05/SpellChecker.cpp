//Name: Alexander Balandin
//ID: 132145194
//DATE: 10/28/2020
//EMAIL: abalandin@myseneca.ca
#include <fstream>
#include <iostream>
#include "SpellChecker.h"

sdds::SpellChecker::SpellChecker(const char* filename)
{
	std::fstream file(filename);
	if (file) {
		size_t i = 0;
		while (file && i < MAX_ARRAY)
		{
			std::string word;
			std::getline(file, word);
			
				std::string::size_type end = word.find(" ");
				std::string::size_type start = 0;
				m_badWords[i] = word.substr(start, end - start);
				start = word.find_first_not_of(" ", end);
				m_goodWords[i] = word.substr(start);
				i++;
			
		}
		file.close();
	}
	else
	{
		throw "Bad file name!";
	}
}

void sdds::SpellChecker::operator()(std::string& text) const
{
	
	for (auto i = 0u; i < MAX_ARRAY; i++)
	{
		
		size_t ind = text.find(m_badWords[i]);
		while (ind != std::string::npos)
		{
			ind = text.find(m_badWords[i]);
			text.replace(ind, m_badWords[i].length(), m_goodWords[i]);
			ind = text.find(m_badWords[i]);
		}
	}
}
