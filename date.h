#pragma once
#include <iostream>

class Date
{
private:
    int day;
    int month;
    int year;

    bool isLeap(int year);
    bool isValidDate(int d, int m, int y);

public:
    friend std::istream &operator>>(std::istream &is, Date &dt)
    {
        do
        {
            is >> dt.year >> dt.month >> dt.day;
        } while (!dt.isValidDate(dt.day, dt.month, dt.year));

        return is;
    }
    friend std::ostream &operator<<(std::ostream &out, const Date &dt)
    {
        out << dt.year << "-" << dt.month << "-" << dt.day;
        return out;
    }

    int operator-(const Date &);
};