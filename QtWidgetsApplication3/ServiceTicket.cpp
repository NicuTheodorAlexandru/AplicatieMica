#include "ServiceTicket.h"

float ServiceTicket::Income(DateTime* start, DateTime* end)
{
	float income = 0;
	for (auto it = repo->GetIteratorBegin(); it != repo->GetIteratorEnd(); it++)
	{
		bool t = it->second->IsBetweenDates(start, end);
		if (!it->second->IsBetweenDates(start, end))
		{
			continue;
		}
		income += it->second->GetParkingCost();
	}
	return income;
}

void ServiceTicket::AddTicket(unsigned int vehicleId, unsigned int lotId, DateTime* entryTime, DateTime* leaveTime, float cost)
{
	repo->AddElement(new Ticket{ entryTime, leaveTime, vehicleId, lotId, cost } );
}

ServiceTicket::~ServiceTicket()
{
	delete repo;
}

ServiceTicket::ServiceTicket(Repository<Ticket>* repo)
{
	this->repo = repo;
}
