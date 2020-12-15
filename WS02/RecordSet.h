//Name: Alexander Balandin
//ID : 132145194
//Email : abalandin@myseneca.ca
//Date : 10 / 03 / 2020
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_RECORDSET_H
#define SDDS_RECORDSET_H
#include <string>
namespace sdds
{

	class RecordSet
	{
	private:
		std::string* name;
		size_t track; 
	public:
		RecordSet();
		RecordSet(const char* nameOfFile);
		RecordSet(RecordSet& recordSet) noexcept;
		//move constructor
		RecordSet(RecordSet&& recordSet) noexcept;
		//move assignment operator
		RecordSet& operator=(RecordSet&& recordset) noexcept;
		RecordSet& operator=(RecordSet& recordset) noexcept;
		~RecordSet();
		size_t size();
		std::string getRecord(size_t size);
	};
}
#endif
