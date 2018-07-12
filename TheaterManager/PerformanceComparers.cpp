#include "PerformanceComparers.h"

int DateComparer::Compare(Performance ^ first, Performance ^ second)
{
	return first->Date.CompareTo(second->Date);
}

int PopularityComparer::Compare(Performance ^ first, Performance ^ second)
{
	return first->Popularity().CompareTo(second->Popularity());
}

int ProfitComparer::Compare(Performance ^ first, Performance ^ second)
{
	return first->Profit().CompareTo(second->Profit());
}