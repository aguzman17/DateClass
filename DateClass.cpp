#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		Date();
		Date(int, int, int);
		void setMonth(int);
		void setDay(int);
		void setYear(int);
		void printDate();

		int daysMonth(int, int);
		int firstDay(int,int);
};
//Default constructor sets date to 1, 1, 2001.
Date::Date()
{
	month = 1;
	day = 1;
	year = 2001;
}
//Constructor sets month to m, day to d, and year to y.
Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}
//Setter for month.
void Date::setMonth(int m)
{
	month = m;

}
//Setter for day.
void Date::setDay(int d)
{
	day = d;
}
//Setter for year.
void Date::setYear(int y)
{
	year = y;
}
//Gives three different formats to the dates.
void Date::printDate()
{
	cout << month << " /" << day << " /" << year << "\n";
	string monthName[12] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	cout << monthName[month - 1] << "  " << day << "  "
		<< year << "\n";
	cout << day << "  " << monthName[month - 1] << "  "
		 << year << "\n\n";


}
//Determines how many days a month has.
int Date::daysMonth(int mm, int year)
{
	int mDays;

	//Determines how many days february has depending if
	//is a leap year.

	if (mm == 2)
	{
		if (year % 100 == 0 && year % 400 == 0 || year % 4 == 0)
			mDays = 29;
		else
			mDays = 28;
	}

	else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
		mDays = 30;
	else
		mDays = 31;

	return mDays;
}
//Tells the first day of the month for an specific date
int Date::firstDay(int month, int year) 
{
		int dow = 0;
		int day = 1;

		int mm[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
		year -= month < 3;
		dow = (year + year / 4 - year / 100 + year / 400 + mm[month - 1] + day) % 7;

		return dow;
}

int main()
{
	int month;
	int day;
	int year;

	string monthName[] = { "January", "February", "March",
						   "April", "May", "June", "July",
						   "August", "September", "October",
						   "November", "December" };
	cout << "\nPlease enter a month, it must be betwwen 1 - 12 "
		<< "\n";
	cin >> month;

	//validation for the month
	while (month < 1 || month > 12)
	{

		cout << "\nERROR insert a valid month: \n";
		cin >> month;
	}

	cout << "\nPlease enter a day, it must be between 1 - 31 "
		<< "\n";
	cin >> day;

	//validation for the day
	while (day < 1 || day > 31)
	{
		cout << "\nERROR insert a valid day: \n";
		cin >> day;

	}

	//validation for february
	while (month == 2 && day > 29)
	{
		cout << "\nERROR insert a valid day: \n";
		cin >> day;
	}

	cout << "\nPlease enter a year, it must be between 1500 - 2050 "
		<< "\n";
	cin >> year;
	cout << endl;

	//validation for the year
	while (year < 1500 || year > 2050)
	{
		cout << "\nERROR insert a valid year: \n\n";
		cin >> year;
		cout << endl;
	}

	//calls the class and gives perimeters to the functions of
	//that class.

	Date newDate(month, day, year);

	newDate.printDate();
	
	cin.get();

	return 0;
}
