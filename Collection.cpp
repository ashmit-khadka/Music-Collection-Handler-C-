//
// Created by Ashmit Khadka on 26/03/2019.
//

#include "Collection.h"

/*
 * Default constructor, creates new Collection object.
 */
Collection::Collection()
{
    albums = new std::vector<Album*>;
}


/*
 * Takes arguments vector<Album*>, creates collection object accordingly.
 *  object accordingly.
 */
Collection::Collection(std::vector<Album*>* albums)
{
    this->albums = albums;
}

/*
 * Destructor for Collection, deletes all track pointers in tracks.
 */
Collection::~Collection()
{
    for (std::vector<Album*>::iterator album = albums->begin() ; album != albums->end(); ++album)
    {
        delete (*album);
    }
    albums->clear();
}

/*
 * Takes argument Album*, adds it to albums.
 */
void Collection::addAlbum(Album *album)
{
    albums->push_back(album);
}

/*
 * Takes argument const string path, reads file path initizles collection.
 */
bool Collection::readCollection(const std::string &path)
{
    std::string lineBuffer;
    std::string splitL;
    std::string splitR;
    std::size_t pos;
    std::string albumDelimeter = " : ";
    std::string trackDelimeter = " - ";

    std::ifstream collection(path);


    if (collection)
    {
        while ( getline(collection,lineBuffer) )
        {
            if ((pos = lineBuffer.find(albumDelimeter)) != std::string::npos)
            {
                splitL = lineBuffer.substr(0, pos);
                splitR = lineBuffer.substr(pos+albumDelimeter.length(), lineBuffer.length());
                albums->push_back(new Album(splitR, splitL));
            }
            else if ((pos = lineBuffer.find(trackDelimeter)) != std::string::npos)
            {
                splitL = lineBuffer.substr(0, pos);
                splitR = lineBuffer.substr(pos+trackDelimeter.length(), lineBuffer.length());
                albums->back()->addTrack(new Track(splitR, Duration(splitL)));
            }
        }
        collection.close();
        return true;
    }
    else
    {
        std::cerr << "Error: unable to open input file" << std::endl;
        return false;
    }
}


/*
 * Returns const vector<Album*>, album, in collection.
 */
const std::vector<Album*>& Collection::getAlbums()
{
    return *albums;
}

/*
 * Uses selection sort to albums in albums.
 */
void Collection::sortCollection()
{
    int n = albums->size();
    int i, j, k;

    for (i = 0; i < n-1; i++)
    {
        k = i;
        for (j = i+1; j < n; j++)
        {
            if (*albums->at(j) < *albums->at(k))
            {
                k = j;
            }
        }
        swap(&albums->at(k), &albums->at(i));
    }
}

/*
 * Returns unsigned long, size, of albums.
 */
unsigned long Collection::size()
{
    return albums->size();
}


void Collection::display()
{
    for(Album* a : *albums)
    {
        std::cout << *a;
        for (Track* t : a->getTracks())
        {
            std::cout << *t;
        }
    }
}



void Collection::test()
{
    std::clog << "Testing Collection:" << std::endl;
    
    Collection* c;
    std::vector<Album*> albums;
    /*
     *  Testing constructor Collection()
     */
    try
    {
        c = new Collection(); 
        std::clog << "Constructor Collection() pass." << std::endl;
    }
    catch (...)
    {
        std::cerr << "Constructor Collection() fail." << std::endl;
    }
    delete(c);
    
    /*
     *  Testing constructor Collection(const std::vector<Album*> albums)
    */
    albums = {new Album("test", "test")};
    c = new Collection(&albums); 
    if (c->size() == 1)
    {
        std::clog << "Constructor Collection(const std::vector<Album*> albums) pass." << std::endl;
    }
    else
    {
        std::cerr << "Constructor Collection(const std::vector<Album*> albums) fail." << std::endl;
    }
    delete(c);   
   
    /*
     *  Testing method addAlbum(Album* album)
     */
    c = new Collection(); 
    c->addAlbum(new Album("test", "test"));
    if (c->size() == 1)
    {
        std::clog << "method addAlbum(Album* album) pass." << std::endl;
    }
    else
    {
        std::cerr << "method addAlbum(Album* album) fail." << std::endl;
    }
    delete(c);
    
    /*
     *  Testing method readCollection(const std::string &path)
     */
    c = new Collection();    
    if (c->readCollection("albums.txt") && c->size() > 1)
    {
        std::clog << "method readCollection(const std::string &path) pass." << std::endl;
    }
    else
    {
        std::cerr << "method readCollection(const std::string &path) fail." << std::endl;
    }
    delete(c);
    
    
    /*
     *  Testing method std::vector<Album*>& getAlbums()
     */
    albums = {new Album("test", "test")};
    c = new Collection(&albums); 
    if (c->getAlbums() == albums)
    {
        std::clog << "method std::vector<Album*>& getAlbums() pass." << std::endl;
    }
    else
    {
        std::cerr << "method std::vector<Album*>& getAlbums() fail." << std::endl;
    }
    delete(c); 
    
     
    /*
     *  Testing method sortCollection()
     */
    
    albums = 
    {
        new Album("a", "a"),
        new Album("z", "b"),
        new Album("a", "b")
    };
    c = new Collection(&albums); 
    c->sortCollection();   

    if (*c->getAlbums()[0] == Album("a", "a") && *c->getAlbums()[2] == Album("z", "b"))
    {
        std::clog << "method sortCollection() pass." <<  std::endl;
    }
    else
    {
        std::cerr << "method sortCollection() fail." << *c->getAlbums()[1] << std::endl;
    }
    delete(c); 
}

