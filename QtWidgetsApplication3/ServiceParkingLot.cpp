#include "ServiceParkingLot.h"

unsigned int ServiceParkingLot::GetBestParkingLot(Vehicle* vehicle)
{
	unsigned int bid = 0;
	float bestScore =  std::numeric_limits<float>::max();
	for (auto it = repo->GetIteratorBegin(); it != repo->GetIteratorEnd(); it++)
	{
		unsigned int id = it->first;
		ParkingLot* lot = it->second;
		if (lot->occupied)
		{
			continue;
		}
		float score = lot->CanFitVehicle(vehicle);
		if (score == -1)
		{
			continue;
		}
		if (score < bestScore)
		{
			bestScore = score;
			bid = id;
		}
	}
	return bid;
}

void ServiceParkingLot::AddParkingLot(float maxHeight, float maxWidth, float maxLength, unsigned int maxWeight)
{
	repo->AddElement(new ParkingLot{ maxHeight, maxWidth, maxLength, maxWeight });
}

ServiceParkingLot::~ServiceParkingLot()
{
	delete repo;
}

ServiceParkingLot::ServiceParkingLot(Repository<ParkingLot>* repo)
{
	this->repo = repo;
}