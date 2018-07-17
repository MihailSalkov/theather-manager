#pragma once

#include "PerformanceInfo.h"

using namespace System;

// Спектакль в конкретный день/время
ref class Performance {
private:
	PerformanceInfo ^ info;
	DateTime date;
	int soldTickets;

public:
	property PerformanceInfo ^ Info {
		PerformanceInfo ^ get() {
			return info;
		}
		void set(PerformanceInfo ^ info) {
			this->info = info;
		}
	}

	property DateTime Date {
		DateTime get() {
			return date;
		}
		void set(DateTime date) {
			this->date = date;
		}
	}

	property int SoldTickets {
		int get() {
			return soldTickets;
		}
		void set(int soldTickets) {
			this->soldTickets = soldTickets;
		}
	}

	property String ^ ShortName {
		String ^ get() {
			return Date.ToString("dd MMM в HH:mm") + " - " + Info->Name;
		}
	}

	Performance();
	Performance(PerformanceInfo ^ info, DateTime date);

	double Profit();
	double Popularity();
	bool IsNeedData();
};