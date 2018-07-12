#include "PerformanceInfo.h"

PerformanceInfo::PerformanceInfo()
{
	name = "";
	info = "";
	age = CHILD;
}

PerformanceInfo::PerformanceInfo(String ^ name, String ^ info, Ages age)
{
	this->name = name;
	this->info = info;
	this->age = age;
}
