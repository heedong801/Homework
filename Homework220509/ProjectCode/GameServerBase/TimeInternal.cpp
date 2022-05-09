#include "PreCompile.h"
#include "TimeInternal.h"

__int64 TimeInternal::DateToTicks(int year, int month, int day)
{
	if (year >= 1 && year <= 9999 && month >= 1 && month <= 12)
	{
		const int* days = IsLeapYear(year) ? DaysToMonth366 : DaysToMonth365;
		if (day >= 1 && day <= days[month] - days[month - 1])
		{
			int y = year - 1;
			int n = y * 365 + y / 4 - y / 100 + y / 400 + days[month - 1] + day - 1;
			return n * TicksPerDay;
		}
	}

	return 0;
}

__int64 TimeInternal::TimeToTicks(int hour, int minute, int second, int millisecond)
{
	if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60 && millisecond >= 0 && millisecond < 1000)
	{
		return hour * TicksPerHour
			+ minute * TicksPerMinute
			+ second * TicksPerSecond
			+ millisecond * TicksPerMillisecond;
	}
	return -1;
}

bool TimeInternal::IsLeapYear(int year)
{
	if (year < 1 || year > 9999) {
		year = 1;
	}

	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

__int64 TimeInternal::Assign(int Days, int Hours, int Minutes, int Seconds, int Millisecond, int Microsecond, int FractionNano)
{
	__int64 totalTicks = 0;

	totalTicks += Days * TicksPerDay;
	totalTicks += Hours * TicksPerHour;
	totalTicks += Minutes * TicksPerMinute;
	totalTicks += Seconds * TicksPerSecond;
	totalTicks += Millisecond * TicksPerMillisecond;
	totalTicks += Microsecond * TicksPerMicrosecond;
	totalTicks += FractionNano / NanosecondsPerTick;

	return totalTicks;
}

__int64 TimeInternal::InternalTicks(unsigned __int64 dateData)
{
	return static_cast<__int64>(dateData & TicksMask);
}

unsigned __int64 TimeInternal::InternalKind(unsigned __int64 dateData)
{
	return dateData & FlagsMask;
}

int TimeInternal::GetDatePart(unsigned __int64 dateData, int part)
{
	__int64 ticks = InternalTicks(dateData);
	// n = 1년 1월 1일 이후의 수
	int n = static_cast<int>(ticks / TicksPerDay);
	// y400 = 1년 1월 1일 이후의 400년 전체 기간의 수
	int y400 = n / DaysPer400Years;
	// n = 400년 기간내의 일 수
	n -= y400 * DaysPer400Years;
	// y100 = 400년 기간내의 전체 100년 기간 수
	int y100 = n / DaysPer100Years;
	// Last 100-year period has an extra day, so decrement result if 4
	if (y100 == 4) y100 = 3;
	// n = 100년 기간내의 일 수
	n -= y100 * DaysPer100Years;
	// y4 = 100년 기간내의 전체 4년 기간 수
	int y4 = n / DaysPer4Years;
	// n = 4년 기간내의 일 수
	n -= y4 * DaysPer4Years;
	// y1 = 4년 기간내의 전체 1년 기간 수
	int y1 = n / DaysPerYear;
	// Last year has an extra day, so decrement result if 4
	if (y1 == 4) y1 = 3;
	// 연도가 요청됬으면 계산해서 반환합니다.
	if (part == DatePartYear) {
		return y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
	}
	// n = 1년 기간내의 일 수
	n -= y1 * DaysPerYear;
	// DayOfYear 가 요청 된경우 반환
	if (part == DatePartDayOfYear) return n + 1;
	// Leap year calculation looks different from IsLeapYear since y1, y4,
	// and y100 are relative to year 1, not year 0
	bool leapYear = y1 == 3 && (y4 != 24 || y100 == 3);
	const int* days = leapYear ? DaysToMonth366 : DaysToMonth365;
	// All months have less than 32 days, so n >> 5 is a good conservative
	// estimate for the month
	//	모든 달은 32 일 미만이므로 n >> 5 는 월에 대한 적게 잡은 추산치 이다.
	int m = (n >> 5) + 1;
	// m = 1-based month number
	while (n >= days[m]) m++;
	// Month 에 대한 요청이였다면 Return
	if (part == DatePartMonth) return m;
	// Return 1-based day-of-month
	return n - days[m - 1] + 1;
}

void TimeInternal::GetDatePart(unsigned __int64 dateData, int& year, int& month, int& day)
{
	__int64 ticks = InternalTicks(dateData);
	// n = 1년 1월 1일 이후의 수
	int n = static_cast<int>(ticks / TicksPerDay);
	// y400 = 1년 1월 1일 이후의 400년 전체 기간의 수
	int y400 = n / DaysPer400Years;
	// n = 400년 기간내의 일 수
	n -= y400 * DaysPer400Years;
	// y100 = 400년 기간내의 전체 100년 기간 수
	int y100 = n / DaysPer100Years;
	// Last 100-year period has an extra day, so decrement result if 4
	if (y100 == 4) y100 = 3;
	// n = 100년 기간내의 일 수
	n -= y100 * DaysPer100Years;
	// y4 = 100년 기간내의 전체 4년 기간 수
	int y4 = n / DaysPer4Years;
	// n = 4년 기간내의 일 수
	n -= y4 * DaysPer4Years;
	// y1 = 4년 기간내의 전체 1년 기간 수
	int y1 = n / DaysPerYear;
	// Last year has an extra day, so decrement result if 4
	if (y1 == 4) y1 = 3;
	// compute year
	year = y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
	// n = day number within year
	n -= y1 * DaysPerYear;
	// dayOfYear = n + 1;
	// Leap year calculation looks different from IsLeapYear since y1, y4,
	// and y100 are relative to year 1, not year 0
	bool leapYear = y1 == 3 && (y4 != 24 || y100 == 3);
	const int* days = leapYear ? DaysToMonth366 : DaysToMonth365;
	// All months have less than 32 days, so n >> 5 is a good conservative
	// estimate for the month
	int m = (n >> 5) + 1;
	// m = 1-based month number
	while (n >= days[m]) m++;
	// compute month and day
	month = m;
	day = n - days[m - 1] + 1;
}

int TimeInternal::DaysInYear(int Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

int TimeInternal::DaysInMonth(int Year, int Month)
{
	const int* days = IsLeapYear(Year) ? DaysToMonth366 : DaysToMonth365;

	return days[Month];
}

bool TimeInternal::Validate(int Year, int Month, int Day)
{
	return (Year >= 1) && (Year <= 9999) &&
		(Month >= 1) && (Month <= 12) &&
		(Day >= 1) && (Day <= DaysInMonth(Year, Month));
}

bool TimeInternal::Validate(int Year, int Month, int Day, int Hour, int Minute, int Second, int Millisecond)
{
	return (Year >= 1) && (Year <= 9999) &&
		(Month >= 1) && (Month <= 12) &&
		(Day >= 1) && (Day <= DaysInMonth(Year, Month)) &&
		(Hour >= 0) && (Hour <= 23) &&
		(Minute >= 0) && (Minute <= 59) &&
		(Second >= 0) && (Second <= 59) &&
		(Millisecond >= 0) && (Millisecond <= 999);
}

unsigned __int64 TimeInternal::Add(unsigned __int64 dateData, double value, int scale)
{
	__int64 millis = static_cast<__int64>(value * scale + (value >= 0 ? 0.5 : -0.5));
	if (millis <= -MaxMillis || millis >= MaxMillis)
	{
	}
	return AddTicks(dateData, millis * TicksPerMillisecond);
}

unsigned __int64 TimeInternal::AddTicks(unsigned __int64 dateData, __int64 value)
{
	__int64 ticks = InternalTicks(dateData);
	if (value > MaxTicks - ticks || value < MinTicks - ticks)
	{
	}

	unsigned __int64 i64InternalKind = InternalKind(dateData);

	return ticks + value | i64InternalKind;
}