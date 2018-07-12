#pragma once

#include "Performance.h"

using namespace System;
using namespace System::Collections;

ref class PopularityComparer : Generic::IComparer<Performance^>
{
public:
	virtual int Compare(Performance ^ first, Performance ^ second);
};

ref class ProfitComparer : Generic::IComparer<Performance^>
{
public:
	virtual int Compare(Performance ^ first, Performance ^ second);
};