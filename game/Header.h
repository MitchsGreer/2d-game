#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include "map.h"
#include "person.h"



#define SOURCE_TILE_SIZE 16
#define DISPLAY_TILE_SIZE 50

//speed of player = number of pixels moved every frame, (tiles/sec = speed * framerate / display_tile_size)
#define PLAYER_SPEED 0.1
#define WALKING_ANIMATION_FRAMES 1

#define WWIDTH 500
#define WHEIGHT 500

//if ((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
//	return false;
//}




//Things that can change
// - we dont need to display the player over the surface, this may be leading to some issues when the player moves back, 
//   it seems it will replace tiles with the default, in this case puddles. we can slove this by having a bool in the mapelement
//   that describes whether the player is on it or not, if it is, load the player
// - need to look through move, as it wot break the tiles even if you have all of the tools
// -  



//for mk
/*
code Header.h
code main.cpp
code map.cpp
code map.h
*/