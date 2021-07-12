#pragma once
#include "Vehicle.h"
#include "Repository.h"

class ServiceVehicle
{
public:
	ServiceVehicle(Repository<Vehicle>* repo);
	~ServiceVehicle();
	void AddVehicle(std::string registrationNumber, float height, float width, float length, unsigned int weight);
	Vehicle* GetVehicleById(unsigned int id)
	{
		return repo->GetElementById(id);
	}
private:
	Repository<Vehicle>* repo;
};

