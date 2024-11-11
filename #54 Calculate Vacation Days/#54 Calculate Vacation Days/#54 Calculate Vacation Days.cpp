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

    short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

short GetDayIndex(sDate Date)
{
    return GetDayIndex(Date.Year, Date.Month, Date.Day);
}

string GetDayName(short DayIndex)
{
    string DaysNames[] = { "Sunday", "Monday", "Tuesday", "Wendsday", "Thursday", "Friday", "Saturday" };

    return DaysNames[DayIndex];
}

bool IsEndOfWeek(short DayIndex)
{
    return DayIndex == 6;
}

bool IsEndOfWeek(sDate Date)
{
    return GetDayIndex(Date) == 6;
}

bool IsWeekend(short DayIndex)
{
    return DayIndex == 5 || DayIndex == 6;
}

bool IsWeekend(sDate Date)
{
    short DayIndex = GetDayIndex(Date);
    return DayIndex == 5 || DayIndex == 6;
}

bool IsBusinessDay(short DayIndex)
{
    return !IsWeekend(DayIndex);
}

bool IsBusinessDay(sDate Date)
{
    return !IsWeekend(Date);
}

short GetDayCountUntilEndOfMonth(sDate Date)
{
    short DaysInMonthCount = NumberOfDaysInMonth(Date.Year, Date.Month);
    return DaysInMonthCount - Date.Day;
}

short GetDayCountUntilEndOfYear(sDate Date)
{
    short TotalDayRemainOfYear = 0;
    short DaysInCurrentMonthCount = NumberOfDaysInMonth(Date.Year, Date.Month);
    TotalDayRemainOfYear = DaysInCurrentMonthCount - Date.Day;

    for (short i = Date.Month + 1; i <= 12; i++)
    {
        TotalDayRemainOfYear += NumberOfDaysInMonth(Date.Year, i);
    }

    return TotalDayRemainOfYear;
}

short GetActualVacationDays(sDate Date1, sDate Date2)
{
    short TotalVacationDays = 0;

    //If the dates are both in the same year and month, we just need to calculate the days.
    if (Date1.Year == Date2.Year && Date1.Month == Date2.Month) {

        for (short i = Date1.Day; i <= Date2.Day; i++)
        {
            short currentDayIndex = GetDayIndex(Date1.Year,Date1.Month,i);
            if(!IsWeekend(currentDayIndex)){
                TotalVacationDays++;
            }

        }
    }
    // eg(Month).. from 25/9/2024 to 2/10/2024 = 6 days | 4 days from September, 2 days from October
    // eg(Year).. from 25/12/2024 to 5/1/2025 = 8 days | 5 days from 2024, 3 days from 2025
    else { 
        short endOfStartMonth = NumberOfDaysInMonth(Date1.Year, Date1.Month);

        for (short i = Date1.Day; i <= endOfStartMonth; i++)
        {
            short currentDayIndex = GetDayIndex(Date1.Year, Date1.Month, i);
            if (!IsWeekend(currentDayIndex)) {
                TotalVacationDays++;
            }

        }

        for (short i = 1; i <= Date2.Day; i++)
        {
            short currentDayIndex = GetDayIndex(Date2.Year, Date2.Month, i-1);
            if (!IsWeekend(currentDayIndex)) {
                TotalVacationDays++;
            }

        }

    }
        
    return TotalVacationDays;
}

bool CheckWhichDateIsLess(sDate Date1, sDate Date2)
{
    // if the year1 less than year2 return true, else if the years are equal, check month1 if less than month2 return true, else if the months are equal, check if day1 is less than day2 return true, if not return false.
    return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    short MonthDaysCount = NumberOfDaysInMonth(Date.Year, Date.Month);

    if (Date.Day == MonthDaysCount) {
        if (Date.Month == 12) {
            Date.Year++;
            Date.Day = 1;
            Date.Month = 1;
        }
        else {
            Date.Month++;
            Date.Day = 1;
        }
    }
    else {
        Date.Day++;
    }

    return Date;
}

//short CalculateVacationDays(sDate Date1, sDate Date2)
//{
//    short DaysCount = 0;
//
//    while (CheckWhichDateIsLess(Date1, Date2))
//    {
//        if (IsBusinessDay(Date1))
//            DaysCount++;
//
//        Date1 = IncreaseDateByOneDay(Date1);
//    }
//
//    return DaysCount;
//}

int main()
{
    cout << "Vacation Start:" << endl;
    sDate VacationStartDate = ReadFullDate();

    cout << "\nVacation End:" << endl;
    sDate VacationEndDate = ReadFullDate();


    short VacationStartDayIndex = GetDayIndex(VacationStartDate.Year, VacationStartDate.Month, VacationStartDate.Day);
    string VacationStartDayName = GetDayName(VacationStartDayIndex);

    short VacationEndDayIndex = GetDayIndex(VacationEndDate.Year, VacationEndDate.Month, VacationEndDate.Day);
    string VacationEndDayName = GetDayName(VacationEndDayIndex);


    cout << "\nVacation From: " << VacationStartDayName << ", " << VacationStartDate.Day << "/" << VacationStartDate.Month << "/" << VacationStartDate.Year << endl;
    cout << "\nVacation End: " << VacationEndDayName << ", " << VacationEndDate.Day << "/" << VacationEndDate.Month << "/" << VacationEndDate.Year << endl;

    short ActualVacationDays = GetActualVacationDays(VacationStartDate, VacationEndDate); // my function (correct 100%)
    //short ActualVacationDays = CalculateVacationDays(VacationStartDate, VacationEndDate); // Abo-Hadhoud function (decrement by one day)

    cout << "\nActual Vacation Day(s): " << ActualVacationDays << endl;
}
