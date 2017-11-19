#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include "GAMESTATE/Game.h"
#include "GAMESTATE/GameStateStart.h"
#include "GAMESTATE/GameStatePlay.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(31232);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, 5, 5, 800, 720, TRUE);

	Game game;
	game.pushState(new GameStatePlay(&game));
	game.gameLoop();
	_CrtDumpMemoryLeaks();
	return 0;
}