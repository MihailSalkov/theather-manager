#include "PerformanceInfo.h"

PerformanceInfo::PerformanceInfo()
{
	name = "";
	info = "";
	age = CHILD;
	ticketPrice = 0;
}

PerformanceInfo::PerformanceInfo(String ^ name, String ^ info, Ages age, double ticketPrice)
{
	this->name = name;
	this->info = info;
	this->age = age;
	this->ticketPrice = ticketPrice;
}
