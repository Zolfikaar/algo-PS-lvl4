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

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length()); /* erase() until
        positon and move to next word. */
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}

string ReplaceWordInString(string S1, string StringToReplace,string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),
            sRepalceTo);
        pos = S1.find(StringToReplace);//find next
    }
    return S1;
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

string DateToString(sDate Date, string Format = "dd/mm/yyyy")
{
    string FormatedStrDate = "";

    FormatedStrDate = ReplaceWordInString(Format, "dd", to_string(Date.Day));
    FormatedStrDate = ReplaceWordInString(FormatedStrDate, "mm", to_string(Date.Month));
    FormatedStrDate = ReplaceWordInString(FormatedStrDate, "yyyy", to_string(Date.Year));

    return FormatedStrDate;
}

int main()
{

    string strDate = ReadDateAsString();
    sDate Date = StringToDate(strDate);
    
    cout << "\n" << DateToString(Date) << "\n";
    cout << "\n" << DateToString(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << DateToString(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << DateToString(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << DateToString(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << DateToString(Date, "Day:dd, Month:mm, Year: yyyy") << "\n";
}

