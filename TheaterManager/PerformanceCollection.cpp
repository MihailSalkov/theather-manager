#include "PerformanceCollection.h"
#include "PerformanceComparers.h"

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

void PerformanceCollection::Sort()
{
	Items->Sort(gcnew DateComparer());
}

PerformanceCollection ^ PerformanceCollection::getNeedData()
{
	PerformanceCollection ^ pc = gcnew PerformanceCollection();

	for each (Performance ^ p in items)
	{
		if (p->IsNeedData())
		{
			pc->Items->Add(p);
		}
	}

	return pc;
}

ReportCollection ^ PerformanceCollection::getReport()
{
	ReportCollection ^ rp = gcnew ReportCollection();

	for each (Performance ^ p in items)
	{
		rp->Add(p);
	}

	return rp;
}

void PerformanceCollection::View(ListBox ^ lb)
{
	lb->Items->Clear();

	for each (Performance ^ perf in items)
	{
		lb->Items->Add(perf->ShortName);
	}
}