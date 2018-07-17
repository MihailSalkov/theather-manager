#include "Performance.h"

Performance::Performance()
{
	info = gcnew PerformanceInfo();
	date = DateTime::MinValue;
	soldTickets = 0;
}

Performance::Performance(PerformanceInfo ^ info, DateTime dateTime)
{
	this->info = info;
	this->date = dateTime;
	this->soldTickets = 0;
}

double Performance::Profit()
{
	return info->TicketPrice * soldTickets;
}

double Performance::Popularity()
{
	return soldTickets;
}

bool Performance::IsNeedData()
{
	return Date <= DateTime::Now && soldTickets <= 0;
}