#pragma once

#include "PerformanceInfo.h"

using namespace System;

// Спектакль в конкретный день/время
ref class Performance {
private:
	PerformanceInfo ^ info;
	DateTime date;
	double ticketPrice;
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

	property double TicketPrice {
		double get() {
			return ticketPrice;
		}
		void set(double ticketPrice) {
			this->ticketPrice = ticketPrice;
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

	Performance();
	Performance(PerformanceInfo ^ info, DateTime date, double ticketPrice);

	double Profit();
	double Popularity();
};