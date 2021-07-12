#pragma once
#include "Vehicle.h"

class ParkingLot
{
public:
	ParkingLot(float maxHeight, float maxWidth, float maxLength, unsigned int maxWeight);
	float CanFitVehicle(Vehicle* vehicle);
	operator std::string() const
	{
		std::string out = std::to_string(maxHeight) + "," + std::to_string(maxWidth) + "," + std::to_string(maxLength) + "," + std::to_string(maxWeight);
		return out;
	};
	bool occupied;
private:
	float maxHeight, maxWidth, maxLength;
	unsigned int maxWeight;
};

