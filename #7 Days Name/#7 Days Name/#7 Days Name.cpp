#include <iostream>
using namespace std;

short ReadYear()
{
    short year;
    cout << "Please, Enter a Year: ";
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
    short Month;
    cout << "Please, Enter a Day: ";
    cin >> Month;
    return Month;
}

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumberOfDaysInMonth(short year, short month)
{
    if (month < 1 || month > 12)
        return 0;

    short NumberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (CheckLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

short GetDayIndex(short year, short month, short day)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string GetDayName(short DayIndex)
{
    string DaysNames[] = {"Sunday", "Monday", "Tuesday", "Wendsday", "Thursday", "Friday", "Saturday"};

    return DaysNames[DayIndex];
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();

    short DayIndex = GetDayIndex(year, month, day);
    string DayName = GetDayName(DayIndex);

    cout << "Date: " << day << "/" << month << "/" << year << endl;
    cout << "Day Order: " << DayIndex << endl;
    cout << "Day Name: " << DayName << endl;
}
