#include "ServiceVehicle.h"

void ServiceVehicle::AddVehicle(std::string registrationNumber, float height, float width, float length, unsigned int weight)
{
	repo->AddElement(new Vehicle(registrationNumber, height, width, length, weight));
}

ServiceVehicle::~ServiceVehicle()
{
	delete repo;
}

ServiceVehicle::ServiceVehicle(Repository<Vehicle>* repo)
{
	this->repo = repo;
}