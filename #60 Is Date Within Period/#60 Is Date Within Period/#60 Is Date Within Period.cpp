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

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

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

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    // if the year1 less than year2 return true, else if the years are equal, check month1 if less than month2 return true, else if the months are equal, check if day1 is less than day2 return true, if not return false.
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

enDateCompare CompareDates(sDate Date1, sDate Date2)
{
    if (IsDate1LessThanDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    /* if (IsDate1AfterDate2(Date1,Date2))
    return enDateCompare::After;*/
    //this is faster
    return enDateCompare::After;
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

bool IsDateInPeriod(sPeriod Period, sDate Date)
{
    return !(
        CompareDates(Date, Period.PeriodStart) == enDateCompare::Before
        ||
        CompareDates(Date, Period.PeriodEnd) == enDateCompare::After
        );
}

int main()
{
    cout << "Enter Period:\n";
    sPeriod Period = ReadPeriod();

    cout << "\nEnter a date to check:\n";
    sDate Date = ReadFullDate();
    bool Result = IsDateInPeriod(Period, Date);

    (Result) ? cout << "\nYes, Date is within Period\n" : cout << "\nNo, Date is NOT within Period\n" << endl;
}
