#include "ReportPerformance.h"

ReportPerformance::ReportPerformance(PerformanceInfo ^ pi)
{
	info = pi;
	soldTickets = 0;
	countEvents = 0;
}

double ReportPerformance::Profit()
{
	return soldTickets * info->TicketPrice;
}

double ReportPerformance::Popularity()
{
	return soldTickets;
}