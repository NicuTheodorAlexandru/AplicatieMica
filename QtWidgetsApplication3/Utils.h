#pragma once
#include "Vehicle.h"
#include "DateTime.h"
#include "ParkingLot.h"
#include "Ticket.h"
#include <string>
#include <algorithm>

class Utils
{
private:

public:
	template<typename T>
	static T* ModelFromString(std::string line, char delim = ' ')
	{
		return NULL;
	}

	template<>
	static Ticket* ModelFromString<Ticket>(std::string line, char delim)
	{
		int i = line.find(delim, 0);
		std::string s1 = line.substr(0, i);
		std::string s2 = line.substr(i+1, line.find(delim, i + 1) - i - 1);
		DateTime* entryTime = ModelFromString<DateTime>(s1, delim);
		DateTime* leaveTime = ModelFromString<DateTime>(s2, delim);
		line = line.substr(s1.size() + s2.size() + 1, std::string::npos);
		unsigned int lotId, vehicleId;
		float cost;
		std::replace(line.begin(), line.end(), delim, ' ');
		std::stringstream ss{ line };
		ss >> lotId >> vehicleId >> cost;
		return new Ticket{ entryTime, leaveTime, vehicleId, lotId, cost };
	}

	template<>
	static ParkingLot* ModelFromString<ParkingLot>(std::string line, char delim)
	{
		float maxHeight, maxWidth, maxLength;
		unsigned int maxWeight;
		std::replace(line.begin(), line.end(), delim, ' ');
		std::stringstream ss{ line };
		ss >> maxHeight >> maxWidth >> maxLength >> maxWeight;
		return new ParkingLot{ maxHeight, maxWidth, maxLength, maxWeight };
	}

	template<>
	static DateTime* ModelFromString<DateTime>(std::string line, char delim)
	{
		int num;
		std::stringstream ss{line};
		int year, month, day, hour, minute;
		char c, c2;
		while (ss >> c >> num)
		{
			if (c == 'Y')
			{
				year = num;
			}
			else if (c == 'm')
			{
				month = num;
			}
			else if (c == 'D')
			{
				day = num;
			}
			else if (c == 'H')
			{
				hour = num;
			}
			else if (c == 'M')
			{
				minute = num;
			}
		}
		return new DateTime{year, month, day, hour, minute};
	}

	template<>
	static Vehicle* ModelFromString<Vehicle>(std::string line, char delim)
	{
		int start = 0, end;
		end = line.find(delim, start);
		std::string registration = line.substr(start, end);
		start = end + 1;
		end = line.find(delim, start);
		std::string str = line.substr(start, end);
		float height = std::stof(line.substr(start, end));
		start = end + 1;
		end = line.find(delim, start);
		float width = std::stof(line.substr(start, end));
		start = end + 1;
		end = line.find(delim, start);
		float length = std::stof(line.substr(start, end));
		start = end + 1;
		end = line.find(delim, start);
		unsigned int weight = std::stoul(line.substr(start, end));
		Vehicle* v = new Vehicle{ registration, height, width, length, weight };
		return v;
	}
};

