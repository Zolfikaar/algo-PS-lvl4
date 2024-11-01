#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
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

bool CheckIfLastDayInMonth(sDate Date)
{
    short monthDaysCount = NumberOfDaysInMonth(Date.Year,Date.Month);
    return (Date.Day == monthDaysCount);
}

bool CheckIfLastMonthInYear(short Month)
{
    return (Month == 12);
}

int main()
{
    sDate Date = ReadFullDate();
    bool isLastDayInMonth = CheckIfLastDayInMonth(Date);
    bool isLastMonthInYear = CheckIfLastMonthInYear(Date.Month);

    if (isLastDayInMonth)
        cout << "\nYes, The day is the last day in month\n";
    else
        cout << "\nNo, The day is NOT the last day in month\n";

    if (isLastMonthInYear)
        cout << "\nYes, The month is the last month in year\n";
    else
        cout << "\nNo, The month is NOT the last month in year\n";
}
