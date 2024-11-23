#include <iostream>
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

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumberOfDaysInMonth(short year, short month)
{
    if (month < 1 || month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (CheckLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];

}

bool IsValidDate(sDate Date)
{
    return (Date.Month > 12 || Date.Day > NumberOfDaysInMonth(Date.Year, Date.Month)) ? false : true;
}

int main()
{
    cout << "\nEnter a date to check:\n";
    sDate Date = ReadFullDate();
    bool Result = IsValidDate(Date);

    (Result) ? cout << "\nYes, Date is Valid\n" : cout << "\nNo, Date is NOT Valid\n" << endl;
}
