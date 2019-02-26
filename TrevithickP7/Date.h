//James Trevithick					jtrevithick2@cnm.edu					TrevithickP7

#ifndef _DATE_H
#define _DATE_H

#include <string>
using namespace std;

	class Date
	{
		private:
				int month, day, year;
				string description;
				int dayOfYear;
				bool bLeap;
				void CalcDayOfYear();
				void DetermineLeapYear();

		public:
				Date();
				Date(int m, int d, int y, string desc);
				void SetDate(int m, int d, int y, string desc);
				void SetDesc(string d){ description = d; }

				string GetFormattedDate();

				int GetDayOfYear(){ return dayOfYear;}
				int GetYear(){ return year;}
				int GetMonth(){ return month;}
				int GetDay(){ return day;}
				bool isLeapYear(){ return bLeap; }

				//later accurrence in year
				bool operator > (Date &d);
				//earlier accurrence
				bool operator <(Date &d);
				//later in time
				bool operator >> (Date &d);
				//earlier in time
				bool operator<<(Date &d);
				//compare month and day
				bool operator == (Date &d);
				//compare descriptions
				bool operator +(Date &d);
	};

#endif