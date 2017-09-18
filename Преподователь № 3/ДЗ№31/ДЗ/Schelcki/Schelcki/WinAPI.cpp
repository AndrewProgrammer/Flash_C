#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <tchar.h>
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
	TCHAR className[] = TEXT("MinimalWin32Application");

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
	static int COUNTLDBCLICK = 0;
	static int COUNTLBUTTON = 0;
	static int COUNTRBUTTON = 0;
	static int COUNTMBUTTON = 0;
	static int COUNTRDBCLICK = 0;
	static int COUNTMDBCLICK = 0;
	const int SIZEFORINFOPANEL = 65546;
	static wchar_t INFOPANEL[SIZEFORINFOPANEL] = {};
	switch (message)
	{
	case WM_LBUTTONDBLCLK:
		COUNTLDBCLICK+= 2;
		MessageBox(0, TEXT("DoubleClikLMouse"), TEXT("WM_LBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL,TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"),COUNTMDBCLICK,COUNTRDBCLICK,COUNTLDBCLICK, COUNTLBUTTON,COUNTRBUTTON,COUNTMBUTTON);
		SetWindowText(window,INFOPANEL);
		UpdateWindow(window);//����� ��� ��� ���� ����� �������� ���� ����
		break;
		// ��������� � ������� ����� ������ ����.
	case WM_LBUTTONDOWN:
		COUNTLBUTTON++;
		MessageBox(0, TEXT("LButtonMousePress"), TEXT("WM_LBUTTONDOWN"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//����� ��� ��� ���� ����� �������� ���� ����
		break;
		//��������� � ������� ������ ������� ������ ����.
	case WM_MBUTTONDBLCLK:
		COUNTMDBCLICK+= 2;
		MessageBox(0, TEXT("DoubleClikMMouse"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//����� ��� ��� ���� ����� �������� ���� ����
		break;
		// ��������� � ������� ������� ������ ����.
	case WM_MBUTTONDOWN:
		COUNTMBUTTON ++;
		MessageBox(0, TEXT("MButtonMousePress"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//����� ��� ��� ���� ����� �������� ���� ����
		break;
		// ��������� � ������� ������ ������ ������ ����.
	case WM_RBUTTONDBLCLK:
		COUNTRDBCLICK += 2;
		MessageBox(0, TEXT("DoubleClikRMouse"), TEXT("WM_RBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//����� ��� ��� ���� ����� �������� ���� ����
		break;
		// ��������� � ������� ������ ������ ����.
	case WM_RBUTTONDOWN:
		COUNTRBUTTON++;
		MessageBox(0, TEXT("RButtonMousePress"), TEXT("WM_RBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//����� ��� ��� ���� ����� �������� ���� ����
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