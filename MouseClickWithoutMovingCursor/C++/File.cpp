#include <Windows.h>

int main() {
	POINT screenPoint;

	screenPoint.x = 1870;
	screenPoint.y = 25;

	HWND handlePtr = WindowFromPoint(screenPoint);

	if(handlePtr) {
		int lParam = MAKELPARAM(screenPoint.x, screenPoint.y);

		PostMessage(handlePtr, WM_LBUTTONDOWN, 0, lParam);
		PostMessage(handlePtr, WM_LBUTTONUP, 0, lParam);
	}

	system("PAUSE");
}
