#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

bool CheckLeapYear(int year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
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

string PrintDateAsString(sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

short NumberOfDaysInMonth(short year, short month)
{
    if (month < 1 || month > 12)
        return 0;

    short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    return (month == 2) ? (CheckLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];

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

sDate IncreaseDateByXDays(sDate Date, int AmountToIncreaseBy)
{
    for (short i = 1; i <= AmountToIncreaseBy; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

sDate IncreaseDateByXWeeks(sDate Date, int AmountToIncreaseBy)
{
    for (short i = 1; i <= AmountToIncreaseBy; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 12) {
        Date.Month = 1;
        Date.Year++;
    }
    else {
        Date.Month++;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year,Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate IncreaseDateByXMonths(sDate Date, int AmountToIncreaseBy)
{
    for (short i = 1; i <= AmountToIncreaseBy; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
    if (CheckLeapYear(Date.Year) && Date.Month == 2 && Date.Day == 29)
    {
        Date.Year++;
        Date.Month = 2;
        Date.Day = 28;
        return Date;
    }
    else
    {
        Date.Year++;
        return Date;
    }
}

sDate IncreaseDateByXYears(sDate Date, int AmountToIncreaseBy)
{
    for (short i = 1; i <= AmountToIncreaseBy; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

sDate IncreaseDateByXYearsFaster(sDate Date, int AmountToIncreaseBy)
{
    Date.Year += AmountToIncreaseBy;
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{   
    Date.Year += 10;
    return Date;   
}

sDate IncreaseDateByXDecades(sDate Date, int AmountToIncreaseBy)
{
    for (short i = 1; i <= AmountToIncreaseBy * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

sDate IncreaseDateByXDecadesFaster(sDate Date, int AmountToIncreaseBy)
{
    Date.Year += AmountToIncreaseBy * 10;
    return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    sDate OneDay = IncreaseDateByOneDay(Date);
    sDate XDays = IncreaseDateByXDays(OneDay, 10);
    sDate OneWeek = IncreaseDateByOneWeek(XDays);
    sDate XWeeks = IncreaseDateByXWeeks(OneWeek,10);
    sDate OneMonth = IncreaseDateByOneMonth(XWeeks);
    sDate XMonths = IncreaseDateByXMonths(OneMonth, 5);
    sDate OneYear = IncreaseDateByOneYear(XMonths);
    sDate XYears = IncreaseDateByXYears(OneYear, 10);
    sDate XYearsFaster = IncreaseDateByXYearsFaster(XYears, 10);
    sDate OneDecade = IncreaseDateByOneDecade(XYearsFaster);
    sDate XDecades = IncreaseDateByXDecades(OneDecade, 10);
    sDate XDecadesFaster = IncreaseDateByXDecadesFaster(XDecades, 10);
    sDate OneCentury = IncreaseDateByOneCentury(XDecadesFaster);
    sDate OneMillennium = IncreaseDateByOneMillennium(OneDecade);

    cout << "\nDate After:\n";
    cout << "\n01- Adding One Day is: " << PrintDateAsString(OneDay) << endl;
    cout << "\n02- Adding Ten Days is: " << PrintDateAsString(XDays) << endl;
    cout << "\n03- Adding One Week is: " << PrintDateAsString(OneWeek) << endl;
    cout << "\n04- Adding Ten Weeks is: " << PrintDateAsString(XWeeks) << endl;
    cout << "\n05- Adding One Month is: " << PrintDateAsString(OneMonth) << endl;
    cout << "\n06- Adding Five Months is: " << PrintDateAsString(XMonths) << endl;
    cout << "\n07- Adding One Year is: " << PrintDateAsString(OneYear) << endl;
    cout << "\n08- Adding Ten Years is: " << PrintDateAsString(XYears) << endl;
    cout << "\n09- Adding Ten Years (Faster) is: " << PrintDateAsString(XYearsFaster) << endl;
    cout << "\n10- Adding One Decade is: " << PrintDateAsString(OneDecade) << endl;
    cout << "\n11- Adding Ten Decades is: " << PrintDateAsString(XDecades) << endl;
    cout << "\n12- Adding Ten Decades (Faster) is: " << PrintDateAsString(XDecadesFaster) << endl;
    cout << "\n13- Adding One Century is: " << PrintDateAsString(OneCentury) << endl;
    cout << "\n14- Adding One Millennium is: " << PrintDateAsString(OneMillennium) << endl;
}
