/*
Name: Alexander Balandin
ID: 132145194
DATE: 9/22/2020
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"
unsigned int g_sysClock;
namespace sdds {
	sdds::Event::Event()
	{
		saveState();
		this->eventStarted = 0;

	}

	Event::Event(const Event& event)
	{
		this->eventStarted = event.eventStarted;
		saveState();
		//2.	if the src pointer is not null, create new resources for the current object and do the copy
		if (event.description != nullptr && event.description[0] != 0)
		{

			this->description = new char[strlen(event.description) + 1];
			strcpy(description, event.description);
			description[strlen(event.description)] = 0;

		}
		else
		{
			//a.	else set the pointer for the current object to nullptr
			this->description = nullptr;

		}
	}

	Event::~Event()
	{


		saveState();

	}

	void Event::saveState()
	{
		if (description != nullptr) {
			delete[] this->description;
			this->description = nullptr;
		}
	}





	void sdds::Event::display() const
	{
		//how many times this function has been called
		static unsigned short counter = 0;
		counter++;

		if (this->description != nullptr)
		{
			unsigned copySec = eventStarted;
			unsigned h = eventStarted / (60 * 60);
			copySec -= h * (60 * 60);
			unsigned m = copySec / 60;
			copySec -= m * 60;
			std::cout.width(3);

			std::cout << std::setfill(' ') << counter << ". " << std::setfill('0') << std::setw(2) << h << ":" << std::setw(2) << m << ":" << std::setw(2) << copySec << " -> " << description << std::endl;
		}
		else
		{
			std::cout.width(3);
			std::cout << std::setfill(' ') << counter << ". [ No Event ]" << std::endl;
		}
	}

	void sdds::Event::setDescription(const char* information)
	{
		eventStarted = g_sysClock;
		//1.	delete the resources pointed to in the current object [ if it is not null pointer
		saveState();
		//2.	if the src pointer is not null, create new resources for the current object and do the copy
		if (information != nullptr && information[0] != 0)
		{

			this->description = new char[strlen(information) + 1];
			strcpy(description, information);
			description[strlen(information)] = 0;

		}
		else
		{
			//a.	else set the pointer for the current object to nullptr
			this->description = nullptr;

		}
	}
	Event& Event::operator=(Event& event)
	{
		this->eventStarted = event.eventStarted;
		saveState();
		if (event.description != nullptr)
		{
			description = new char[strlen(event.description) + 1];
			strcpy(description, event.description);

		}
		else {
			description = nullptr;
		}
		return *this;
	}
}
