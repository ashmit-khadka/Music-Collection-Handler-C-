//
// Created by Ashmit Khadka on 26/03/2019.
//

#include "Album.h"

/*
 * Takes arguments const string title, artist, constructs Track object
 * accordingly.
 */
Album::Album(const std::string &title, const std::string &artist)
{
    this->title =   title;
    this->artist =  artist;
    tracks =        new std::vector<Track*>;
}

/*
 * Takes arguments const string title, artist and vector<Track*> tracks.
 */
Album::Album(const std::string &title, const std::string &artist, std::vector<Track*>* tracks)
{
    this->title =   title;
    this->artist =  artist;
    this->tracks =  tracks;
    
    for (Track* track : *tracks)
    {
        duration.add(track->getDuration());
    }
}

/*
 * Destructor, deletes all tracks in tracks.
 */
Album::~Album(){
    for (std::vector<Track*>::iterator track = tracks->begin() ; track != tracks->end(); ++track)
    {
        delete (*track);
    }
    tracks->clear();
}

/*
 * Takes argument const string title, sets title instance variable.
 */
void Album::setTitle(const std::string& title)
{
    this->title = title;
}

/*
 * Returns const string, title, of Album.
 */
std::string Album::getTitle() const
{
    return title;
}

/*
 * Takes argument const string artist, sets title instance variable.
 */
void Album::setArtist(const std::string &artist)
{
    this->artist = artist;
}

/*
 * Returns const string, artist, of Album.
 */
std::string Album::getArtist() const
{
    return artist;
}

/*
 * Takes argument Track* track, adds track pointer to tracks and 
 * increments duration accordingly
 */
bool Album::addTrack(Track *track)
{
    /*
    if (std::find(tracks->begin(), tracks->end(), &track) != tracks->end())
    {
        return false;
    }*/

    tracks->push_back(track);
    duration.add(track->getDuration());
    //std::cout << tracks->size() << std::endl;
    return true;
}

/*
 * Takes argument integer unsigned int i, removes track pointer from tracks and
 * decrements duration accordingly.
 */
bool Album::removeTrack(unsigned int i)
{
    if (i > tracks->size())
    {
       return false;
    }
    duration.minus(tracks->at(i)->getDuration());
    tracks->erase(tracks->begin()+i);
    return true;
}

/*
 * Returns const Duration, duration, of Album 
 */
Duration Album::getDuration() const
{
    return duration;
}
/*
 * Returns const std::vector<Track*> &Album, tracks, of Album
 */
const std::vector<Track*> &Album::getTracks() const
{
    return *tracks;
}

/*
 * Returns const std::vector<Track*> &Album, tracks, of Album
 */
unsigned long Album::size()
{
    return tracks->size();
}

/*
 * Takes in argument integer index, Returns Track* at position index in Tracks. 
 */
Track* Album::operator[](int index)
{
    if (index > tracks->size())
    {
        std::cout << "track index out of bounds" << std::endl;
        return nullptr;
    }
    else
    {
        return tracks->operator[](index);
    }

}


void Album::test()
{
    std::clog << "Testing Album:" << std::endl;
    
    Album *a1;
    std::string title = "test_title";
    std::string artist = "test_artist";
    std::vector<Track*> tracklist;
    
   /*
    * Testing constructor Album(const std::string &title, const std::string &artist)
    */    
    a1 = new Album(title, artist);
    if (a1->getTitle() == title && a1->getArtist() == artist)
    {
        std::clog << "constructor Album(const std::string &title, const std::string &artist) pass." << std::endl;
    }
    else
    {
        std::cerr << "constructor Album(const std::string &title, const std::string &artist) fail." << std::endl;
    }
    delete(a1);

    /*
     * Testing constructor Album(const std::string &title, const std::string &artist, std::vector<Track*>* tracks)
     */    
    tracklist = {new Track("",Duration())};    
    a1 = new Album(title, artist, &tracklist);
    if (a1->getTitle() == title && a1->getArtist() == artist && a1->getTracks().size() == 1)
    {
        std::clog << "constructor Album(const std::string &title, const std::string &artist, std::vector<Track*>* tracks) pass." << std::endl;
    }
    else
    {
        std::cerr << "constructor Album(const std::string &title, const std::string &artist, std::vector<Track*>* tracks) fail." << std::endl;
    }
    delete(a1); //deletes all tracks in album.
    

    /*
     * Testing method addTrack(Track* track)
     */    
    a1 = new Album(title, artist);
    a1->addTrack(new Track("test", Duration()));
    if (a1->getTracks().size() == 1)
    {
        std::clog << "method addTrack(Track* track) pass." << std::endl;
    }
    else
    {
        std::cerr << "method addTrack(Track* track) fail." << std::endl;
    }
    delete(a1);
    
    
    /*
     * Testing method removeTrack(unsigned int i);
     */
    a1 = new Album(title, artist);
    a1->addTrack(new Track("test", Duration()));
    a1->addTrack(new Track("test2", Duration()));
    a1->addTrack(new Track("test3", Duration()));    
    a1->removeTrack(1);
    if (a1->getTracks().size() == 2)
    {
        std::clog << "method removeTrack(unsigned int i) pass." << std::endl;
    }
    else
    {
        std::cerr << "method removeTrack(unsigned int i) fail." << std::endl;
    }
    delete(a1);
        

    /*
     * Testing method std::vector<Track*>& getTracks() const;
     */
    tracklist =
    {
        new Track("test", Duration()),
        new Track("test2", Duration()),
        new Track("test3", Duration())
    };
    a1 = new Album(title, artist, &tracklist);
    if (a1->getTracks() == tracklist)
    {
        std::clog << "method std::vector<Track*>& getTracks()) pass." << std::endl;
    }
    else
    {
        std::cerr << "method std::vector<Track*>& getTracks()) fail." << std::endl;
    }
    delete(a1);
    
    
    /*
     * Testing method getDuration();
     */
    tracklist =
    {
        new Track("test", Duration(0,2,0)),
        new Track("test2", Duration(0,2,0)),
        new Track("test3", Duration(0,2,0))
    };
    a1 = new Album(title, artist, &tracklist);
    if (a1->getDuration() == Duration(0,6,0))
    {
        std::clog << "method getDuration() pass." << std::endl;
    }
    else
    {
        std::cerr << "method getDuration() fail." << std::endl;
    }
    delete(a1);
    
    /*
     * Testing method size();
     */
    tracklist =
    {
        new Track("test", Duration(0,2,0)),
        new Track("test2", Duration(0,2,0)),
        new Track("test3", Duration(0,2,0))
    };
    a1 = new Album(title, artist, &tracklist);
    if (a1->size() == 3)
    {
        std::clog << "method size() pass." << std::endl;
    }
    else
    {
        std::cerr << "method size() fail." << std::endl;
    }
    delete(a1);
    
    /*
     * Testing operator[](int index);
     */
    a1 = new Album(title, artist, &tracklist);
    if (a1[0].getTitle() == title)
    {
        std::clog << "operator[](int index) pass." << std::endl;
    }
    else
    {
        std::cerr << "operator[](int index) fail." << std::endl;
    }
    delete(a1);


 
}