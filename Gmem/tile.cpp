    #include "tile.h"

    //constructors
    //default
    Tile::Tile()
    {
        Coordinates c;
        this->image_location = c;
        this->passable = true;
        this->identity = NONE;
    }
    //nondefault
    Tile::Tile(bool passing, Coordinates location, Identifier newdata)
    {
        this->image_location = location;
        this->passable = passing;
        this->identity = newdata;
    }

    //destructor
    Tile::~Tile()
    {
        //does not do much
    }

    //getters
    Identifier Tile::get_identity()
    {
        return this->identity;
    }
    bool Tile::get_passable(void)
    {
        return this->passable;
    }
    Coordinates Tile::get_coordinates(void)
    {
        return this->image_location;
    }

    //settrs
    void Tile::set_identity(Identifier newdata)
    {
        this->identity = newdata;
    }
    void Tile::set_passable(bool newdata)
    {
        this->passable = newdata;
    }
    void Tile::set_coordinates(Coordinates newdata)
    {
        this->image_location = newdata;
    }

    //needed to make a change