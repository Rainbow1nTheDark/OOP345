#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <string>
#include <list>
#include <vector>
namespace sdds {
	struct Song;
	class SongCollection {
		std::vector<Song> songList;
	public:
		SongCollection() {}
		SongCollection(const std::string& fileName);
		void display(std::ostream& out) const;
		void sort( const std::string& field);
		void cleanAlbum();
		bool inCollection(const std::string& artist) const;
		std::list<Song> getSongsForArtist(const std::string& artist) const;

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		std::string m_year;
		size_t m_songLength;
		Song();
	};

}
#endif
