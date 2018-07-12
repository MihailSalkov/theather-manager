#include "PerformanceComparers.h"

int PopularityComparer::Compare(Performance ^ first, Performance ^ second)
{
	return first->Popularity().CompareTo(second->Popularity());
}

int ProfitComparer::Compare(Performance ^ first, Performance ^ second)
{
	return first->Profit().CompareTo(second->Profit());
}