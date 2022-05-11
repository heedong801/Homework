#include "PreCompile.h"
#include "DateTime.h"
#include "TimeInternal.h"

DateTime::DateTime() : _dateData(0)
{
}

DateTime::DateTime(__int64 ticks, DateTimeKind kind)
{
	if (ticks < TimeInternal::MinTicks || ticks > TimeInternal::MaxTicks)
	{
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 파라미터로 넘어온 ticks 값이 이상합니다."));
	}

	_dateData = static_cast<unsigned __int64>(ticks);

	switch (kind)
	{
	case DateTimeKind::Utc:
	{
		_dateData |= TimeInternal::KindUtc;
	}
	break;
	case DateTimeKind::Local:
	{
		_dateData |= TimeInternal::KindLocal;
	}
	break;
	case DateTimeKind::Unspecified:
	{
		_dateData |= TimeInternal::KindUnspecified;
	}
	break;
	default:
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 지원하지 않는 DateTimeKind 입니다."));
		break;
	}
}

DateTime::DateTime(int year, int month, int day, DateTimeKind kind)
{
	if (false == TimeInternal::Validate(year, month, day))
	{
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 파라미터로 넘어온 year, month, day 가 이상합니다."));
	}

	_dateData = static_cast<unsigned __int64>(TimeInternal::DateToTicks(year, month, day));

	switch (kind)
	{
	case DateTimeKind::Utc:
	{
		_dateData |= TimeInternal::KindUtc;
	}
	break;
	case DateTimeKind::Local:
	{
		_dateData |= TimeInternal::KindLocal;
	}
	break;
	case DateTimeKind::Unspecified:
	{
		_dateData |= TimeInternal::KindUnspecified;
	}
	break;
	default:
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 지원하지 않는 DateTimeKind 입니다."));
		break;
	}
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second, DateTimeKind kind)
{
	if (false == TimeInternal::Validate(year, month, day, hour, minute, second, 0))
	{
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 파라미터로 넘어온 year, month, day, hour, minute, second 가 이상합니다."));
	}

	_dateData = static_cast<unsigned __int64>(TimeInternal::DateToTicks(year, month, day) + TimeInternal::TimeToTicks(hour, minute, second, 0));

	switch (kind)
	{
	case DateTimeKind::Utc:
	{
		_dateData |= TimeInternal::KindUtc;
	}
	break;
	case DateTimeKind::Local:
	{
		_dateData |= TimeInternal::KindLocal;
	}
	break;
	case DateTimeKind::Unspecified:
	{
		_dateData |= TimeInternal::KindUnspecified;
	}
	break;
	default:
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 지원하지 않는 DateTimeKind 입니다."));
		break;
	}
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second, int millisecond, DateTimeKind kind)
{
	if (false == TimeInternal::Validate(year, month, day, hour, minute, second, millisecond))
	{
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 파라미터로 넘어온 year, month, day, hour, minute, second, millisecond 가 이상합니다."));
	}

	_dateData = static_cast<unsigned __int64>(TimeInternal::DateToTicks(year, month, day) + TimeInternal::TimeToTicks(hour, minute, second, millisecond));

	switch (kind)
	{
	case DateTimeKind::Utc:
	{
		_dateData |= TimeInternal::KindUtc;
	}
	break;
	case DateTimeKind::Local:
	{
		_dateData |= TimeInternal::KindLocal;
	}
	break;
	case DateTimeKind::Unspecified:
	{
		_dateData |= TimeInternal::KindUnspecified;
	}
	break;
	default:
		//AMSG(_TEXT("JKBase::JKTime::DateTime Constructor Failed 지원하지 않는 DateTimeKind 입니다."));
		break;
	}
}

DateTime::~DateTime()
{
	_dateData = 0;
}

