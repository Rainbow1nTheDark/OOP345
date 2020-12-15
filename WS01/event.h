/*
Name: Alexander Balandin
ID: 132145194
DATE: 9/22/2020
*/
#ifndef SDDS_EVENT_H
#define  SDDS_EVENT_H
extern unsigned int g_sysClock;
namespace sdds {

	class Event
	{
	private:
		char * description = nullptr;
		unsigned int eventStarted;
	public:
		Event();
		Event(const Event& event);
		~Event();
		void saveState();
		
		void display() const;
		void setDescription(const char* information);
		Event& operator=(Event& event);
	};
}
#endif