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

short ReadDaysToAdd()
{
    short Day;
    cout << "Please, Enter a Days to Add: ";
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

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

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

sDate AddDaysToDate(short Days, sDate Date)
{
    short RemainingDays = Days;
    short MonthDays = 0;

    // Continue to add days until all RemainingDays are added
    while (RemainingDays > 0)
    {
        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);

        if (RemainingDays > MonthDays - Date.Day) {
            // Calculate remaining days after the current month
            RemainingDays -= (MonthDays - Date.Day + 1);
            Date.Day = 1;  // Start from the first day of the next month
            Date.Month++;  // Move to the next month

            if (Date.Month > 12) {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else {
            // Add remaining days to the current day
            Date.Day += RemainingDays;
            RemainingDays = 0; // All remaining days are added
        }
    }

    return Date;
}


// My function
//sDate AddDaysToDate(short Days, sDate Date)
//{
//    short RemainingDays = Days;
//    short MonthDays = 0;
//
//    while (true)
//    {
//        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
//
//        if (RemainingDays > MonthDays) {
//            RemainingDays -= MonthDays;
//
//            if (RemainingDays > MonthDays) {
//                Date.Month++; //
//            }
//
//            if (Date.Month > 12)
//            {
//                Date.Month = 1;
//                Date.Year++;
//            }
//        }
//        else {
//            
//            Date.Day += RemainingDays;
//
//            if (Date.Day > MonthDays) {
//                Date.Day -= MonthDays;
//                Date.Month++;
//                break;
//            }            
//            
//        }
//
//    }
//
//    return Date;
//}

// Abu-Hadhuod function's
//sDate AddDaysToDate(short Days, sDate Date)
//{
//    short RemainingDays = Days; +NumberOfDaysFromYearBeginning(Date.Year, Date.Month, Date.Day);
//    short MonthDays = 0;
//    Date.Month = 1;
//
//    while (true)
//    {
//        MonthDays = NumberOfDaysInMonth(Date.Year, Date.Month);
//
//        if (RemainingDays > MonthDays) {
//            RemainingDays -= MonthDays;
//            Date.Month++;
//
//            if (Date.Month > 12)
//            {
//                Date.Month = 1;
//                Date.Year++;
//            }
//        }
//        else {
//            Date.Day = RemainingDays;
//            break;
//        }
//
//    }
//
//    return Date;
//}

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = AddDaysToDate(Days, Date);

    cout << "Date after adding [" << Days << "] days is: ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    // test cases
    // 13/9/2024 + 20[days] = 3/10/2024
    // 10/10/2022 + 2500[days] = 14/8/2029
}
