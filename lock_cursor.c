#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	short caps;
	POINT cursor;
	HMONITOR monitor;
	RECT screenRect;
	MONITORINFO mi;
	mi.cbSize = sizeof(MONITORINFO);

	while(1)
	{
		caps = GetKeyState(VK_SCROLL);
		if (caps)
		{
			GetCursorPos(&cursor);
			
			monitor = MonitorFromPoint(cursor, MONITOR_DEFAULTTONEAREST);
			GetMonitorInfo(monitor, &mi);

			ClipCursor(&mi.rcMonitor);
		}
		else
		{
			ClipCursor(NULL);
		}
		Sleep(100);
	}

	return 0;
}
