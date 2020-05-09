//
//  main.cpp
//  class2
//
//  Created by junyeong on 2018. 4. 6..
//  Copyright © 2018년 junyeong. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

class DayOfYear
{
public:
    DayOfYear(int monthValue, int dayValue);
    DayOfYear(int monthValue);
    DayOfYear();
    void input();
    void output();
    int getMonthNumebr();
    int getDay();
private:
    int month;
    int day;
    void testDate();
};

class Holiday
{
public:
    Holiday();
    Holiday(int month, int day, bool theEnforcement);
    void output();
private:
    DayOfYear date;
    bool parkingEnforcement;
};

int main()
{
    Holiday h(2, 14, true);
    cout << "testing the class Holiday.\n";
    h.output();
    return 0;
}

Holiday::Holiday() : date(1, 1), parkingEnforcement(false)
{}

Holiday::Holiday(int month, int day, bool theEnforcement)
: date(month, day), parkingEnforcement(theEnforcement)
{}

void Holiday::output()
{
    date.output();
    cout <<  endl;
    if (parkingEnforcement)
        cout << "parking laws will be enforced.\n";
    else
        cout << "parking alws will not be enforced.\n";
}

DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue)
{
    testDate();
}

void DayOfYear::testDate()
{
    if((month < 1) || (month > 12))
    {
        cout << "illegal month value.\n";
        exit(1);
    }
    if ((day < 1)|| (day > 31))
    {
        cout << "illegal date value.\n";
        exit(1);
    }
    
    
}

void DayOfYear::output()
{
    switch (month)
    {
        case 1:
            cout << "january";
            break;
        case 2:
            cout << "february";
            break;
        case 3:
            cout << " march";
            break;
        case 4:
            cout << "april";
            break;
        case 5:
            cout << "may";
            break;
            case 6:
            cout << "june";
            break;
        case 7:
            cout << " july" ;
            break;
        case 8:
            cout << "august";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "october";
            break;
        case 11:
            cout << "november";
            break;
        case 12:
            cout << "december";
            break;
            default:
            cout << " error in DayOfYear::output";
    }
    cout << day;
}
