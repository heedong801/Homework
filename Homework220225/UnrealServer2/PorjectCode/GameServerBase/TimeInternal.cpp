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
	// n = 1�� 1�� 1�� ������ ��
	int n = static_cast<int>(ticks / TicksPerDay);
	// y400 = 1�� 1�� 1�� ������ 400�� ��ü �Ⱓ�� ��
	int y400 = n / DaysPer400Years;
	// n = 400�� �Ⱓ���� �� ��
	n -= y400 * DaysPer400Years;
	// y100 = 400�� �Ⱓ���� ��ü 100�� �Ⱓ ��
	int y100 = n / DaysPer100Years;
	// Last 100-year period has an extra day, so decrement result if 4
	if (y100 == 4) y100 = 3;
	// n = 100�� �Ⱓ���� �� ��
	n -= y100 * DaysPer100Years;
	// y4 = 100�� �Ⱓ���� ��ü 4�� �Ⱓ ��
	int y4 = n / DaysPer4Years;
	// n = 4�� �Ⱓ���� �� ��
	n -= y4 * DaysPer4Years;
	// y1 = 4�� �Ⱓ���� ��ü 1�� �Ⱓ ��
	int y1 = n / DaysPerYear;
	// Last year has an extra day, so decrement result if 4
	if (y1 == 4) y1 = 3;
	// ������ ��û������ ����ؼ� ��ȯ�մϴ�.
	if (part == DatePartYear) {
		return y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
	}
	// n = 1�� �Ⱓ���� �� ��
	n -= y1 * DaysPerYear;
	// DayOfYear �� ��û �Ȱ�� ��ȯ
	if (part == DatePartDayOfYear) return n + 1;
	// Leap year calculation looks different from IsLeapYear since y1, y4,
	// and y100 are relative to year 1, not year 0
	bool leapYear = y1 == 3 && (y4 != 24 || y100 == 3);
	const int* days = leapYear ? DaysToMonth366 : DaysToMonth365;
	// All months have less than 32 days, so n >> 5 is a good conservative
	// estimate for the month
	//	��� ���� 32 �� �̸��̹Ƿ� n >> 5 �� ���� ���� ���� ���� �߻�ġ �̴�.
	int m = (n >> 5) + 1;
	// m = 1-based month number
	while (n >= days[m]) m++;
	// Month �� ���� ��û�̿��ٸ� Return
	if (part == DatePartMonth) return m;
	// Return 1-based day-of-month
	return n - days[m - 1] + 1;
}

void TimeInternal::GetDatePart(unsigned __int64 dateData, int& year, int& month, int& day)
{
	__int64 ticks = InternalTicks(dateData);
	// n = 1�� 1�� 1�� ������ ��
	int n = static_cast<int>(ticks / TicksPerDay);
	// y400 = 1�� 1�� 1�� ������ 400�� ��ü �Ⱓ�� ��
	int y400 = n / DaysPer400Years;
	// n = 400�� �Ⱓ���� �� ��
	n -= y400 * DaysPer400Years;
	// y100 = 400�� �Ⱓ���� ��ü 100�� �Ⱓ ��
	int y100 = n / DaysPer100Years;
	// Last 100-year period has an extra day, so decrement result if 4
	if (y100 == 4) y100 = 3;
	// n = 100�� �Ⱓ���� �� ��
	n -= y100 * DaysPer100Years;
	// y4 = 100�� �Ⱓ���� ��ü 4�� �Ⱓ ��
	int y4 = n / DaysPer4Years;
	// n = 4�� �Ⱓ���� �� ��
	n -= y4 * DaysPer4Years;
	// y1 = 4�� �Ⱓ���� ��ü 1�� �Ⱓ ��
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