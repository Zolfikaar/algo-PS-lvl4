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

sPeriod ReadPeriod()
{
    sPeriod Period;
    cout << "Enter Start Date:\n";
    Period.PeriodStart = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.PeriodEnd = ReadFullDate();
    return Period;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1LessThanDate2(sDate Date1, sDate Date2)
{
    // if the year1 less than year2 return true, else if the years are equal, check month1 if less than month2 return true, else if the months are equal, check if day1 is less than day2 return true, if not return false.
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
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

bool isOverlapPeriods(sPeriod Periode1, sPeriod Periode2)
{
    if (
        CompareDates(Periode2.PeriodEnd, Periode1.PeriodStart) == enDateCompare::Before
        ||
        CompareDates(Periode2.PeriodStart, Periode1.PeriodEnd) == enDateCompare::After
        )
        return false;
    else
        return true;
}

int main()
{
    cout << "Enter Period 1:\n";
    sPeriod Period1 = ReadPeriod();

    cout << "Enter Period 2:\n";
    sPeriod Period2 = ReadPeriod();


    bool Result = isOverlapPeriods(Period1, Period2);

    Result ? cout << "\nYes, Periods Overlap\n" : cout << "\nNo, Periods does NOT overlap\n";
}
