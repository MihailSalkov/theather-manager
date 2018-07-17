#include "PerformanceComparers.h"

int DateComparer::Compare(Performance ^ first, Performance ^ second)
{
	return first->Date.CompareTo(second->Date);
}

int ReportPopularityComparer::Compare(ReportPerformance ^ first, ReportPerformance ^ second)
{
	return first->Popularity().CompareTo(second->Popularity()) * -1;
}

int ReportProfitComparer::Compare(ReportPerformance ^ first, ReportPerformance ^ second)
{
	return first->Profit().CompareTo(second->Profit()) * -1;
}