#ifndef DATETIME_HPP
#define DATETIME_HPP

#include <iostream>
#include <string>

#include "date.hpp"
using namespace std;

class DateTime : public Date
{
	public:
		const int hour,minute,second;
		DateTime(void);
		DateTime(int,int,int,int,int,int);
		DateTime(const DateTime&);

		friend ostream & operator << (ostream &output, DateTime &dt);
};

class EventPair
{
	public:
		DateTime date_time;
		string pair_event;

		EventPair(void) : date_time(DateTime()),pair_event("") {}
		EventPair(DateTime dt,string s) : date_time(dt),pair_event(s){}
		DateTime first(void) {return date_time;}
		string second(void) {return pair_event;}
};


#endif