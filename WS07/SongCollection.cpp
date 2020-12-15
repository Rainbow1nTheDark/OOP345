#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "SongCollection.h"
namespace sdds {
	SongCollection::SongCollection(const std::string& fileName)
	{
		std::fstream file(fileName);
		if (!file)
			throw("Cannot open file");
		while (file)
		{
			Song song;
			std::string line{}, str{};
			const size_t strLength = 25, numLength = 5;
			size_t start = 0;
			std::getline(file, line, '\n');
			if (line != "") {
				// for TITLE, ARTIST, and ALBUM
				auto get_25_lengthStr = [&]() {
					str = line.substr(start, strLength);
					while (str[0] == ' ')
						str.erase(0, 1);
					while (str[str.length() - 1] == ' ')
						str.erase(str.length() - 1, 1);
					start += strLength;
				};
				//for YEAR, LENGTH, PRICE
				auto get_5_lengthNo = [&]() {
					str = line.substr(start, numLength);
					size_t isEmpty = str.find_first_not_of(' ');
					if (isEmpty != std::string::npos)
					{
						while (str[0] == ' ')
							str.erase(0, 1);
						while (str[str.length() - 1] == ' ')
							str.erase(str.length() - 1, 1);
					}
					start += numLength;
				};

				get_25_lengthStr();
				song.m_title = str;

				get_25_lengthStr();
				song.m_artist = str;

				get_25_lengthStr();
				song.m_album = str;

				get_5_lengthNo();
				song.m_year = str;

				get_5_lengthNo();
				song.m_songLength = std::stoi(str);

				get_5_lengthNo();
				song.m_price = std::stod(str);

				songList.push_back(song);
			}
		}
		//close file
		file.close();
	}

	void SongCollection::display(std::ostream& out) const
	{
		std::for_each(songList.begin(), songList.end(), [&out](Song item) {
			out << item;
			out << std::endl;
			});
		size_t totalLength = 0;
		std::for_each(songList.begin(), songList.end(), [&totalLength](Song item)
			{
				totalLength += item.m_songLength;
			});
		size_t hours = totalLength / 60 / 60;
		size_t min = totalLength / 60 - (hours * 60);
		size_t sec = totalLength - (min * 60 + hours * 60 * 60);
		out << "----------------------------------------------------------------------------------------\n";
		out << "|" <<std::right << std::setw(78) << "Total Listening Time: " << hours << ":" << min << ":" << sec << " |\n";

	}

	void SongCollection::sort(const std::string& field)
	{
		std::sort(songList.begin(), songList.end(), [field](Song& song1, Song& song2)
			{
				if (field == "title")
					return song1.m_title < song2.m_title;
				else if (field == "album")
					return song1.m_album < song2.m_album;
				else
					return song1.m_songLength < song2.m_songLength;
			});
	}

	void SongCollection::cleanAlbum()
	{
		std::for_each(songList.begin(), songList.end(), [](Song& item) {
			if (item.m_album == "[None]")
				item.m_album = "      ";
			});
	}

	bool SongCollection::inCollection(const std::string& artist) const
	{
		bool isInCollection = false;
		std::for_each(songList.begin(), songList.end(), [artist, &isInCollection](Song item) {
			if (item.m_artist == artist)
				isInCollection = true;
			});
		return isInCollection;
	}

	std::list<Song> SongCollection::getSongsForArtist(const std::string& artist) const
	{
		std::list<Song> listOfSongs;
		std::for_each(songList.begin(), songList.end(), [artist, &listOfSongs](Song item) {
			if(item.m_artist == artist)
				listOfSongs.push_back(item);
			});
		return listOfSongs;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		size_t min = theSong.m_songLength / 60;
		size_t sec = theSong.m_songLength - min * 60;
		out << "| " << std::left << std::setw(20) << theSong.m_title << " | "
			<< std::setw(15) << theSong.m_artist << " | "
			<< std::setw(20) << theSong.m_album << " | "
			<< std::setw(6) << std::right << theSong.m_year << " | "
			<< min << ":" << ((sec >= 10) ? std::to_string(sec) : ("0" + std::to_string(sec))) << " | "
			<< theSong.m_price << " |";
		return out;
	}

	Song::Song()
	{
		m_artist = {};
		m_title = {};
		m_album = {};
		m_price = 0;
		m_year = {};
		m_songLength = 0;
	}
}