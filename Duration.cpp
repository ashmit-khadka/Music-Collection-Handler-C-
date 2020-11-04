//
// Created by Ashmit Khadka on 26/03/2019.
//

#include "Duration.h"
#include <iostream>

/*
 * Default constructor. Constructs duration object set to 0:00:00.
 */
Duration::Duration()
{
    this->hour =    0;
    this->minute =  0;
    this->second =  0;
}

/*
 * Takes integer arguments hour, minute, seconds, constructs object accordingly.
 */
Duration::Duration(int hour, int minute, int second)
{
     this->hour =       hour;
     this->minute =     minute;
     this->second =     second;
}

/*
 * Takes const string duration, constructs object accordingly. 
 * String format "h:mm:ss" e.g. "0:4:25".
 */
Duration::Duration(const std::string& duration)
{
    try
    {
        this->hour = std::stoi(duration.substr(0));
        this->minute = std::stoi(duration.substr(2,3));
        this->second = std::stoi(duration.substr(5,6));
    }
    catch(std::invalid_argument& e)
    {
      std::cerr << "Invalid argument " << duration << std::endl;
    }
    catch(std::out_of_range& e)
    {
      std::cerr << "Out of range " << duration << std::endl;
    }
    catch(...)
    {
      std::cerr << "Could not create Duration from" << duration << std::endl;
    }
}

/*
 * Takes integer argument seconds, constructs object accordingly. 
 */
Duration::Duration(int seconds){
    this->hour =    seconds / (60 * 60);
    this->minute =  (seconds - this->hour * 60 * 60) / 60;
    this->second =  seconds - (this->hour * 60 * 60) - (this->minute *60);
}

/*
 * Takes argument integer hour, sets hour instance variable.
 */
void Duration::setHour(int hour)
{
    this->hour = hour;
}

/*
 * Returns const integer, hour, of duration.
 */
int Duration::getHour() const
{
    return hour;
}

/*
 * Takes argument integer minute, sets minute instance variable.
 */
void Duration::setMinute(int minute)
{
    this->second = second;
}

/*
 * Returns const integer, minute, of duration.
 */
int Duration::getMinute() const
{
    return minute;
}

/*
 * Takes argument integer hour, sets hour instance variable.
 */
void Duration::setSecond(int second)
{
    this->second = second;
}

/*
 * Returns const integer, second, of duration.
 */
int Duration::getSecond() const
{
    return second;
}

/*
 * Takes argument const Duration d, appends d to this Duration. 
 */
void Duration::add(const Duration& d)
{
    this->setDuration(Duration(this->toSeconds()+d.toSeconds()));
}

/*
 * Takes argument const Duration d, decrements this Duration by d. 
 */
void Duration::minus(const Duration& d)
{
    this->setDuration(Duration(this->toSeconds()-d.toSeconds()));
}

/*
 * Takes argument integer hour, minute, second. Sets instance variables.
 * accordingly. 
 */
void Duration::setDuration(int hour, int minute, int second)
{
    this->hour =    hour;
    this->minute =  minute;
    this->second =  second;
}

/*
 * Takes argument const Duration d, Sets instance variables based on d.
 * accordingly. 
 */
void Duration::setDuration(const Duration& d){
    this->hour =    d.getHour();
    this->minute =  d.getMinute();
    this->second =  d.getSecond();
}

/*
 * Returns const integer of total seconds for Duration.
 */
int Duration::toSeconds() const {
    return this->getHour() * 60 * 60 + this->getMinute() * 60 + this->getSecond();
}


/*
 * Test harness.
 */
