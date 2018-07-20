#include "Performances.h"
#include "PerformanceComparers.h"

using namespace System::IO;
using namespace System::Windows::Forms;

Performances::Performances()
{
	fileName = "performances.db";
	itemsInfo = gcnew List<PerformanceInfo^>();
	performances = gcnew PerformanceCollection();
	currentMonth = DateTime::MinValue;
	Load();
}

Performances::Performances(String ^ fileName, DateTime currentMonth)
{
	this->fileName = fileName;
	itemsInfo = gcnew List<PerformanceInfo^>();
	performances = gcnew PerformanceCollection();
	CurrentMonth = currentMonth;
	Load();
}

void Performances::Load()
{
	if (!File::Exists(fileName))
		return;

	StreamReader ^ sr = gcnew StreamReader(fileName);

	enum ReadState { NAME, AGE, PRICE, INFO, EVENTS };

	String ^ line;
	ReadState state = NAME;
	PerformanceInfo ^ perfInfo;

	while ((line = sr->ReadLine()) != nullptr)
	{
		switch (state)
		{
		case NAME:
			perfInfo = gcnew PerformanceInfo();
			perfInfo->Name = line;

			state = AGE;
			break;

		case AGE:
			perfInfo->Age = (Ages) Int32::Parse(line);

			state = PRICE;
			break;

		case PRICE:
			perfInfo->TicketPrice = perfInfo->TicketPrice.Parse(line);

			state = INFO;
			break;

		case INFO:
			if (line == "#@#")
			{
				itemsInfo->Add(perfInfo);

				state = EVENTS;
				break;
			}

			if (perfInfo->Info != "")
				perfInfo->Info += "\n";
			perfInfo->Info += line;
			break;

		case EVENTS:
			if (line == "")
			{
				state = NAME;
				break;
			}

			array<Char> ^ sep = { L';' };
			array<String^> ^ fields = line->Split(sep);

			Performance ^ perf = gcnew Performance();
			perf->Info = perfInfo;
			perf->Date = DateTime::Parse(fields[0]);
			perf->SoldTickets = perf->SoldTickets.Parse(fields[1]);
			performances->Items->Add(perf);
			break;
		}
	}

	sr->Close();
}

void Performances::Save()
{
	StreamWriter ^ sw = gcnew StreamWriter(fileName);

	for each (PerformanceInfo ^ perfInfo in itemsInfo)
	{
		sw->WriteLine(perfInfo->Name);
		sw->WriteLine(perfInfo->Age);
		sw->WriteLine(perfInfo->TicketPrice);
		sw->WriteLine(perfInfo->Info);
		sw->WriteLine("#@#");

		PerformanceCollection ^ perfs = getByPerformance(perfInfo);
		for each (Performance ^ perf in perfs->Items)
		{
			sw->WriteLine(perf->Date.ToString() + ";" + perf->SoldTickets);
		}
		sw->WriteLine("");
	}

	sw->Close();
}

PerformanceCollection ^ Performances::getByCurrentMonth()
{
	PerformanceCollection ^ res = gcnew PerformanceCollection();
	DateTime nextMonth = currentMonth.AddMonths(1);

	for each (Performance ^ perf in performances->Items)
	{
		if (perf->Date >= currentMonth && perf->Date < nextMonth)
			res->Items->Add(perf);
	}

	res->Sort();

	return res;
}

PerformanceCollection ^ Performances::getByPerformance(PerformanceInfo ^ perfInfo)
{
	PerformanceCollection ^ res = gcnew PerformanceCollection();

	for each (Performance ^ perf in performances->Items)
	{
		if (perf->Info->Equals(perfInfo))
			res->Items->Add(perf);
	}

	res->Sort();

	return res;
}

void Performances::AddPerformance(Performance ^ perf)
{
	performances->Items->Add(perf);
	performances->Sort();
	Save();
}

void Performances::RemovePerformance(Performance ^ perf)
{
	performances->Items->Remove(perf);
	Save();
}