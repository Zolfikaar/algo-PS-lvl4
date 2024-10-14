#include <iostream>
using namespace std;

bool CheckLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else {
        return false;
    }
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
