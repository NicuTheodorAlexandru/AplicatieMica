#pragma once
#include <string>

class DateTime
{
public:
	DateTime(int year, int month, int day, int hour, int minute);
	int minute, hour, day, month, year;
	bool operator==(const DateTime& other) { return (other.minute == minute) && (other.hour == hour) && (other.day == day) && (other.month == month) && (other.year == year); }
	bool operator!=(const DateTime& other) { return !(*this == other); }
	bool operator< (const DateTime& other) 
	{ 
		if (*this == other)
			return false;
		if (year < other.year)
			return true;
		else
			return false;
		if (month < other.month)
			return true;
		else
			return false;
		if (day < other.day)
			return true;
		else
			return false;
		if (hour < other.hour)
			return true;
		else
			return false;
		if (minute < other.minute)
			return true;
		else
			return false;
	}
	bool operator> (const DateTime& other) { return !(*this < other) && *this == other ; }
	bool operator<=(const DateTime& other) { return !(*this > other); }
	bool operator>=(const DateTime& other) { return !(*this < other); }
	operator std::string () const
	{
		std::string out =
			"Y" + std::to_string(year) +
			"m" + std::to_string(month) +
			"D" + std::to_string(day) +
			"H" + std::to_string(hour) +
			"M" + std::to_string(minute);
		return out;
	};
};