#pragma once

#include "Performance.h"
#include "ReportPerformance.h"

using namespace System;
using namespace System::Collections;

ref class DateComparer : Generic::IComparer<Performance^>
{
public:
	virtual int Compare(Performance ^ first, Performance ^ second);
};

ref class ReportPopularityComparer : Generic::IComparer<ReportPerformance^>
{
public:
	virtual int Compare(ReportPerformance ^ first, ReportPerformance ^ second);
};

ref class ReportProfitComparer : Generic::IComparer<ReportPerformance^>
{
public:
	virtual int Compare(ReportPerformance ^ first, ReportPerformance ^ second);
};