#pragma once
#include <string>
#include <sstream>
#include "IdGenerator.h"

class Vehicle
{
private:
	std::string registrationNumber;
	float height, width, length;
	unsigned int weight;
	unsigned int id;
public:
	Vehicle(std::string registrationNumber, float height, float width, float length, unsigned int weight);
	//~Vehicle();
	std::string GetRegistrationNumber();
	float GetHeight();
	float GetWidth();
	float GetLength();
	unsigned int GetWeight();
	unsigned int GetId();
	operator std::string () const
	{
		std::string out = registrationNumber + "," + std::to_string(height) + "," + std::to_string(width) + "," + std::to_string(length) + "," + std::to_string(weight);
		return out;
	};
};

