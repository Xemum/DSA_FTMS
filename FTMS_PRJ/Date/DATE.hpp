//
//  DATE.hpp
//  FTMS_PROJECT
//
//  Created by youcef mhammdi on 01/12/2023.
//

#ifndef DATE_hpp
#define DATE_hpp
#include <iostream>
using std::cout;
using std::endl;

class Date
{
public:
    // Interface

    // Constructor
    Date(int year = 1900, int month = 1, int day = 1);

    // Copy constructor
    Date(const Date& d);

    // Destructor
    ~Date();

    // Getter methods
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

    // Setter methods
    void SetYear(int year);
    void SetMonth(int month);
    void SetDay(int day);

    // Operator overloads
    Date& operator=(const Date& d);
    Date& operator+=(int day);
    Date operator+(int day);
    Date& operator-=(int day);
    Date operator-(int day);
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    bool operator>(const Date& d);
    bool operator==(const Date& d);
    bool operator>=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator!=(const Date& d);
    int operator-(const Date& d);
    void Print() const;


private:
    int _year;
    int _month;
    int _day;
    int GetMonthDay(int year, int month)const;
};
#endif


