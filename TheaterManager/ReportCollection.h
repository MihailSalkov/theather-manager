#pragma once

#include "Performance.h"
#include "ReportPerformance.h"

using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class ReportCollection
{
private:
	List<ReportPerformance^> ^ items;

	ReportPerformance ^ Find(Performance ^ p);

public:
	ReportCollection();

	void Add(Performance ^ p);

	void SortByPopularity();
	void SortByProfit();

	void View(DataGridView ^ dgv);
};