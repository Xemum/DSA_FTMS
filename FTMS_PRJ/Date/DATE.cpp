#include "DATE.hpp"




    int Date::GetMonthDay(int year, int month)const
    {
        static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int days = monthDays[month];
        if ((month == 2 && (year % 4 == 0 && year % 100 != 0)) || year % 400 == 0)
        {
            return 29;
        }
        return days;
    }

Date::Date(int year , int month , int day )
    {
        if (year >= 0 && month > 0 && month < 13
            && day > 0 && day <= GetMonthDay(year, month))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            throw "not a valid date";
        }
    }


Date::Date(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    // equal operator
    Date& Date::operator=(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
        return *this;
    }

    //destructure
Date::~Date()
    {
        _year = 0;
        _month = 0;
        _year = 0;
    }


    //add equal operator
    Date& Date::operator+=(int day)
    {
        if (day < 0)
        {
            *this -= -day;
            return *this;
        }
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            _day -= GetMonthDay(_year, _month);
            _month++;
            if (_month == 13)
            {
                _year++;
                _month = 1;
            }
        }
        return *this;
    }


    // plus operator
    Date Date::operator+(int day)
    {
        Date ret(*this); // retreive the current stat
        ret += day;
        return ret;
    }


    //minus
    Date& Date::operator-=(int day)
    {
        if (day < 0)
        {
            *this += -day;
            return *this;
        }
        _day -= day;
        while (_day <= 0)
        {
            _day += GetMonthDay(_year, _month);
            _month--;
            if (_month == 0)
            {
                _year--;
                _month = 12;
            }
        }
        return *this;
    }


    Date Date::operator-(int day)
    {
        Date ret(*this);
        ret -= day;
        return ret;
    }


    // post order ++
    Date& Date::operator++()
    {
        *this += 1;
        return *this;
    }


    // pre order ++
    Date Date::operator++(int)
    {
        Date ret(*this);
        *this += 1;
        return ret;
    }


    // post order --
    Date& Date::operator--()
    {
        *this -= 1;
        return *this;
    }

    //pre order --
    Date Date::operator--(int)
    {
        Date ret(*this);
        *this += 1;
        return ret;
    }


    // > operator
    bool Date::operator>(const Date& d)
    {
        if ((_year > d._year)
            || (_year == d._year && _month > d._month)
            || (_year == d._year && _month == d._month && _day > d._day))
        {
            return true;
        }
        return false;
    }


    // == operator
    bool Date::operator==(const Date& d)
    {
        return (_year == d._year)
            && (_month == d._month)
            && (_day == d._day);
    }


    // >= operator
    inline bool Date::operator >= (const Date& d)
    {
        return *this > d || *this == d;
    }

    // < operator
    bool Date::operator < (const Date& d)
    {
        return !(*this >= d);
    }

    // <= operator
    bool Date::operator <= (const Date& d)
    {
        return !(*this > d);
    }


    // != operator
    bool Date::operator != (const Date& d)
    {
        return !(*this == d);
    }


    // date- another date
    int Date::operator-(const Date& d)
    {
        int flag = -1;
        int count = 0;
        Date min = *this;
        Date max = d;

        if (*this > d)
        {
            flag = 1;
            min = d;
            max = *this;
        }

        while (min < max)
        {
            ++min;
            ++count;
        }
        return count * flag;
    }


    // printer
    void Date::Print()const
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }


// Getter methods
int Date::GetYear() const{
    return _year;
};
int Date::GetMonth() const{
    return _month;
};
int Date::GetDay() const{
    return _day;
};

// Setter methods
void Date::SetYear(int year){
    if (year >= 0)
    {
        _year = year;
    }
    else
    {
        throw "not a valid year";
    }
};
void Date::SetMonth(int month){
    if ( month > 0 && month < 13)
    {
        _month = month;
    }
    else
    {
        throw "not a valid month";
    }
};
void Date::SetDay(int day){
    if (day > 0 && day <= GetMonthDay(_year,_month))
    {
        _day = day;
    }
    else
    {
        throw "not a valid day";
    }
};
