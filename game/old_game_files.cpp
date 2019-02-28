#include "FullGame.h"



//controls game flow
void FullGame::play_game_old() {
	bool moved = false;
	int frame = 0;

	/*initialize values (only need window here)

	while (application is running) {
	update the screen
	process events
	check if exited out
	}

	cleanup data	*/

	//generate a map and create a window for display
	Map myMap;
	Player player1;
	create_window();
	create_renderer();

	//test function that proves we are capable of loading .png files
	init_png_loading();

	//render_map()

	//control game flow -- keep playing until exited out
	while (running) {


		//update the screen here******
		render_map(myMap);

		//render_all_and_display(myMap);

		render_player(player1);
		//present_renderer()

		//update screen with rendered image
		SDL_RenderPresent(renderer);

		//SDL_PollEvent takes the most recent event (button press) and stores it to the event variable
		while (SDL_PollEvent(&event) != 0) {

			//process any given event
			OnEvent_old(&event, myMap, player1);

			//if input given for movement, then re-render 
		}

		//update frame, ***if frame gets above 4, then reset it??
		++frame;
		if (frame >= WALKING_ANIMATION_FRAMES) {
			frame = 0;
		}
	}
	close();
}

//generates a map and player renderer and displays to screen
void FullGame::render_all_and_display(Map &myMap, Player &player) {
	//render map
	render_map(myMap);

	//render player
	render_player(player);

	//update screen with rendered image
	SDL_RenderPresent(renderer);
}


//void FullGame::render_player_motion_in_place(int frame, Map &myMap) {
//create destination/source rect objects


//switch statement determines what values to assign to source_rect
//(what frame we are on affects what animation stage to choose)

//make dest_rect based on player location in map object

//update renderer

//destroy any textures/surfaces used in this function
//}


//determines events (such as key presses) and their associated changes (move left etc)
void FullGame::OnEvent_old(SDL_Event* Event, Map &map, Player &player) {

	//allow ourselves to exit the panel by clicking on the exit button in the top corner
	if (Event->type == SDL_QUIT) {
		running = false;
	}
	if (Event->type == SDL_KEYDOWN) //a key has been pressed down
	{
		const Uint8 *state = SDL_GetKeyboardState(NULL); //gets what key has been pressed down
		if (state[SDL_SCANCODE_W])//if the w key was pressed (NORTH)
		{
			player.move(NORTH, map);
		}
		else if (state[SDL_SCANCODE_A])//if the a key was pressed (WEST)
		{
			player.move(WEST, map);
		}
		else if (state[SDL_SCANCODE_S])//if the s key was pressed (SOUTH)
		{
			player.move(SOUTH, map);
		}
		else if (state[SDL_SCANCODE_D])//if the d key was pressed (EAST)
		{
			player.move(EAST, map);
		}
		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_A])//if the d key was pressed (NORTHWEST)
		{
			player.move(NORTHWEST, map);
		}
		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_S])//if the d key was pressed (NORTHSOUTH)
		{
			//if the plpayer press both up and down it should not do anything
		}
		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_D])//if the d key was pressed (NORTHEAST)
		{
			player.move(NORTHEAST, map);
		}
		else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A])//if the d key was pressed (SOUTHWEST)
		{
			player.move(SOUTHWEST, map);
		}
		else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D])//if the d key was pressed (SOUTHEAST)
		{
			player.move(SOUTHEAST, map);
		}
		else if (state[SDL_SCANCODE_D] && state[SDL_SCANCODE_A])//if the d key was pressed (EASTWEST)
		{
			//if the player presses both left and right it should not do anything
		}
		else if (state[SDL_SCANCODE_SPACE])//if the space key was pressed
		{

		}

	}
}