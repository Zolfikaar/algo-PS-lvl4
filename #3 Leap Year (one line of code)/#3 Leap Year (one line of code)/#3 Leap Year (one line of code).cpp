#include <iostream>
using namespace std;

bool CheckLeapYear(int year)
{
    //return (year % 400 == 0) ? true : (year % 100 == 0) ? false : (year % 4 == 0) ? true : false; // valid
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0); // valid, with better performance
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
    if (CheckLeapYear(year))
        cout << "Yes, year [" << year << "] is a Leap year";
    else
        cout << "No, year [" << year << "] is Not a Leap year";
}
