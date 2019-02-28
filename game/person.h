#pragma once
#include "Header.h"
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

	int get_x_pixel();
	int get_y_pixel();

	void set_x_pixel(int x);
	void set_y_pixel(int y);

    //player functions
    bool move(Direction direction, Map &map);

	//overloaded pixel_movement function
	bool move(Direction direction, Map &map, int pixel_change);


private:
    //holds the player animation locations
    Coordinates image_location[4];
    Coordinates player_location;
    Direction facing;

	int x_pixel;
	int y_pixel;
};




//needed to make a change