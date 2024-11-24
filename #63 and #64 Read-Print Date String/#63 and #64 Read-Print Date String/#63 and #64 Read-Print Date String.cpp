#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct sDate
{
    short Day;
    short Month;
    short Year;
};

string ReadDateAsString()
{
    string Date;
    cout << "\nEnter a date as string (dd/mm/yyyy):\n";
    cin >> Date;
    return Date;
}

vector <string> SplitString(string S, string Delim)
{
    vector <string> vString;

    short pos = 0;
    string sWord;

    // use find function to get the position of the delimeter
    while ((pos = S.find(Delim)) != string::npos)
    {
        sWord = S.substr(0, pos); // store the word

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S.erase(0, pos + Delim.length()); // erase until position and move to next word
    }

    if (S != "")
        vString.push_back(S); // print last word in the string

    return vString;
}

sDate StringToDate(string strDate)
{
    sDate Date;
    vector <string> vDate;

    vDate = SplitString(strDate, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(sDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
    
    string strDate = ReadDateAsString();
    sDate Date = StringToDate(strDate);

    cout << "Day: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Tear: " << Date.Year << endl;

    cout << "You Entered: " << strDate << endl;
}

