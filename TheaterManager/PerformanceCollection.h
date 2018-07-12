#pragma once

#include "Performance.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

// ��������� ���������� (����� �������������� ��� ������� ������, � ��� �� �� ������������ �������/����������/�������� � �.�.
ref class PerformanceCollection
{
private:
	List<Performance^> ^ items;

public:
	property List<Performance^> ^ Items {
		List<Performance^> ^ get() {
			return items;
		}
	}

	PerformanceCollection();

	int SoldTickets();
	double Profit();
	double Popularity();
};