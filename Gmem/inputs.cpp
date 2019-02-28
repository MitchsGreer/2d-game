#include "FullGame.h"

//determines events (such as key presses) and their associated changes (move left etc)
void GameApp::OnEvent(SDL_Event* Event, Map * map, Player player) {

	//allow ourselves to exit the panel by clicking on the exit button in the top corner
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
	if(Event->type == SDL_KEYDOWN) //a key has been pressed down
	{
		const Uint8 *state = SDL_GetKeyboardState(NULL); //gets what key has been pressed down
		if(state[SDL_SCANCODE_W])//if the w key was pressed (NORTH)
		{
            	player->move(NORTH, map);
		}
		else if(state[SDL_SCANCODE_A])//if the a key was pressed (WEST)
		{
            	player->move(WEST, map);
		}
		else if(state[SDL_SCANCODE_S])//if the s key was pressed (SOUTH)
		{
            	player->move(SOUTH, map);
		}
		else if(state[SDL_SCANCODE_D])//if the d key was pressed (EAST)
		{
            	player->move(EAST, map);
		}
		else if(state[SDL_SCANCODE_W] && state[SDL_SCANCODE_A])//if the d key was pressed (NORTHWEST)
		{
            	player->move(NORTHWEST, map);
		}
		else if(state[SDL_SCANCODE_W] && state[SDL_SCANCODE_S])//if the d key was pressed (NORTHSOUTH)
		{
			//if the plpayer press both up and down it should not do anything
		}
		else if(state[SDL_SCANCODE_W] && state[SDL_SCANCODE_D])//if the d key was pressed (NORTHEAST)
		{
            	player->move(NORTHEAST, map);
		}
		else if(state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A])//if the d key was pressed (SOUTHWEST)
		{
            	player->move(SOUTHWEST, map);
		}
		else if(state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D])//if the d key was pressed (SOUTHEAST)
		{
            	player->move(SOUTHEAST, map);
		}
		else if(state[SDL_SCANCODE_D] && state[SDL_SCANCODE_A])//if the d key was pressed (EASTWEST)
		{
            	//if the player presses both left and right it should not do anything
		}
		else if(state[SDL_SCANCODE_SPACE])//if the space key was pressed
		{
            
		}

	}
}

//needed to make a change