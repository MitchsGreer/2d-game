#pragma once
#include "Coordinates.h"
#include "map.h"

typedef enum Direction
{
    IDLE, NORTH, SOUTH, EAST, WEST, NORTHEAST, NORTHWEST, SOUTHEAST, SOUTHWEST
};

class Player
{
public:
    //constructor
    Player();

    Player(Coordinates * i_location, Coordinates p_location);

    //destructors
    ~Player();

    //getters
    Coordinates * get_image_location(void);
    Coordinates get_player_location(void);

    //setters
    void set_image_coordinates(Coordinates * newdata);
    void set_player_coordinates(Coordinates newdata);

    //player functions
    bool move(Direction direction, Map &map);

private:
    //holds the player animation locations
    Coordinates image_location[4];
    Coordinates player_location;
    Direction facing;
};




//needed to make a change