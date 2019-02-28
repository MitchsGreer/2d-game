#include "map.h"


    //constructors
    Map::Map()
    {
        Coordinates c(1,1);
        //this should make the whole map grass
        for(int i = 0; i < Map_y_Max; ++i)
        {
            for(int j = 0; j < Map_x_Max; ++j)
            {
                this->set_identity(i, j, GRASS);
                this->set_passable(i, j, true);
                this->set_image_location(i, j, c);
            }
        }
        //sets tile 5,5 as a rock
        c.setx(3);
        c.sety(10);
        this->set_identity(5, 5, ROCK);
        this->set_passable(5, 5, false);
        this->set_image_location(5, 5, c);
    }
    /*
    Map::Map(FILE * infile)
    {

    }
    */
   
    //destructors
    Map::~Map()
    {
        //does not need to do anythning
    }

    //getters
    Identifier Map::get_identity(int x, int y)
    {
        return  this->map[y][x].get_identity();
    }
    bool Map::get_passable(int x, int y)
    {
        return this->map[y][x].get_passable();
    }
    Coordinates Map::get_image_location(int x, int y)
    {
        return this->map[y][x].get_coordinates();
    }

    //setters
    void Map::set_identity(int x, int y, Identifier identity)
    {
        this->map[y][x].set_identity(identity);
    }
    void Map::set_passable(int x, int y, bool passable)
    {
        this->map[y][x].set_passable(passable);
    }
    void Map::set_image_location(int x, int y, Coordinates image_location)
    {
        this->map[y][x].set_coordinates(image_location);
    }

    //needed to make a change