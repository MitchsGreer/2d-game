#pragma once
#include "Header.h"
#include "map.h"
#include <SDL.h>
#include <vector>

class FullGame {
public:
	//class constructor
	FullGame();

	//destructor -- cleaup images etc
	~FullGame();

	//controls game flow
	void play_game_old();

	void play_game();

	void refresh_screen(Map &myMap, Player &player1);

	void FullGame::event_handler(SDL_Event* Event, Map &map, Player &player, int time_1);

	//loads and retrns a given surface using the given relative path to the bmp
	//postcondition: surface returned must be deallocated by program that calls it!
	//string is const to allow passing string literals
	SDL_Surface * load_surface(const std::string path);

	//generates a window object for display, returns success bool
	bool create_window();

	//generate a renderer object for the window, returns success bool
	bool create_renderer();

	//creates a texture from a provided surface + applies that texture to the renderer, frees up the surface/texture
	void apply_texture_to_renderer(SDL_Rect &dest_rect, SDL_Rect &source_rect, const std::string path);

	//allows us to generate a map and player initial starting point
	void render_all_and_display(Map &myMap, Player &player);

	//void render_player_motion_in_place(int frame, Map &myMap);

	//renders the player's screen facing default sprite at the player's current location
	void render_player(Player &player);

	//takes the renderer, applies it to the screen (this function updates screen with image generated from map parameter)
	void render_map(Map &myMap);

	//determine which texture to apply via switch statement and adjust source_rect accordingly
	void determine_source_tile(int x, int y, Map &map, SDL_Rect &source_rect);

	//initializes PNG loading -- allows us to use more than just .bmp images
	void init_png_loading();

	//processes any given event
	//void process_event(SDL_Event* Event, Map * map, Player * player);

	void OnEvent_old(SDL_Event* Event, Map &map, Player &player);

	//controls cleanup of all code (values etc)
	void close();

private:
	//control game state
	bool running;

	//handles error output
	std::ofstream error_log;

	//Event handler
	SDL_Event event;

	//window object ptr
	SDL_Window * window_display;

	//renderer object ptr
	SDL_Renderer * renderer;

	//texture object ptr
	SDL_Texture * temp_texture;

	//surfaces for textures (master_surface most useful for blitting)
	SDL_Surface * temp_surface;
	SDL_Surface * master_surface;
};
