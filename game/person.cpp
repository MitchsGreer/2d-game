#include "person.h"


    //constructor
    Player::Player()
    {
        Coordinates c;
        for(int i = 0; i < 4; ++i)
        {
            this->image_location[i].operator=(c);
        }
        this->player_location.operator=(c);
    }

    Player::Player(Coordinates * i_location, Coordinates p_location)
    {
         for(int i = 0; i < 4; ++i)
        {
            this->image_location[i].operator=(i_location[i]);
        }
        this->player_location.operator= (p_location);
    }

    //destructors
    Player::~Player()
    {

    }

    //getters
    Coordinates * Player::get_image_location(void)
    {
        return this->image_location;
    }
    Coordinates Player::get_player_location(void)
    {
        return this->player_location;
    }

    //setters
    void Player::set_image_coordinates(Coordinates * newdata)
    {
        for(int i = 0; i < 4; ++i)
        {
        this->image_location[i].operator= (newdata[i]);
        }
    }
    void Player::set_player_coordinates(Coordinates newdata)
    {
        this->player_location.operator= (newdata);
    }

    bool Player::move(Direction direction, Map &map)
    {
        int x, y;
        x = this->player_location.getx();
        y = this->player_location.gety();
        //moving up
        if(direction == NORTH && y > 0 && map.get_passable(x, y - 1))
        {
            this->player_location.sety(y - 1);
            return true;
        }
        //moving down
        else if(direction == SOUTH && y < Map_y_Max - 1  && map.get_passable(x, y + 1))
        {
            this->player_location.sety(y + 1);
            return true;
        }
        //moving right
        else if(direction == EAST && x < Map_x_Max - 1  && map.get_passable(x + 1, y))
        {
            this->player_location.setx(x + 1);
            return true;
        }
        //moving left
        else if(direction == WEST && x > 0  && map.get_passable(x - 1, y))
        {
            this->player_location.setx(x - 1);
            return true;
        }
        //moving up right
        else if(direction == NORTHEAST && y > 0 && x < 9 && map.get_passable(x + 1, y - 1))
        {
            this->player_location.setx(x + 1);
            this->player_location.sety(y - 1);
            return true;
        }
        //moving up left
        else if(direction == NORTHWEST && y > 0 && x > 0 && map.get_passable(x - 1, y - 1))
        {
            this->player_location.setx(x - 1);
            this->player_location.sety(y - 1);
            return true;
        }
        //moving down right
        else if(direction == SOUTHEAST && y < 9 && x < 9 && map.get_passable(x + 1, y + 1))
        {
            this->player_location.setx(x + 1);
            this->player_location.sety(y + 1);
            return true;
        }
        //moving down left
        else if(direction == SOUTHWEST && y < 9 && x > 0 && map.get_passable(x - 1, y + 1))
        {
            this->player_location.setx(x - 1);
            this->player_location.sety(y + 1);
            return true;
        }
        return false;
    }

    //needed to make a change