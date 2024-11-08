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

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1) {
        if (Date.Month == 1) {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else {
            Date.Month--;
            Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);;
        }
    }
    else {
        Date.Day--;

    }

    return Date;
}

sDate DecreaseDateByXDays(sDate Date, int AmountToDecreaseBy)
{
    for (short i = 1; i <= AmountToDecreaseBy; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    for (short i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }

    return Date;
}

sDate DecreaseDateByXWeeks(sDate Date, int AmountToDecreaseBy)
{
    for (short i = 1; i <= AmountToDecreaseBy; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 1) {
        Date.Month = 12;
        Date.Year--;
    }
    else {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

    if (Date.Day > NumberOfDaysInCurrentMonth) {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate DecreaseDateByXMonths(sDate Date, int AmountToDecreaseBy)
{
    for (short i = 1; i <= AmountToDecreaseBy; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYears(sDate Date, int AmountToDecreaseBy)
{
    for (short i = 1; i <= AmountToDecreaseBy; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, int AmountToDecreaseBy)
{
    Date.Year += AmountToDecreaseBy;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, int AmountToDecreaseBy)
{
    for (short i = 1; i <= AmountToDecreaseBy * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }

    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, int AmountToDecreaseBy)
{
    Date.Year -= AmountToDecreaseBy * 10;
    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100;
    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    sDate OneDay = DecreaseDateByOneDay(Date);
    sDate XDays = DecreaseDateByXDays(OneDay, 10);
    sDate OneWeek = DecreaseDateByOneWeek(XDays);
    sDate XWeeks = DecreaseDateByXWeeks(OneWeek, 10);
    sDate OneMonth = DecreaseDateByOneMonth(XWeeks);
    sDate XMonths = DecreaseDateByXMonths(OneMonth, 5);
    sDate OneYear = DecreaseDateByOneYear(XMonths);
    sDate XYears = DecreaseDateByXYears(OneYear, 10);
    sDate XYearsFaster = DecreaseDateByXYearsFaster(XYears, 10);
    sDate OneDecade = DecreaseDateByOneDecade(XYearsFaster);
    sDate XDecades = DecreaseDateByXDecades(OneDecade, 10);
    sDate XDecadesFaster = DecreaseDateByXDecadesFaster(XDecades, 10);
    sDate OneCentury = DecreaseDateByOneCentury(XDecadesFaster);
    sDate OneMillennium = DecreaseDateByOneMillennium(OneDecade);

    cout << "\nDate After:\n";
    cout << "\n01- Decrease One Day is: " << PrintDateAsString(OneDay) << endl;
    cout << "\n02- Decrease Ten Days is: " << PrintDateAsString(XDays) << endl;
    cout << "\n03- Decrease One Week is: " << PrintDateAsString(OneWeek) << endl;
    cout << "\n04- Decrease Ten Weeks is: " << PrintDateAsString(XWeeks) << endl;
    cout << "\n05- Decrease One Month is: " << PrintDateAsString(OneMonth) << endl;
    cout << "\n06- Decrease Five Months is: " << PrintDateAsString(XMonths) << endl;
    cout << "\n07- Decrease One Year is: " << PrintDateAsString(OneYear) << endl;
    cout << "\n08- Decrease Ten Years is: " << PrintDateAsString(XYears) << endl;
    cout << "\n09- Decrease Ten Years (Faster) is: " << PrintDateAsString(XYearsFaster) << endl;
    cout << "\n10- Decrease One Decade is: " << PrintDateAsString(OneDecade) << endl;
    cout << "\n11- Decrease Ten Decades is: " << PrintDateAsString(XDecades) << endl;
    cout << "\n12- Decrease Ten Decades (Faster) is: " << PrintDateAsString(XDecadesFaster) << endl;
    cout << "\n13- Decrease One Century is: " << PrintDateAsString(OneCentury) << endl;
    cout << "\n14- Decrease One Millennium is: " << PrintDateAsString(OneMillennium) << endl;
}
