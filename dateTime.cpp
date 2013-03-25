#include <ctime>
#include <iostream>
#include <string>
#include <cmath>


#include "date.hpp"
#include "dateTime.hpp"

using namespace std;



DateTime :: DateTime(void):	Date(),
							hour(timeinfo->tm_hour),
							minute(timeinfo->tm_min),
							second(timeinfo->tm_sec)
{}


DateTime :: DateTime(int d,int m, int y, int h, int min, int s) :	
							Date(d,m,y),
							hour(h),
							minute(min),
							second(s)
{}


DateTime :: DateTime(const DateTime & dt):
							Date(dt.day,dt.month,dt.year),
							hour(dt.hour),
							minute(dt.minute),
							second(dt.second)
{}



ostream & operator << (ostream &output, DateTime &dt)
{
	output << dt.hour << ":" <<  (dt.minute< 10 ? "0" : "") << dt.minute << ":" << dt.second << "    ";
	output << dt.day << "." <<  dt.month << "." << dt.year << endl;
	return output;
}


bool operator < (DateTime &dt1,DateTime &dt2)
{
	if (dt1.year != dt2.year) return dt1.year < dt2.year;
	if (dt1.month != dt2.month) return dt1.month < dt2.month;
	if (dt1.day != dt2.day) return dt1.day < dt2.day;
	if (dt1.hour != dt2.hour) return dt1.hour < dt2.hour;
	if (dt1.minute != dt2.minute) return dt1.minute < dt2.minute;
	if (dt1.second != dt2.second) return dt1.second < dt2.second;
	return false;
}


bool operator == (DateTime &dt1,DateTime &dt2)
{
	return (dt1.year != dt2.year ||
		dt1.month != dt2.month ||
		dt1.day != dt2.day ||
		dt1.hour != dt2.hour || 
		dt1.minute != dt2.minute ||
		dt1.second != dt2.second) ;
}


bool operator != (DateTime &dt1,DateTime &dt2)
{
	return !(dt1 == dt2);
}


bool operator >= (DateTime &dt1,DateTime &dt2)
{
	return !(dt1 < dt2);
}


bool operator > (DateTime &dt1,DateTime &dt2)
{
	return (dt1 >= dt2) && dt1 != dt2; 
}


bool operator <= (DateTime &dt1,DateTime &dt2)
{
	return !(dt1 > dt2);
}