#include "includeHeader.h"
#include "rendering.h"

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance,	HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {


	/*std::thread imguiThread(imguiMain);
	imguiThread.join();*/
	imguiMain();
	return 0;
}
