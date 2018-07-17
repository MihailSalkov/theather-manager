#include "ReportCollection.h"
#include "PerformanceComparers.h"

using namespace System::Collections::Generic;

ReportCollection::ReportCollection()
{
	items = gcnew List<ReportPerformance^>();
}

ReportPerformance ^ ReportCollection::Find(Performance ^ p)
{
	for each (ReportPerformance ^ rp in items)
	{
		if (rp->Info == p->Info)
			return rp;
	}

	return nullptr;
}

void ReportCollection::Add(Performance ^ p)
{
	ReportPerformance ^ find = Find(p);

	if (find == nullptr)
	{
		find = gcnew ReportPerformance(p->Info);
		items->Add(find);
	}

	find->CountEvents++;
	find->SoldTickets += p->SoldTickets;
}

void ReportCollection::SortByPopularity()
{
	items->Sort(gcnew ReportPopularityComparer());
}

void ReportCollection::SortByProfit()
{
	items->Sort(gcnew ReportProfitComparer());
}

void ReportCollection::View(DataGridView ^ dgv)
{
	dgv->Rows->Clear();

	for each (ReportPerformance ^ p in items)
	{
		array <String^> ^ vals = { p->Info->Name, p->CountEvents.ToString(), p->SoldTickets.ToString(), p->Profit().ToString() };
		dgv->Rows->Add(vals);
	}
}