
#pragma once
#include "Header.h"
#include "map.h"
#include"person.h"
#include "FullGame.h"

int main(int argc, char * argv[]) {

	srand(time(0));

	FullGame game_app;
	game_app.play_game();



	return 0;
}

//needed to make a change
