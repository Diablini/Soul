

#pragma once

#include <string>

using namespace std;

enum Month
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December,
	NumOfMonths
};

string MonthToString (Month mo)
{
	switch (mo)
	{
	case January: return "January";
		break;
	case February: return "February";
		break;
	case March: return "March";
		break;
	case April: return "April";
		break;
	case May: return "May";
		break;
	case June: return "June";
		break;
	case July: return "July";
		break;
	case August: return "August";
		break;
	case September: return "September";
		break;
	case October: return "October";
		break;
	case November: return "November";
		break;
	case December: return "December";
		break;
	default: throw "Wrong month token";
		break;
	}

}

struct Year
{
	Year(size_t which)
	{
		bool leap;
		if (which % 4 == 0 || which % 1000 != 0) leap = true;
		Monthdays[January] = 31;
		Monthdays[March] = 31;
		Monthdays[April] = 30;
		Monthdays[May] = 31;
		Monthdays[June] = 30;
		Monthdays[July] = 31;
		Monthdays[August] = 31;
		Monthdays[September] = 30;
		Monthdays[October] = 31;
		Monthdays[November] = 30;
		Monthdays[December] = 31;
		if (leap) Monthdays[February] = 29;
		else Monthdays[February] = 28;
		year = which;
	}

	size_t dayCount()
	{
		size_t res = 0;
		for (size_t i = 0; i < NumOfMonths; i++)
		{
			res += Monthdays[i];
		}
		return res;
	}

	size_t year;
	size_t Monthdays [NumOfMonths];
};

struct Date
{
	Date(size_t d, Month m, size_t y)
	{
		day = d; month = m; year = y;
	}

	string toString()
	{
		return to_string(day) + "." + MonthToString(month) + "." + to_string(year);
	}

	size_t day;
	Month month;
	size_t year;


};


size_t timeInDays(Date from, Date to)
{
	if (from.year > to.year ||
		(from.year == to.year && from.month > to.month) ||
		(from.year == to.year && from.month == to.month &&
		from.day > to.day))
	{
		// swap dates
		Date buffer = from;
		from = to;
		to = buffer;
	}

	size_t daycount = 0;
	Year fromyear(from.year);
	Year toyear(to.year);

	daycount += fromyear.Monthdays[from.month] - from.day;
	for(size_t i = from.month + 1; i < NumOfMonths; i++)
	{
		daycount += fromyear.Monthdays[i];
	}

	for(size_t i = from.year + 1; i < to.year; i++)
	{
		Year temp(i);
		daycount += temp.dayCount();
	}

	for (size_t i = January; i < to.month; i++)
	{
		daycount += toyear.Monthdays[i];
	}
	
	for (size_t i = 0; i < to.day; i++)
	{
		daycount++;
	}
	return daycount;
	
}