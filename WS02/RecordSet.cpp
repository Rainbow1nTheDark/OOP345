//Name: Alexander Balandin
//ID : 132145194
//Email : abalandin@myseneca.ca
//Date : 10 / 03 / 2020
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include <fstream>
#include "RecordSet.h"
namespace sdds
{
    RecordSet::RecordSet()
    {
        name = nullptr;
        track = 0;
    }
    RecordSet::RecordSet(const char* nameOfFile)
    {
        track = 0;
        name = nullptr;
       
        std::ifstream in(nameOfFile);
        if (in.is_open()) {
            //I used this style of cheacking if is not the end of the file because while(in.good()) is infinite while loop
            std::string str;
            while (getline(in, str, ' '))
            {
                track++;

            }
            // reopening file to start reading from the beginning
            in.close();
           in.open(nameOfFile);
            if (name != nullptr)
            {
                delete[] name;
                name = nullptr;

            }
            name = new std::string[track];
            int i = 0;
           while(getline(in, name[i], ' '))
            {
               
                i++;
            }

            in.close();
        }
    }
    RecordSet::RecordSet(RecordSet& recordSet) noexcept
    {
        track = recordSet.track;
        name = nullptr;
        name = new std::string[track];
        for (size_t i = 0; i < track; i++)
        {
            name[i] = recordSet.name[i];
        }
    }
    RecordSet::RecordSet(RecordSet&& recordSet) noexcept
    {
        track = recordSet.track;
        name = nullptr;
        name = recordSet.name;
        recordSet.name = nullptr;
    }
    RecordSet& RecordSet::operator=(RecordSet&& recordset) noexcept
    {
        if (name != nullptr)
        {
            delete[] name;
            name = nullptr;

        }
        track = recordset.track;
        name = recordset.name;
        recordset.name = nullptr;
        
        return *this;
    }
    RecordSet& RecordSet::operator=(RecordSet& recordset) noexcept
    {
        if (name != nullptr)
        {
            delete[] name;
            name = nullptr;

        }
        track = recordset.track;
        name = new std::string[track];
        for (size_t i = 0; i < track; i++)
        {
            name[i] = recordset.name[i];
        }
        return *this;
    }
    RecordSet::~RecordSet()
    {
        if (name != nullptr)
        {
            delete[] name;
            name = nullptr;
        }
    }
    size_t RecordSet::size()
    {
        return track;
    }
    std::string RecordSet::getRecord(size_t size)
    {
        std::string str;
        if (size <= track && name != nullptr) {
            str = name[size];
        }

        

        return str;
    }
}