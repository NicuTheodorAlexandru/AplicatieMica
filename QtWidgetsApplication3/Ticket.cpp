#include "Ticket.h"

bool Ticket::IsBetweenDates(DateTime* start, DateTime* end)
{
	return *start >= *entryTime && *end >= *start && *end <= *leaveTime;
}

Ticket::~Ticket()
{
	delete entryTime;
	delete leaveTime;
}

float Ticket::GetParkingCost()
{
	return cost;
}

Ticket::Ticket(DateTime* entryTime, DateTime* leaveTime, unsigned int vehicleId, unsigned int lotId, float cost)
{
	this->entryTime = entryTime;
	this->leaveTime = leaveTime;
	this->vehicleId = vehicleId;
	this->lotId = lotId;
	this->cost = cost;
}