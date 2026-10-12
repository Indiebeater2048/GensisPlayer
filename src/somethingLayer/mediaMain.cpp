#include <raylib.h>
#include "mediaMain.h"

bool initGame() {

	return true;
}

bool updateGame() {
	DrawText("goals, ReadDisplaySongText, DisplayCurrentMedia, ManageMedia", 350, 225, 100, { 200, 255, 255, 100 });
	float deltaTime = GetFrameTime();
	if (deltaTime > 1.f / 5) { deltaTime = 1.f / 5; }

	return true;
}

bool closeGame() {

	return false;
}
