#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

struct sPeriod
{
    sDate PeriodStart;
    sDate PeriodEnd;
};

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short ReadYear()
{
    short year;
    cout << "Please, Enter a Year to check: ";
    cin >> year;
    return year;
}

short ReadMonth()
{
    short Month;
    cout << "Please, Enter a Month: ";
    cin >> Month;
    return Month;
}

short ReadDay()
{
    short Day;
    cout << "Please, Enter a Day: ";
    cin >> Day;
    return Day;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

short NumberOfDaysInMonth(short year, short month)
{
    if (month < 1 || month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (CheckLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];

}

sDate IncreaseDateByOneDay(sDate Date)
{
    short MonthDaysCount = NumberOfDaysInMonth(Date.Year, Date.Month);

    if (Date.Day == MonthDaysCount) {
        if (Date.Month == 12) {
            Date.Year++;
            Date.Day = 1;
            Date.Month = 1;
        }
        else {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else {
        Date.Day++;
    }

    return Date;
}

bool CheckWhichDateIsLess(sDate Date1, sDate Date2)
{
    // if the year1 less than year2 return true, else if the years are equal, check month1 if less than month2 return true, else if the months are equal, check if day1 is less than day2 return true, if not return false.
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

int DifferenceBetweenTwoDates(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    while (CheckWhichDateIsLess(Date1, Date2)) {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }
    return IncludeEndDay ? ++Days : Days;
}

sPeriod ReadPeriod()
{
    sPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.PeriodStart = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.PeriodEnd = ReadFullDate();
    return Period;
}

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDate = false)
{
    return DifferenceBetweenTwoDates(Period.PeriodStart, Period.PeriodEnd, IncludeEndDate);
}

int main()
{
    cout << "Enter Period:\n";
    sPeriod Period = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLengthInDays(Period) << endl;
    cout << "Period Length (Including End Date) is: " << PeriodLengthInDays(Period, true) << endl;
}
