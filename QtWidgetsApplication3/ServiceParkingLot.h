#pragma once
#include "ParkingLot.h"
#include "Repository.h"
#include <limits>

class ServiceParkingLot
{
public:
	ServiceParkingLot(Repository<ParkingLot>* repo);
	~ServiceParkingLot();
	void AddParkingLot(float maxHeight, float maxWidth, float maxLength, unsigned int maxWeight);
	unsigned int GetBestParkingLot(Vehicle* vehicle);
private:
	Repository<ParkingLot>* repo;
};