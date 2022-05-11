#pragma once

class TimeInternal
{
public:
    static constexpr __int64 NanosecondsPerTick = 100;  //  틱당 나노초 1틱당 100나노초

    static constexpr __int64 TicksPerMicrosecond = 10;  //  10틱당 1마이크로초
    static constexpr __int64 TicksPerMillisecond = 10000;   //  10000틱당 1밀리초
    static constexpr __int64 TicksPerSecond = TicksPerMillisecond * 1000;
    static constexpr __int64 TicksPerMinute = TicksPerSecond * 60;
    static constexpr __int64 TicksPerHour = TicksPerMinute * 60;
    static constexpr __int64 TicksPerDay = TicksPerHour * 24;

    // Number of milliseconds per time unit
    static constexpr int MillisPerSecond = 1000;
    static constexpr int MillisPerMinute = MillisPerSecond * 60;
    static constexpr int MillisPerHour = MillisPerMinute * 60;
    static constexpr int MillisPerDay = MillisPerHour * 24;

    // Number of days in a non-leap year
    static constexpr int DaysPerYear = 365;
    // Number of days in 4 years
    static constexpr int DaysPer4Years = DaysPerYear * 4 + 1;       // 1461
    // Number of days in 100 years
    static constexpr int DaysPer100Years = DaysPer4Years * 25 - 1;  // 36524
    // Number of days in 400 years
    static constexpr int DaysPer400Years = DaysPer100Years * 4 + 1; // 146097

    // Number of days from 1/1/0001 to 12/31/1600
    static constexpr int DaysTo1601 = DaysPer400Years * 4;          // 584388
    // Number of days from 1/1/0001 to 12/30/1899
    static constexpr int DaysTo1899 = DaysPer400Years * 4 + DaysPer100Years * 3 - 367;
    // Number of days from 1/1/0001 to 12/31/1969
    static constexpr int DaysTo1970 = DaysPer400Years * 4 + DaysPer100Years * 3 + DaysPer4Years * 17 + DaysPerYear; // 719,162
    // Number of days from 1/1/0001 to 12/31/9999
    static constexpr int DaysTo10000 = DaysPer400Years * 25 - 366;  // 3652059

    static constexpr __int64 MinTicks = 0;
    static constexpr __int64 MaxTicks = DaysTo10000 * TicksPerDay - 1;
    static constexpr __int64 MaxMillis = (__int64)DaysTo10000 * MillisPerDay;

    static constexpr __int64 FileTimeOffset = DaysTo1601 * TicksPerDay;
    static constexpr __int64 DoubleDateOffset = DaysTo1899 * TicksPerDay;
    // The minimum OA date is 0100/01/01 (Note it's year 100).
    // The maximum OA date is 9999/12/31
    static constexpr __int64 OADateMinAsTicks = (DaysPer100Years - DaysPerYear) * TicksPerDay;
    // All OA dates must be greater than (not >=) OADateMinAsDouble
    static constexpr double OADateMinAsDouble = -657435.0;
    // All OA dates must be less than (not <=) OADateMaxAsDouble
    static constexpr double OADateMaxAsDouble = 2958466.0;

    static constexpr int DatePartYear = 0;
    static constexpr int DatePartDayOfYear = 1;
    static constexpr int DatePartMonth = 2;
    static constexpr int DatePartDay = 3;

    //static constexpr bool s_isLeapSecondsSupportedSystem = SystemSupportLeapSeconds();

    static constexpr int DaysToMonth365[] = {
        0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    static constexpr int DaysToMonth366[] = {
        0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

    //public static readonly DateTime MinValue = new DateTime(MinTicks, DateTimeKind.Unspecified);
    //public static readonly DateTime MaxValue = new DateTime(MaxTicks, DateTimeKind.Unspecified);

    static constexpr unsigned __int64 TicksMask = 0x3FFFFFFFFFFFFFFF;
    static constexpr unsigned __int64 FlagsMask = 0xC000000000000000;
    static constexpr unsigned __int64 LocalMask = 0x8000000000000000;
    static constexpr __int64 TicksCeiling = 0x4000000000000000;
    static constexpr unsigned __int64 KindUnspecified = 0x0000000000000000;
    static constexpr unsigned __int64 KindUtc = 0x4000000000000000;
    static constexpr unsigned __int64 KindLocal = 0x8000000000000000;
    static constexpr unsigned __int64 KindLocalAmbiguousDst = 0xC000000000000000;
    static constexpr unsigned int KindShift = 62;

public:
    static __int64 DateToTicks(int year, int month, int day);
    static __int64 TimeToTicks(int hour, int minute, int second, int millisecond);
    static bool IsLeapYear(int year);

    static __int64 Assign(int Days, int Hours, int Minutes, int Seconds, int Millisecond, int Microsecond, int FractionNano);

    static __int64 InternalTicks(unsigned __int64 dateData);
    static unsigned __int64 InternalKind(unsigned __int64 dateData);
    static int GetDatePart(unsigned __int64 dateData, int part);
    static void GetDatePart(unsigned __int64 dateData, int& year, int& month, int& day);

    static int DaysInYear(int Year);
    static int DaysInMonth(int Year, int Month);
    static bool Validate(int Year, int Month, int Day);
    static bool Validate(int Year, int Month, int Day, int Hour, int Minute, int Second, int Millisecond);

    static unsigned __int64 Add(unsigned __int64 dateData, double value, int scale);
    static unsigned __int64 AddTicks(unsigned __int64 dateData, __int64 value);
};