void Duration::test()
{
    Duration d1;
    Duration d2;
    Duration d3;

    std::cout << "Testing Duration Class:" << std::endl;
    
    /*
     * Testing default constructor Duration()
     */
    d1 = Duration();
    if (d1.getHour() == 0 && d1.getMinute() == 0 && d1.getSecond() == 0)
    {
        std::clog << "constructor Duration() pass" << std::endl;
    }
    else
    {
        std::cerr << "constructor Duration() fail" << std::endl;
    }
    
    /*
     * Testing constructor Duration(int hour, int minute, int second)
     */
    d1 = Duration(0, 3, 46);
    if (d1.getHour() == 0 && d1.getMinute() == 3 && d1.getSecond() == 46)
    {
        std::clog << "constructor Duration(int seconds) pass" << std::endl;
    }
    else
    {
        std::cerr << "constructor Duration(int seconds) fail" << std::endl;
    }
    
    /*
     * Testing constructor Duration(int seconds)
     */
    d1 = Duration(43544);
    if (d1.getHour() == 12 && d1.getMinute() == 5 && d1.getSecond() == 44)
    {
        std::clog << "constructor Duration(int seconds) pass" << std::endl;
    }
    else
    {
        std::cerr << "constructor Duration(int seconds) fail" << std::endl;
    }
        
    /*
     * Testing constructor Duration(std::string duration)
     */
    d1 = Duration("1:34:27");
    if (d1.getHour() == 1 && d1.getMinute() == 34 && d1.getSecond() == 27)
    {
        std::clog << "constructor Duration(std::string duration) pass" << std::endl;
    }
    else
    {
        std::cerr << "constructor Duration(std::string duration) fail" << std::endl;
    }

    /*
     * Testing method setDuration(int hour, int minute, int second) 
     */
    d1 = Duration();
    d1.setDuration(1,23,45);
    if (d1.getHour() == 1 && d1.getMinute() == 23 && d1.getSecond() == 45)
    {
        std::clog << "setDuration(int hour, int minute, int second) pass" << std::endl;
    }
    else
    {
        std::cerr << "setDuration(int hour, int minute, int second) fail" << std::endl;
    }
    
    /*
     * Testing method setDuration(const Duration& d){
     */
    d1 = Duration();
    d2 = Duration(1,23,45);
    d1.setDuration(d2);
    if (d1.getHour() == 1 && d1.getMinute() == 23 && d1.getSecond() == 45)
    {
        std::clog << "setDuration(const Duration& d) pass" << std::endl;
    }
    else
    {
        std::cerr << "setDuration(const Duration& d) fail" << std::endl;
    }
    
    
    
    /*
     * Testing method method 'add(Duration& d)'
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    d3 = Duration(0,5,9);
    d1.add(d2);
    if (d1 == d3)
    {
        std::clog << "method 'add(Duration& d)' pass" << std::endl;
    }
    else
    {
        std::cerr << "method 'add(Duration& d)' fail" << std::endl;
    }

    /*
     * Testing method method 'minus(Duration& d)'.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    d3 = Duration(0,0,59);
    d1.minus(d2);
    if ((d1) == d3){
        std::clog << "method 'minus(Duration& d)' pass" << std::endl;
    }
    else
    {
        std::cerr << "method 'minus(Duration& d)' fail" << std::endl;
    }

    /*
     * Testing the + operator.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    d3 = Duration(0,5,9);
    if ((d1 + d2) == d3){
        std::clog << "operator + pass" << std::endl;
    }
    else
    {
        std::cerr << "operator + fail" << std::endl;
    }


    /*
     * Testing the - operator.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    d3 = Duration(0,0,59);
    if ((d1 - d2) == d3){
        std::clog << "operator - pass" << std::endl;
    }
    else
    {
        std::cerr << "operator - fail" << std::endl;
    }


    /*
     * Testing the < operator.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    if (d2 < d1){
        std::clog << "operator < pass" << std::endl;
    }
    else
    {
        std::cerr << "operator < fail" << std::endl;
    }


    /*
     * Testing the > operator.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    if (d1 > d2){
        std::clog << "operator > pass" << std::endl;
    }
    else
    {
        std::cerr << "operator > fail" << std::endl;
    }


    /*
     * Testing the == operator.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,3,4);
    if (d1 == d2){
        std::clog << "operator == pass" << std::endl;
    }
    else
    {
        std::cerr << "operator == fail" << std::endl;
    }


    /*
     * Testing the != operator.
     */
    d1 = Duration(0,3,4);
    d2 = Duration(0,2,5);
    if (d1 != d2){
        std::clog << "operator != pass" << std::endl;
    }
    else
    {
        std::cerr << "operator != fail" << std::endl;
    }


    /*
     * Testing the << operator.
     */
    d1 = Duration(0,3,45);
    try
    {
        std::clog << d1 << " operator << pass" << std::endl;

    }
    catch (const std::exception& e)
    {
        std::cerr << "operator << fail" << std::endl;
    }

    /*
     * Testing the * operator.
     */
    d1 = Duration(0,3,45);
    d1 = d1*4;
    d1 = 5*d1;
    if (d1 == Duration(1,15,0))
    {
        std::clog << "operator * pass" << std::endl;

    }
    else
    {
        std::cerr << "operator * fail" << std::endl;
    }

    /*
     * Testing the / operator.
     */
    d1 = Duration(0,3,45);
    d1 = d1/9;
    d1 = 100/d1;
    if (d1 == Duration(0,0,4))
    {
        std::clog << "operator / pass" << std::endl;

    }
    else
    {
        std::cerr << "operator / fail" << std::endl;
    }

    std::cout << "testing operator >>" << std::endl;
    d1 = Duration();
    d1 >> 2;
}

