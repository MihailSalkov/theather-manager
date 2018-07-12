#pragma once

#include "PerformanceCollection.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

ref class Performances {
private:
	String ^ fileName;
	List<PerformanceInfo^> ^ itemsInfo;
	PerformanceCollection ^ performances;
	DateTime currentMonth;

public:
	property List<PerformanceInfo^> ^ ItemsInfo {
		List<PerformanceInfo^> ^ get() {
			return itemsInfo;
		}
	}

	property DateTime CurrentMonth {
		DateTime get() {
			return currentMonth;
		}
		void set(DateTime currentMonth) {
			this->currentMonth = currentMonth;
		}
	}

	Performances();
	Performances(String ^ fileName, DateTime currentMonth);

	void Load();
	void Save();
	PerformanceCollection ^ getByCurrentMonth();
	PerformanceCollection ^ getByPopularity();
	PerformanceCollection ^ getByProfit();
	PerformanceCollection ^ getByPerformance(PerformanceInfo ^ perf);

};