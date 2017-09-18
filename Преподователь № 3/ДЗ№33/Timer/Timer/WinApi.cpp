#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <tchar.h>
#include <windowsx.h>
#include <ctime>
#include <windowsx.h>
// ���������� Windows.h �������� �����������, ������� � ���������, ������� ������������ ��� ��������� ���������� ��� Windows.
#include <Windows.h>

// �������� ������� ���������.
LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(
	HINSTANCE instance, // ���������� ���������� ����������.
	HINSTANCE /*previousInstance*/, // ������ ����� 0 � ��������� ��� �������������.
	LPTSTR /*commandLine*/, // ��������� ��������� ������ (��� ����� ������������ �����).
	INT showCommand // ������ ������������ ���� ��� ������� ���������.
	)
{
	// 1. ����������� ������ ����.

	// ��� ������ ����.
	TCHAR className[] = TEXT("KeyBoard");

	WNDCLASSEX windowClass = {};
	windowClass.cbClsExtra = 0; // ������������ Windows.
	windowClass.cbSize = sizeof(windowClass); // ������ ��������� WNDCLASSEX.
	windowClass.cbWndExtra = 0; // ������������ Windows.
	windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // ���������� ���� ����� ������.
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW); // �������� ������������ �������.
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION); // �������� ���������� ������.
	windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION); // �������� ���������� ������.
	windowClass.hInstance = instance; // ���������� ������� ����������.
	windowClass.lpfnWndProc = WindowProcedure; // ����� ������� ���������.
	windowClass.lpszClassName = className; // ��� ������ ����.
	windowClass.lpszMenuName = nullptr; // ���������� �� �������� ����.
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; // CS (Class Style) - ����� ������ ����.

	// ����� ������ ����:
	// CS_HREDRAW - ������������ ��� ����, ���� ������� ������ �� �����������.
	// CS_VREDRAW - ������������ ��� ����, ���� ������� ������ �� ���������.

	INT exitCode = 0;

	// 2. ����������� ������ ����.

	if (RegisterClassEx(&windowClass))
	{
		// 3. �������� ����.

		// ��������� ���� � ���������� window ������������� ���������� ����.
		HWND window = CreateWindowEx(
			0UL, // ����������� ����� ����.
			className, // ��� ������ ����.
			TEXT("Minimal Win32 Application"), // ��������� ����.
			WS_OVERLAPPEDWINDOW, // ����� ����.
			CW_USEDEFAULT, // X-���������� �������� ������ ����.
			CW_USEDEFAULT, // Y-���������� �������� ������ ����.
			CW_USEDEFAULT, // ������ ����.
			CW_USEDEFAULT, // ������ ����.
			nullptr, // ���������� ������������� ����.
			nullptr, // ���������� ���� ����.
			instance, // ���������� ����������, ���������� ����.
			nullptr // ��������� �� ������� ������ ����������.
			);

		// ����� ����:
		// WS_MINIMIZE - ������� ������������� ���������������� ����.
		// WS_MAXIMIZE - ������� ������������� ����������������� ����.
		// WS_BORDER - ������� ���� � ������ ��������.
		// WS_CAPTION - ������� ����, � �������� ������� ��������� (��� �������� � ���� ����� WS_BORDER).
		// WS_SYSMENU - ������� ����, � �������� ������� ������� ���� � ��������� (������������ ��������� �� ������ WS_CAPTION).
		// WS_MAXIMIZEBOX - ������� ����, � �������� ������� ������ "����������" � ��������� (������������ ��������� �� ������ WS_SYSMENU).
		// WS_MINIMIZEBOX - ������� ����, � �������� ������� ������ "��������" � ��������� (������������ ��������� �� ������ WS_SYSMENU).
		// WS_THICKFRAME - ������� ����, � �������� ������� ���������� �������.
		// WS_OVERLAPPED - ������� ������������� ���� (� �������������� ���� ������� ������� � ���������).
		// WS_OVERLAPPEDWINDOW - ������� ������������� ����, �������� � ���� ����� WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MAXIMIZEBOX, WS_MINIMIZEBOX.

		// 4. ����������� ����.

		ShowWindow(window, showCommand);
		UpdateWindow(window); // ����������� ����.

		// 5. ������ ����� ��������� ���������.

		MSG message = {};

		// ��������� ���������� ��������� �� ������� ���������.
		// ������� GetMessage ���������� �������� �������� �� ���� �� ��� ���, ���� �� ������� ��������� WM_QUIT.
		while (GetMessage(&message, nullptr, 0U, 0U))
		{
			// ���������� ���������.
			TranslateMessage(&message);

			// ��������������� ���������.
			DispatchMessage(&message);
		}

		// ������������ ��������, ������� ���� �������� � ������� PostQuitMessage.
		exitCode = message.wParam;
	}

	return exitCode;
}
LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	RECT r;
	const int SizeOfWindow = 300;
	static int x, y;
	static int WidthOfOurScreen = GetSystemMetrics(SM_CXSCREEN);//������ ������ ������
	static int HightOfOurScreen = GetSystemMetrics(SM_CYSCREEN); //������ ������ ������
	static int xPos = (int)LOWORD(lParam);
	static int yPos = (int)HIWORD(lParam);
	switch (message)
	{
	case WM_TIMER:
	{
		GetWindowRect(window,&r);
		if (r.right < WidthOfOurScreen && r.top == 0)
		{
			x += 10;
		}
		if (r.right >= WidthOfOurScreen && r.top <= HightOfOurScreen)
		{
			y += 10;
		}
		if (r.left != 0 && r.bottom >= HightOfOurScreen)
		{
			x -= 10;
		}
		if (r.top <= HightOfOurScreen - SizeOfWindow && r.left == 0 )
		{
			y -= 10;
		}
		MoveWindow(window,x,y,SizeOfWindow,SizeOfWindow,true);
		UpdateWindow(window);
	}
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			// ����������� ������� �� ������� ������� Escape.
			KillTimer(
				window, // ���������� ����.
				1U // ������������� �������������� �������.
				);
		}
		if (wParam == VK_RETURN)
		{
			GetWindowRect(window, &r);
			MoveWindow(window, 0, 0, SizeOfWindow, SizeOfWindow, true);
			UpdateWindow(window);
			SetTimer(window, 1U, 10U, nullptr);
		}
		if (wParam == VK_UP)
		{
			GetWindowRect(window, &r);
			x = r.left;
			y = r.top;
			if (y >= 0)
			{
				--y;
			}
			MoveWindow(window, x, y, SizeOfWindow, SizeOfWindow, true);
			UpdateWindow(window);
		}
		if (wParam == VK_LEFT)
		{
			GetWindowRect(window, &r);
			x = r.left;
			y = r.top;
			if (x >= 0)
			{
				x--;
			}
			MoveWindow(window, x, y, SizeOfWindow, SizeOfWindow, true);
			UpdateWindow(window);
		}
		if (wParam == VK_DOWN)
		{
			GetWindowRect(window, &r);
			x = r.left;
			y = r.top;
			if (r.bottom <= HightOfOurScreen)
				++y;
			MoveWindow(window, x, y, SizeOfWindow, SizeOfWindow, true);
			UpdateWindow(window);
		}
		if (wParam == VK_RIGHT)
		{
			GetWindowRect(window, &r);
			x = r.left;
			y = r.top;
			if (r.right <= WidthOfOurScreen)
			{
				++x;
			}
			MoveWindow(window, x, y, SizeOfWindow, SizeOfWindow, true);
			UpdateWindow(window);
		}
		break;
		case WM_MOVE:
			GetWindowRect(window, &r);
			if (r.left <= 0)
			{
				x = 0;
				y = r.top;
				MoveWindow(window, x, y, r.right - r.left, r.bottom - r.top, true);
			}
			if (r.top <= 0)
			{
				x = r.left;
				y = 0;
				MoveWindow(window, x, y, r.right - r.left, r.bottom - r.top, true);
			}
			if (r.right >= WidthOfOurScreen)
			{
				x = WidthOfOurScreen - (r.right - r.left);
				y = r.top;
				MoveWindow(window, x, y, r.right - r.left, r.bottom - r.top, true);
			}
			if (r.bottom >= HightOfOurScreen)
			{
				x = r.left;
				y = HightOfOurScreen - (r.bottom - r.top);
				MoveWindow(window, x, y, r.right - r.left, r.bottom - r.top, true);
			}
			break;
	case WM_DESTROY: // ��������� � ���������� ���������.
		PostQuitMessage(0); // �������� ��������� WM_QUIT.
		//SetWindowText(window, L"Hello World");
		break;
	default:
		result = DefWindowProc(window, message, wParam, lParam);
		break;
	}

	return result;
}