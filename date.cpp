#include <ctime>
#include <iostream>
#include <string>
#include <cmath>

#include "date.hpp"

using namespace std;

time_t Date :: t = time(0);
tm * Date :: timeinfo = localtime( &Date::t ); 


int Date::days_in_month[2][13] =
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwyk³e
	{0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestêpne
};


int Date::dfboty[2][13] =
{
	{0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwyk³e
	{0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestêpne
};


Date :: Date(void) : day(timeinfo->tm_mday),
					 month(1+timeinfo->tm_mon),
					 year(1900+timeinfo->tm_year)
{	
}


Date :: Date(const Date& date) : day(date.day), month(date.month), year(date.year)
{
}


Date::Date(int d, int m, int y) : day(d), month(m), year(y) 
{
	if(!this->check_date()) throw string("This date is nov valid with gregorian calendar.");
}


bool Date::is_leap_year(int year)
{
	if(year % 400 == 0) return true;
	if(year % 100 == 0) return false;
	return year % 4 == 0;
}


bool Date::check_date(void)
{
	return  this->day > 0 &&
			this->day <= this->days_in_month[Date::is_leap_year(this->year)][this->month] &&
			this->month > 0 &&
			this->month < 13 &&
			this->year > 1581;
}


double Date::days(void) const // data liczona od 1 stycznia roku 0
{
	int y1,y2;
	y1 = ceil((double)this->year/4) - ceil((double)this->year/100) + ceil((double)this->year/400);
	y2 = this->year - y1;
	return y1*366 + y2*365 + this->dfboty[Date::is_leap_year(this->year)][this->month-1] + this->day;
}


double Date::days_from_to(const Date& date1, const Date& date2)
{

	return date2.days() - date1.days(); 
}

