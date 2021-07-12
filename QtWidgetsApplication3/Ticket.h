#pragma once
#include "DateTime.h"
#include "Vehicle.h"
#include "ParkingLot.h"

class Ticket
{
public:
	Ticket(DateTime* entryTime, DateTime* leaveTime, unsigned int vehicleId, unsigned int lotId, float cost);
	~Ticket();
	float GetParkingCost();
	bool IsBetweenDates(DateTime* start, DateTime* end);
	operator std::string() const
	{
		std::string out = std::string(*entryTime) + "," + std::string(*leaveTime) + ","
			+ std::to_string(lotId) + "," + std::to_string(vehicleId) 
			+ "," + std::to_string(cost);
		return out;
	};
private:
	unsigned int lotId, vehicleId;
	DateTime* entryTime;
	DateTime* leaveTime;
	float cost;
};

