#include "Performance.h"

Performance::Performance()
{
	info = gcnew PerformanceInfo();
	date = DateTime::MinValue;
	soldTickets = 0;
	ticketPrice = 0;
}

Performance::Performance(PerformanceInfo ^ info, DateTime dateTime, double ticketPrice)
{
	this->info = info;
	this->date = dateTime;
	this->soldTickets = 0;
	this->ticketPrice = 0;
}

double Performance::Profit()
{
	return ticketPrice * soldTickets;
}

double Performance::Popularity()
{
	return soldTickets;
}