#include "gui.h"
#include "recoil.cpp"
#include <Windows.h>
#include <thread>

int __stdcall wWinMain(
	HINSTANCE instance,
	HINSTANCE previousInstance,
	PWSTR arguments,
	int commandShow)
{
	gui::CreateHWindow("Slinky");
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::isRunning)
	{	
		gui::BeginRender();
		gui::Render();
		gui::EndRender();

		while (true) {
			if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
				dragMouseDown(1);
				dragMouseLeft(1);
			}
			else {
				break;
			}
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}