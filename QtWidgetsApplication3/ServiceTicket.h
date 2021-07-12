#pragma once
#include "Repository.h"
#include "Ticket.h"
#include "DateTime.h"

class ServiceTicket
{
public:
	ServiceTicket(Repository<Ticket>* repo);
	~ServiceTicket();
	void AddTicket(unsigned int vehicleId, unsigned int lotId, DateTime* entryTime, DateTime* leaveTime, float cost);
	float Income(DateTime* start, DateTime* end);
private:
	Repository<Ticket>* repo;
};

