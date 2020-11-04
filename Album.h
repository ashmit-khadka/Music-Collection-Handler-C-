//
// Created by Ashmit Khadka on 26/03/2019.
//

#ifndef INC_5015Y_CW2_ALBUM_H
#define INC_5015Y_CW2_ALBUM_H

#include <iostream>
#include <algorithm>
#include <vector>
#include "Track.h"

class Album {

private:

    std::string title;
    std::string artist;
    std::vector<Track*>* tracks;
    Duration duration;

public:

    Album
            (
                    const std::string& title,
                    const std::string& artist
            );

    Album
            (
                    const std::string& title,
                    const std::string& artist,
                    std::vector<Track*>* tracks
            );

    ~Album();

    void setTitle(const std::string& title);

    std::string getTitle() const;

    void setArtist(const std::string& artist);

    std::string getArtist() const;

    bool addTrack(Track* track);

    bool removeTrack(unsigned int i);

    const std::vector<Track*>& getTracks() const;

    Duration getDuration () const;

    unsigned long size();

    Track* operator[](int index);

    static void test();

};

inline std::ostream& operator<<(std::ostream& os, const Album& a)
{
    os << a.getArtist() << " : " << a.getTitle() << std::endl;
    return os;
}


inline bool operator<(const Album& a1, const Album& a2)
{
    if(a1.getArtist() != a2.getArtist())
    {            
        return a1.getArtist() < a2.getArtist();
    }
    return a1.getTitle() < a2.getTitle();
}

inline bool operator==(const Album& a1, const Album& a2)
{
    return a1.getTitle() == a2.getTitle() && a1.getArtist() == a2.getArtist();
}





#endif //INC_5015Y_CW2_ALBUM_H
