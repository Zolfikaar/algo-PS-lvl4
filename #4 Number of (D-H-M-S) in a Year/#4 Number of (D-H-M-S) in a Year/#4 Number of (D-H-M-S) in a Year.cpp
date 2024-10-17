#include <iostream>
using namespace std;

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int NumberOfDaysInYear(short year)
{
    return CheckLeapYear(year) ? 366 : 365;
}

int NumberOfHoursInYear(short year)
{
    return NumberOfDaysInYear(year) * 24;
}

int NumberOfMinutesInYear(short year)
{
    return NumberOfHoursInYear(year) * 60;
}

int NumberOfSecondsInYear(short year)
{
    return NumberOfMinutesInYear(year) * 60;
}

short ReadYear()
{
    short year;
    cout << "Please, Enter a Year to check: ";
    cin >> year;
    return year;
}

int main()
{
    short year = ReadYear();

    cout << "Number of Days in Year [" << year << "] is: " << NumberOfDaysInYear(year) << endl;
    cout << "Number of Hours in Year [" << year << "] is: " << NumberOfHoursInYear(year) << endl;
    cout << "Number of Minutes in Year [" << year << "] is: " << NumberOfMinutesInYear(year) << endl;
    cout << "Number of Seconds in Year [" << year << "] is: " << NumberOfSecondsInYear(year) << endl;
}
