#pragma once
#include "Coordinates.h"

#define Map_x_Max 10
#define Map_y_Max 10

typedef enum Identifier
{
    NONE, GRASS, DIRT, SHRUB, TREE, ROCK, PUDDLE, FINISH, START, PLAYER
};

class Tile
{
public:
    //constructors
    //default
    Tile();
    //nondefault
    Tile(bool passing, Coordinates location, Identifier newdata);

    //destructor
    ~Tile();

    //getters
    Identifier get_identity();
    bool get_passable(void);
    Coordinates get_coordinates(void);

    //settrs
    void set_identity(Identifier newdata);
    void set_passable(bool newdata);
    void set_coordinates(Coordinates newdata);

private:

    Identifier identity;
    bool passable;
    Coordinates image_location;
    int width;
    int height;
    Coordinates location;
};

//needed to make a change