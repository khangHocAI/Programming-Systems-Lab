#include"Time.h"

Time::Time()
{
	time_t info = time(0);
	struct tm now;
	localtime_s(&now, &info);
	_hour = now.tm_hour;
	_min = now.tm_min;
	_sec = now.tm_sec;
}
Time::Time(int hour, int min, int sec)
{
	if ((0 <= hour) && (hour <= 12) && (min >= 0) && (min <= 59) && (sec >= 0) && (sec <= 59))
	{
		_hour = hour;
		_min = min;
		_sec = sec;
	}
	else
	{
		throw runtime_error("Invalid argument");
	}
}
string Time::toString()
{
	stringstream out;
	out << setfill('0') << setw(2) << _hour;
	out << ":";
	out << setfill('0') << setw(2) << _min;
	out << ":";
	out << setfill('0') << setw(2) << _sec;
	return out.str();
}