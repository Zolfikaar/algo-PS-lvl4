#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

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

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int NumberOfDaysInYear(short year)
{
    return CheckLeapYear(year) ? 366 : 365;
}

short NumberOfDaysInMonth(short year, short month)
{
    if (month < 1 || month > 12)
        return 0;

    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (CheckLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short NumberOfDaysFromYearBeginning(short year, short month, short day)
{
    short TotalCurrentDays = 0;

    for (short i = 1; i < month; i++)
    {
        TotalCurrentDays += NumberOfDaysInMonth(year, i);
    }

    TotalCurrentDays += day;
    return TotalCurrentDays;
}

sDate DateFromDaysNumber(short NumberOfDays, short year)
{
    sDate Date;
    Date.Year = year;
    Date.Month = 1;

    short TotalCurrentDays = NumberOfDays;
    short monthDays = 0;

    while (true)
    {
        monthDays = NumberOfDaysInMonth(year, Date.Month);

        if (TotalCurrentDays > monthDays)
        {
            TotalCurrentDays -= monthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = TotalCurrentDays;
            break;
        }
    }

    return Date;
}

int main()
{
    short day = ReadDay();
    short month = ReadMonth();
    short year = ReadYear();
    short numberOfDays = NumberOfDaysFromYearBeginning(year, month, day);
    sDate Date = DateFromDaysNumber(numberOfDays, year);

    cout << "Number of Days from the beginning of Year [" << year << "] to the date you enter is: " << numberOfDays << endl;
    cout << "Date of [" << numberOfDays << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}
