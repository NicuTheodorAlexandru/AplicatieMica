#include "Vehicle.h"

float Vehicle::GetWidth()
{
	return width;
}

float Vehicle::GetLength()
{
	return length;
}

unsigned int Vehicle::GetWeight()
{
	return weight;
}

unsigned int Vehicle::GetId()
{
	return id;
}

float Vehicle::GetHeight()
{
	return height;
}

std::string Vehicle::GetRegistrationNumber()
{
	return registrationNumber;
}

Vehicle::Vehicle(std::string registrationNumber, float height, float width, float length, unsigned int weight)
{
	this->registrationNumber = registrationNumber;
	this->height = height;
	this->width = width;
	this->length = length;
	this->weight = weight;
	id = IdGenerator::GenerateId();
}