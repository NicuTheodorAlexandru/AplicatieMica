#include "ParkingLot.h"

float ParkingLot::CanFitVehicle(Vehicle* vehicle)
{
	float score = 0;
	if (maxHeight < vehicle->GetHeight())
	{
		return -1;
	}
	score += maxHeight - vehicle->GetHeight();
	if (maxWidth < vehicle->GetWidth())
	{
		return -1;
	}
	score += maxWidth - vehicle->GetWidth();
	if (maxLength < vehicle->GetLength())
	{
		return -1;
	}
	score += maxLength - vehicle->GetLength();
	if (maxWeight < vehicle->GetWeight())
	{
		return -1;
	}
	score += maxWeight - vehicle->GetWeight();
	return score;
}

ParkingLot::ParkingLot(float maxHeight, float maxWidth, float maxLength, unsigned int maxWeight)
{
	occupied = false;
	this->maxHeight = maxHeight;
	this->maxWidth = maxWidth;
	this->maxLength = maxLength;
	this->maxWeight = maxWeight;
}