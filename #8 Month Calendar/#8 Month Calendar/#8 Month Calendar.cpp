#include <iostream>
using namespace std;

string MonthsName[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
string DaysName[] = { "Sun", "Mon","Tue","Wen","Thur","Fri","Sat" };

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

short GetDayIndex(short year, short month, short day)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

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

void PrintMonthCalendar(short year, short month)
{
    short currentDayIndex = GetDayIndex(year, month, 1);
    string monthName = MonthsName[month - 1];
    short monthDaysNumber = NumberOfDaysInMonth(year, month);

    printf("\n--------------- %s -----------------\n\n", monthName.c_str());
    printf("  Sun  Mon  Tue  Wen  Thur  Fri  Sat\n");

    short i;
    for (i = 0; i < currentDayIndex; i++)
        printf("     ");

    for (short j = 1; j <= monthDaysNumber; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }

    cout << "\n------------------------------------\n" << endl;
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    PrintMonthCalendar(year, month);
}
