//Name: Alexander Balandin
//ID : 132145194
//Email : abalandin@myseneca.ca
//Date : 10 / 03 / 2020
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <chrono>
#include "RecordSet.h"
namespace sdds
{
	const int MAX_OBJECTS = 7;
	class TimedEvents
	{
	private:
		
		int stored;
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point end;
		struct 
		{
			std::string eventName;
			std::string unitsOfTime;
			std::chrono::steady_clock::duration duration;
		} records[MAX_OBJECTS];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* nameOfEvent);
		friend std::ostream& operator<<(std::ostream& os, TimedEvents& timeEvent);
	};
}
#endif

