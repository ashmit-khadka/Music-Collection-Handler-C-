//
// Created by Ashmit Khadka on 26/03/2019.
//

#ifndef INC_5015Y_CW2_COLLECTION_H
#define INC_5015Y_CW2_COLLECTION_H

#include <vector>
#include "Album.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include "Track.h"
#include "Duration.h"

class Collection {

private:

    std::vector<Album*>* albums;

public:

    Collection();

    ~Collection();

    Collection(std::vector<Album*>* albums);

    void addAlbum(Album* album);

    bool readCollection(const std::string &path);

    const std::vector<Album*>& getAlbums();

    void sortCollection();
    
    unsigned long size();

    void display();

    static void test();

};

/*
 * Used for selection sort.
 */
template <typename T>
void swap (T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}



#endif //INC_5015Y_CW2_COLLECTION_H
