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

short GetDayIndex(sDate Date)
{
    return GetDayIndex(Date.Year, Date.Month, Date.Day);
}

string GetDayName(short DayIndex)
{
    string DaysNames[] = {"Sunday", "Monday", "Tuesday", "Wendsday", "Thursday", "Friday", "Saturday"};

    return DaysNames[DayIndex];
}

sDate DateFromDaysNumber(short NumberOfDays, short year)
{
    sDate Date;
    Date.Year = year;
    Date.Month = 1;

    short TotalCurrentDays = NumberOfDays;
    short monthDays = 0;

    while (true)
    {
        monthDays = NumberOfDaysInMonth(year, Date.Month);

        if (TotalCurrentDays > monthDays)
        {
            TotalCurrentDays -= monthDays;
            Date.Month++;
        }
        else
        {
            Date.Day = TotalCurrentDays;
            break;
        }
    }

    return Date;
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

int main()
{
    sDate Date = ReadFullDate();

    short DayIndex = GetDayIndex(Date.Year, Date.Month, Date.Day);
    string DayName = GetDayName(DayIndex);
    bool EndOfWeek = IsEndOfWeek(DayIndex);
    bool WeekEnd = IsWeekend(DayIndex);
    bool BusinessDay = IsBusinessDay(DayIndex);
    short DayCountUntilEndOfWeek = 6 - DayIndex;
    short DayCountUntilEndOfMonth = GetDayCountUntilEndOfMonth(Date);
    short DayCountUntilEndOfYear = GetDayCountUntilEndOfYear(Date);

    cout << "\nToday is: " << DayName << ", ";
    cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    cout << "\nIs it the end of the week?" << endl;
    if (EndOfWeek)
        cout << "Yes, Its the end of the week" << endl;
    else
        cout << "Not, Its NOT the end of the week" << endl;

    cout << "\nIs it the weekend?" << endl;
    if (WeekEnd)
        cout << "Yes, Its the Weekend" << endl;
    else
        cout << "Not, Its NOT the Weekend" << endl;

    cout << "\nIs it a Business Day?" << endl;
    if (BusinessDay)
        cout << "Yes, Its a Business Day" << endl;
    else
        cout << "Not, Its NOT a Business Day" << endl;

    cout << "\nDays until the end of the week: " << DayCountUntilEndOfWeek << " Day(s)." << endl;
    cout << "Days until the end of the month: " << DayCountUntilEndOfMonth << " Day(s)." << endl;
    cout << "Days until the end of the year: " << DayCountUntilEndOfYear << " Day(s)." << endl;
}
