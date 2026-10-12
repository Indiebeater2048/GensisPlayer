#include <iostream>
#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include <mediaMain.h>

int main() {

#if PRODUCTION_BUILD == 1
	SetTraceLogLevel(LOG_NONE); // RAYLIB LOG OUTPUT
#endif

	//raylibconfig
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(2000, 1000, "First window");
	SetExitKey(KEY_ESCAPE); // EXIT KEY
	SetTargetFPS(100);

	rlImGuiSetup(true);

	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	if (!initGame()) {
		return 0;
	}

	//WINDOW
	while (!WindowShouldClose())
	{

#pragma region imgui
		BeginDrawing();
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
		ClearBackground(BLACK);
#pragma endregion


		if (!updateGame()) {
			CloseWindow();
		}

		rlImGuiEnd();

		EndDrawing();
	}

	CloseWindow();

	closeGame();

#pragma region imgui
	rlImGuiShutdown();
#pragma endregion

	return 0;
}