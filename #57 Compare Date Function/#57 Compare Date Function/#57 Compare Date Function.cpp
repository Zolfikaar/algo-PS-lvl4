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

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool isDate1LessThanDate2(sDate Date1, sDate Date2)
{
    // if the year1 less than year2 return true, else if the years are equal, check month1 if less than month2 return true, else if the months are equal, check if day1 is less than day2 return true, if not return false.
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

short compareTwoDates(sDate Date1, sDate Date2)
{
    return IsDate1EqualDate2(Date1, Date2) ? 0 : isDate1LessThanDate2(Date1, Date2) ? 1 : -1;
}



int main()
{
    cout << "Enter Date1:\n";
    sDate Date1 = ReadFullDate();
    cout << "\nEnter Date2:\n";
    sDate Date2 = ReadFullDate();

    short Result = compareTwoDates(Date1, Date2);
    cout << "\nCompare Result:\n";
    cout << Result << endl;

}
