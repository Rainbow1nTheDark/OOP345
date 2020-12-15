//Name: Alexander Balandin
//ID : 132145194
//Email : abalandin@myseneca.ca
//Date : 10 / 03 / 2020
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"
namespace sdds
{
    std::ostream& operator<<(std::ostream& os, TimedEvents& timeEvent)
    {
        os << "--------------------------\n" << "Execution Times:\n"
            << "--------------------------\n";
        for (auto i = 0; i < timeEvent.stored; i++) 
        {
            os << std::setw(20) << std::left << timeEvent.records[i].eventName << std::setw(12) << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(timeEvent.records[i].duration).count() << std::right << " nanoseconds" <<'\n';
        }
        os << "--------------------------\n";
        return os;
    }
    TimedEvents::TimedEvents()
    {
        stored = 0;
    }
    void TimedEvents::startClock()
    {
        start = std::chrono::steady_clock::now();
    }
    void TimedEvents::stopClock()
    {
        end = std::chrono::steady_clock::now();
    }
    void TimedEvents::recordEvent(const char* nameOfEvent)
    {
        if (stored < MAX_OBJECTS) {
            records[stored].unitsOfTime = "nanoseconds";
            records[stored].eventName = nameOfEvent;
            records[stored].duration = end - start;
            stored++;
        }
    }
}