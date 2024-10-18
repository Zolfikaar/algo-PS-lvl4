#include <iostream>
using namespace std;

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumberOfDaysInMonth(short year, short month)
{
    if (month < 1 || month > 12)
        return 0;

    if (month == 2) {
        return CheckLeapYear(year) ? 29 : 28;
    }

    short arrMonthsOf31Days[7] = { 1,3,5,7,8,10,12 };
    for (short i = 1; i <= 7; i++) {
        if (arrMonthsOf31Days[i-1] == month)
            return 31;
    }

    return 30;
}

short NumberOfHoursInMonth(short year, short month)
{
    return NumberOfDaysInMonth(year, month) * 24;
}

int NumberOfMinutesInMonth(short year, short month)
{
    return NumberOfHoursInMonth(year, month) * 60;
}

int NumberOfSecondsInMonth(short year, short month)
{
    return NumberOfMinutesInMonth(year, month) * 60;
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
    cout << "Please, Enter a Month to check: ";
    cin >> Month;
    return Month;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();

    cout << "Number of Days in month [" << month << "] is: " << NumberOfDaysInMonth(year, month) << endl;

    cout << "Number of Hours in month [" << month << "] is: " << NumberOfHoursInMonth(year, month) << endl;
    cout << "Number of Minutes in month [" << month << "] is: " << NumberOfMinutesInMonth(year, month) << endl;
    cout << "Number of Seconds in month [" << month << "] is: " << NumberOfSecondsInMonth(year, month) << endl;
}
