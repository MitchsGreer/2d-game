#pragma once
#include "tile.h"

class Map
{
public:

    //constructors
    Map();
   // Map(FILE * infile);

    //destructors
    ~Map();

    //getters
    Identifier get_identity(int x, int y);
    bool get_passable(int x, int y);
    Coordinates get_image_location(int x, int y);

    //setters
    void set_identity(int x, int y, Identifier identity);
    void set_passable(int x, int y, bool passable);
    void set_image_location(int x, int y, Coordinates image_location);

private:
    Tile map[Map_y_Max][Map_x_Max];
};

//needed to make a change