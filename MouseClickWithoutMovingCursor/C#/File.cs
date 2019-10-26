public enum WMessages : int {
	WM_LBUTTONDOWN = 0x201,
	WM_LBUTTONUP = 0x202,
	WM_LBUTTONDBLCLK = 0x203,
	WM_RBUTTONDOWN = 0x204,
	WM_RBUTTONUP = 0x205,
	WM_RBUTTONDBLCLK = 0x206
};

[DllImport("user32.dll")]
static extern IntPtr WindowFromPoint(int xPoint, int yPoint);

[DllImport("user32.dll", SetLastError = true)]
static extern bool PostMessage(IntPtr hWnd, uint Msg, int wParam, int lParam);

private int MAKELPARAM(Point screenPoint) {
	return ((screenPoint.Y << 16) | (screenPoint.X & 0xFFFF));
}

private void ClickOnScreen(int xPosition, int yPosition) {
	Point screenPoint = new Point(xPosition, yPosition);
	IntPtr handlePtr = WindowFromPoint(screenPoint.X, screenPoint.Y);

	if(handlePtr != null) {
		int lParam = MAKELPARAM(screenPoint);

		PostMessage(handlePtr, (uint)WMessages.WM_LBUTTONDOWN, 0, lParam);
		PostMessage(handlePtr, (uint)WMessages.WM_LBUTTONUP, 0, lParam);
	}
}
