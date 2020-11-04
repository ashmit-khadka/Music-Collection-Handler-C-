#include <iostream>
#include <iomanip>
#include "Duration.h"
#include "Track.h"
#include "Collection.h"
#include "Album.h"


int main() {
    
//       
//    Collection c; //specify the default constructor.
//
//   /*
//    * Task 1: Read in a Collection from the file albums.txt, provided via BlackBoard
//    */
//    std::cout << "\nTask 1" << std::endl;
//    if (!c.readCollection("albums.txt"))
//    {
//        std::cout << "Couldn't read file" << std::endl;
//    }
//    else
//    {
//        c.display();
//    }
//
//    /*
//     * Task 2: Display the entire album Collection, arranged in alphabetical order of the album artist.
//     * If more than one album exists for a given artist, they should be displayed in alphabetical order
//     * of the album title.
//     */
//    std::cout << "\nTask 2" << std::endl;
//    c.sortCollection();
//    c.display();
//
//    /*
//     * Task 3: Display the total play time of all Pink Floyd albums in the collection.
//     */
//    std::cout << "\nTask 3" << std::endl;
//    Duration task3;
//    for (Album *album : c.getAlbums()){
//        if (album->getArtist() == "Pink Floyd")
//        {
//            task3.add(album->getDuration());
//        }
//    }
//    std::cout << task3 << std::endl;
//    
//    /*
//     * Task 4: Display the album with the largest number of tracks.
//     */
//    std::cout << "\nTask 4" << std::endl;
//    Album *largestAlbum = c.getAlbums().front();
//    for (Album *album : c.getAlbums()){
//        if (album->size() > largestAlbum->size())
//        {
//            largestAlbum = album;
//        }
//    }
//    std::cout << *largestAlbum;
//
//
//    /*
//     * Task 5: Display the details of the longest track in the album collection.
//    */
//    std::cout << "\nTask 5" << std::endl;
//    Track *longestTrack = c.getAlbums().front()->getTracks().front();
//    for (Album *album : c.getAlbums()){
//        for(Track *track : album->getTracks()){
//            if (track->getDuration() > longestTrack->getDuration())
//            {
//                longestTrack = track;
//            }
//        }
//    }
//    std::cout << *longestTrack;
//    
    
    Duration::test();
    //Track::test();
    //Album::test();
    //Collection::test();
    
    
    return EXIT_SUCCESS;
}