int DateTime::Year() const
{
	return TimeInternal::GetDatePart(_dateData, TimeInternal::DatePartYear);
}
int DateTime::Month() const
{
	return TimeInternal::GetDatePart(_dateData, TimeInternal::DatePartMonth);
}
int DateTime::Day() const
{
	return TimeInternal::GetDatePart(_dateData, TimeInternal::DatePartDay);
}
int DateTime::GetDayOfYear() const
{
	int year = Year();
	int month = Month();
	int day = Day();

	for (int CurrentMonth = 1; CurrentMonth < month; ++CurrentMonth)
	{
		day += TimeInternal::DaysInMonth(year, CurrentMonth);
	}

	return day;
}
int DateTime::Hour() const
{
	return static_cast<int>((TimeInternal::InternalTicks(_dateData) / TimeInternal::TicksPerHour) % 24);
}
int DateTime::GetHour12() const
{
	int hour = Hour();

	if (hour < 1)
	{
		return 12;
	}

	if (hour > 12)
	{
		return (hour - 12);
	}

	return hour;
}
int DateTime::Minute() const
{
	return static_cast<int>((TimeInternal::InternalTicks(_dateData) / TimeInternal::TicksPerMinute) % 60);
}
int DateTime::Second() const
{
	return static_cast<int>((TimeInternal::InternalTicks(_dateData) / TimeInternal::TicksPerSecond) % 60);
}
int DateTime::Millisecond() const
{
	return static_cast<int>((TimeInternal::InternalTicks(_dateData) / TimeInternal::TicksPerMillisecond) % 1000);
}
__int64 DateTime::Ticks() const
{
	return TimeInternal::InternalTicks(_dateData);
}
DateTimeKind DateTime::Kind() const
{
	switch (TimeInternal::InternalKind(_dateData))
	{
	case TimeInternal::KindLocal:
		return DateTimeKind::Local;
	case TimeInternal::KindUtc:
		return DateTimeKind::Utc;
	case TimeInternal::KindUnspecified:
	default:
		return DateTimeKind::Unspecified;
	}
}
DayOfWeek DateTime::DayOfWeek() const
{
	return static_cast<::DayOfWeek>((TimeInternal::InternalTicks(_dateData) / TimeInternal::TicksPerDay + 1) % 7);
}
DateTime DateTime::AddMonths(int months) const
{
	if (months < -120000 || months > 120000)
	{
		//AMSG(_TEXT(""));
	}

	int y, m, d;
	TimeInternal::GetDatePart(_dateData, y, m, d);

	int i = m - 1 + months;
	if (i >= 0)
	{
		m = i % 12 + 1;
		y = y + i / 12;
	}
	else
	{
		m = 12 + (i + 1) % 12;
		y = y + (i - 11) / 12;
	}
	if (y < 1 || y > 9999)
	{
		//AMSG(_TEXT(""));
	}
	int days = TimeInternal::DaysInMonth(y, m);
	if (d > days) d = days;
	DateTime ret;
	ret._dateData = (TimeInternal::DateToTicks(y, m, d) + TimeInternal::InternalTicks(_dateData)) | TimeInternal::InternalKind(_dateData);
	return ret;
}
DateTime DateTime::AddDays(double days) const
{
	DateTime ret;
	ret._dateData = TimeInternal::Add(_dateData, days, TimeInternal::MillisPerDay);
	return ret;
}
DateTime DateTime::AddHour(double hour) const
{
	DateTime ret;
	ret._dateData = TimeInternal::Add(_dateData, hour, TimeInternal::MillisPerHour);
	return ret;
}
DateTime DateTime::AddMinutes(double minutes) const
{
	DateTime ret;
	ret._dateData = TimeInternal::Add(_dateData, minutes, TimeInternal::MillisPerMinute);
	return ret;
}
DateTime DateTime::AddSeconds(double seconds) const
{
	DateTime ret;
	ret._dateData = TimeInternal::Add(_dateData, seconds, TimeInternal::MillisPerSecond);
	return ret;
}
DateTime DateTime::AddMillisecond(double millisecond) const
{
	DateTime ret;
	ret._dateData = TimeInternal::Add(_dateData, millisecond, 1);
	return ret;
}

bool DateTime::operator==(const DateTime& rhs) const
{
	return _dateData == rhs._dateData;
}

bool DateTime::operator!=(const DateTime& rhs) const
{
	return _dateData != rhs._dateData;
}

bool DateTime::operator<(const DateTime& rhs) const
{
	return _dateData < rhs._dateData;
}

bool DateTime::operator<=(const DateTime& rhs) const
{
	return _dateData <= rhs._dateData;
}

bool DateTime::operator>(const DateTime& rhs) const
{
	return _dateData > rhs._dateData;
}

bool DateTime::operator>=(const DateTime& rhs) const
{
	return _dateData >= rhs._dateData;
}

DateTime DateTime::UtcNow()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	return DateTime(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, DateTimeKind::Utc);
}

DateTime DateTime::Now()
{
	SYSTEMTIME st;
	GetLocalTime(&st);

	return DateTime(st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, DateTimeKind::Utc);
}

std::string DateTime::ToString() const
{
	return ToString("%y-%M-%d %h:%m:%s.%f");
}

std::string DateTime::ToString(const char* Format) const
{
	std::stringstream Result;

	while (*Format != '\0')
	{
		if ((*Format == '%') && (*++Format != '\0'))
		{
			switch (*Format)
			{
			case 'y': Result << Year(); break;
			case 'M': Result << Month(); break;
			case 'd': Result << Day(); break;
			case 'h': Result << Hour(); break;
			case 'm': Result << Minute(); break;
			case 's': Result << Second(); break;
			case 'f': Result << Millisecond(); break;
			default:
				Result << *Format;
			}
		}
		else
		{
			Result << *Format;
		}

		++Format;
	}

	return Result.str();
}