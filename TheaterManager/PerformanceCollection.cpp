#include "PerformanceCollection.h"

PerformanceCollection::PerformanceCollection()
{
	items = gcnew List<Performance^>();
}

int PerformanceCollection::SoldTickets()
{
	int count = 0;

	for each (Performance ^ perf in items)
		count += perf->SoldTickets;

	return count;
}

double PerformanceCollection::Profit()
{
	double count = 0;

	for each (Performance ^ perf in items)
		count += perf->Profit();

	return count;
}

double PerformanceCollection::Popularity()
{
	double popularity = 0;

	for each (Performance ^ perf in items)
		popularity += perf->Popularity();

	return popularity;
}