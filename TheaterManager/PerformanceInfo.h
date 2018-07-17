#pragma once

using namespace System;

// Возраст
enum Ages {
	CHILD, // Для детей
	ADULT // Для взрослых
};

// Информация о спектакле
ref class PerformanceInfo
{
private:
	String ^ name;
	String ^ info;
	Ages age;
	double ticketPrice;

public:
	property String ^ Name {
		String ^ get() {
			return name;
		}
		void set(String ^ name) {
			this->name = name;
		}
	}

	property String ^ Info {
		String ^ get() {
			return info;
		}
		void set(String ^ info) {
			this->info = info;
		}
	}

	property Ages Age {
		Ages get() {
			return age;
		}
		void set(Ages age) {
			this->age = age;
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

	PerformanceInfo();
	PerformanceInfo(String ^ name, String ^ info, Ages age, double ticketPrice);
};