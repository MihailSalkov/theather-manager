#pragma once

#include "PerformanceInfo.h"

ref class ReportPerformance
{
private:
	PerformanceInfo ^ info;
	int countEvents;
	int soldTickets;

public:
	property PerformanceInfo ^ Info {
		PerformanceInfo ^ get() {
			return info;
		}
	}

	ReportPerformance(PerformanceInfo ^ pi);

	property int CountEvents {
		int get() {
			return countEvents;
		}
		void set(int countEvents) {
			this->countEvents = countEvents;
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

	double Profit();
	double Popularity();
};