//
// Created by Ashmit Khadka on 26/03/2019.
//

#ifndef INC_5015Y_CW2_DURATION_H
#define INC_5015Y_CW2_DURATION_H

#include <iostream>
#include <iomanip>

class Duration {

private:

    int hour;
    int minute;
    int second;

public:

    Duration();

    Duration
    (
            int hour,
            int minute,
            int second
    );

    Duration(const std::string& duration);

    Duration(int seconds);

    void setHour(int hour);

    int getHour() const;

    void setMinute(int minute);

    int getMinute() const;

    void setSecond(int second);

    int getSecond() const;

    void setDuration
    (
            int hour,
            int minute,
            int second
    );

    void setDuration(const Duration& newDuration);

    void add(const Duration& d);

    void minus(const Duration& d);

    int toSeconds() const;

    static void test();

};


inline std::ostream& operator<<(std::ostream& os, const Duration& d)
{
    os << d.getHour() << ":" << std::setfill('0') << std::setw(2) << d.getMinute() <<
        ":" << std::setfill('0') << std::setw(2) << d.getSecond();
    return os;
}


inline std::istream& operator>>(std::istream& is, int s)
{
    printf("%d\n", s);
    return is;
}

inline Duration operator+(const Duration& d1, const Duration& d2)
{
    return Duration(d1.toSeconds() + d2.toSeconds());
};

inline Duration operator-(const Duration& d1, const Duration& d2)
{
    return Duration(d1.toSeconds() - d2.toSeconds());
}

inline bool operator<(const Duration& d1, const Duration& d2)
{
    return d1.toSeconds()<d2.toSeconds();
}

inline bool operator>(const Duration& d1, const Duration& d2)
{
    return d1.toSeconds()>d2.toSeconds();
}

inline bool operator==(const Duration& d1, const Duration& d2)
{
    return d1.toSeconds()==d2.toSeconds();
}

inline bool operator!=(const Duration& d1, const Duration& d2)
{
    return d1.toSeconds()!=d2.toSeconds();
}

inline bool operator>=(const Duration& d1, const Duration& d2)
{
    return !(d1 < d2);
}

inline bool operator<=(const Duration& d1, const Duration& d2)
{
    return !(d1 > d2);
}

inline Duration operator*(const Duration& d, int n)
{
    return Duration(d.toSeconds()*n);
}

inline Duration operator*(int n, const Duration& d)
{
    return Duration(d.toSeconds()*n);
}

inline Duration operator/(const Duration& d, int n)
{
    return Duration(d.toSeconds()/n);
}

inline Duration operator/(int n, const Duration& d)
{
    return Duration(n/d.toSeconds());
}


#endif //INC_5015Y_CW2_DURATION_H
