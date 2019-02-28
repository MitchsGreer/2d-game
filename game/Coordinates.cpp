#include "Coordinates.h"


//constructor
Coordinates::Coordinates()
{
    this->x = 0;
    this->y = 0;
}
Coordinates::Coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

//destructor
Coordinates::~Coordinates()
{
    //does not do anything
}

//getters
int Coordinates::getx(void)
{
    return this->x;
}
int Coordinates::gety(void)
{
    return this->y;
}

//setters
void Coordinates::setx(int newdata)
{
    this->x = newdata;
}
void Coordinates::sety(int newdata)
{
    this->y = newdata;
}

void Coordinates::operator=(Coordinates newdata)
{
    this->x = newdata.getx();
    this->y = newdata.gety();
}

//needed to make a change