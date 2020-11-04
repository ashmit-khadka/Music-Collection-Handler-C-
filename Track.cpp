//
// Created by Ashmit Khadka on 26/03/2019.
//

#include "Track.h"

/*
 * Takes arguments string title and const Duration duration, constructs Track.
 *  object accordingly.
 */
Track::Track(const std::string &title, const Duration &duration)
{
    this->title =       title;
    this->duration =    duration;

}

/*
 * Takes argument const string title, sets title instance variable.
 */
void Track::setTitle(const std::string &title)
{
    this->title = title;
}

/*
 * Returns const string, title, of duration.
 */
std::string Track::getTitle() const
{
    return title;
}

/*
 * Takes argument const duration, sets duration instance variable.
 */
void Track::setDuration(const Duration &duration)
{
    this->duration = duration;
}

/*
 * Returns const Duration, duration, of track.
 */
Duration Track::getDuration() const
{
    return duration;
}

/*
 * Test harness.
 */
void Track::test()
{
    
    /*
     * Testing constructor Track(const std::string &title, const Duration &duration)
     */
    std::string name = "test_name";
    Duration d1 = Duration(0,1,23);
    Track t1 = Track(name, d1);
    if (t1.getTitle() == name && t1.getDuration() == d1)
    {
        std::clog << "constructor Track(const std::string &title, const Duration &duration) pass." << std::endl;
    }
    else
    {
        std::cerr << "constructor Track(const std::string &title, const Duration &duration) fail." << std::endl;
    }
    
    
}