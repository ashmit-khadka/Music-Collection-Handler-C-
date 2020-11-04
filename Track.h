//
// Created by Ashmit Khadka on 26/03/2019.
//

#ifndef INC_5015Y_CW2_TRACK_H
#define INC_5015Y_CW2_TRACK_H

#include <iostream>
#include "Duration.h"

class Track {

private:

    std::string title;
    Duration duration;

public:

    Track(
            const std::string& title,
            const Duration& duration
            );

    void setTitle(const std::string& title);

    std::string getTitle() const;

    void setDuration(const Duration& duration);

    Duration getDuration() const;

    static void test();
};

inline std::ostream& operator<<(std::ostream& os, const Track& t)
{
    os << t.getDuration() << " - " << t.getTitle() << std::endl;
    return os;
}


#endif //INC_5015Y_CW2_TRACK_H
