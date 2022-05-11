#pragma once
#include "DateTimeKind.h"

static void Append(std::string& str, const char* format)
{

}

class DateTime
{
private:
	unsigned __int64 _dateData;

public:
	int Year() const;
	int Month() const;
	int Day() const;
	int GetDayOfYear() const;
	int Hour() const;
	int GetHour12() const;
	int Minute() const;
	int Second() const;
	int Millisecond() const;
	__int64 Ticks() const;

	DateTimeKind Kind() const;
	DayOfWeek DayOfWeek() const;

	DateTime AddMonths(int months) const;
	DateTime AddDays(double days) const;
	DateTime AddHour(double hour) const;
	DateTime AddMinutes(double minutes) const;
	DateTime AddSeconds(double seconds) const;
	DateTime AddMillisecond(double millisecond) const;

	bool operator==(const DateTime& rhs) const;
	bool operator!=(const DateTime& rhs) const;
	bool operator<(const DateTime& rhs) const;
	bool operator<=(const DateTime& rhs) const;
	bool operator>(const DateTime& rhs) const;
	bool operator>=(const DateTime& rhs) const;

public:
	static DateTime UtcNow();
	static DateTime Now();

public:
	std::string ToString() const;
	std::string ToString(const char* Format) const;

public:
	DateTime();
	DateTime(__int64 ticks, DateTimeKind kind);
	DateTime(int year, int month, int day, DateTimeKind kind);
	DateTime(int year, int month, int day, int hour, int minute, int second, DateTimeKind kind);
	DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, DateTimeKind kind);
	~DateTime();
};