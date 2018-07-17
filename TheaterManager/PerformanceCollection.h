#pragma once

#include "Performance.h"
#include "ReportCollection.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

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

	void Sort();

	PerformanceCollection ^ getNeedData();
	ReportCollection ^ getReport();

	void View(ListBox ^ lb);
};