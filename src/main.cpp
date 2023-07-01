#include <iostream>
#include "Game.h"
#include "Constants.h"

int main(int argv, char** args){
	Game *game = new Game();
	game->Initialize(WINDOW_WIDTH,WINDOW_HEIGTH);

	while (game->IsRunning()){
		game->ProcessInput();
		game->Update();
		game->Render();
	}

	game->Destroy();

	return 0;
}