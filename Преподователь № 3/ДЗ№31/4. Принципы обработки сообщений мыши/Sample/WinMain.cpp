#include <cstdio>
#include <tchar.h>
#include <Windows.h>
#include <WindowsX.h>

VOID AddMouseMessageInfo(LPCTSTR message, WORD x, WORD y);
VOID AddMouseWheelMessageInfo(WORD keys, SHORT delta, WORD x, WORD y);
LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(HINSTANCE instance, HINSTANCE /*previousInstance*/, LPTSTR /*commandLine*/, INT showCommand)
{
    TCHAR className[] = TEXT("Win32Application");

    WNDCLASSEX windowClass = {};
    windowClass.cbClsExtra = 0;
    windowClass.cbSize = sizeof(windowClass);
    windowClass.cbWndExtra = 0;
    windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
    windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    windowClass.hInstance = instance;
    windowClass.lpfnWndProc = WindowProcedure;
    windowClass.lpszClassName = className;
    windowClass.lpszMenuName = nullptr;
    windowClass.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;

    // Стили класса окна:
    // CS_DBLCLKS - Окно будет получать сообщения о двойном щелчке кнопки мыши.
    // Если этот стиль не будет включен, то при двойном щелчке левой кнопкой мыши будут приходить следующие сообщения: WM_LBUTTONDOWN, WM_LBUTTONUP, WM_LBUTTONDOWN, WM_LBUTTONUP.
    // Если этот стиль будет включен, то при двойном щелчке левой кнопкой мыши будут приходить следующие сообщения: WM_LBUTTONDOWN, WM_LBUTTONUP, WM_LBUTTONDBLCLK, WM_LBUTTONUP.

    INT exitCode = 0;

    if (RegisterClassEx(&windowClass))
    {
        HWND window = CreateWindowEx(0UL, className, TEXT("Mouse Messages"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr, instance, nullptr);

        ShowWindow(window, showCommand);
        UpdateWindow(window);

        MSG message = {};

        while (GetMessage(&message, nullptr, 0U, 0U))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        exitCode = message.wParam;
    }

    return exitCode;
}

VOID AddMouseMessageInfo(LPCTSTR message, WORD x, WORD y)
{
    FILE* file = nullptr;

    if (_tfopen_s(&file, TEXT("Messages.txt"), TEXT("a")) == 0)
    {
        TCHAR line[100] = {};

        _stprintf_s(line, TEXT("Message: %s, X: %d, Y: %d\r\n"), message, x, y);
        _fputts(line, file);

        fclose(file);
    }
}

VOID AddMouseWheelMessageInfo(WORD keys, SHORT delta, WORD x, WORD y)
{
    FILE* file = nullptr;

    if (_tfopen_s(&file, TEXT("Messages.txt"), TEXT("a")) == 0)
    {
        TCHAR line[100] = {};

        _stprintf_s(line, TEXT("Message: WM_MOUSEWHEEL, X: %d, Y: %d, Delta: %d"), x, y, delta);

        // Если нажата клавиша CTRL.
        if ((keys & MK_CONTROL) != 0U)
        {
            _tcscat_s(line, TEXT(", Ctrl"));
        }
        // Если нажата клавиша SHIFT.
        if ((keys & MK_SHIFT) != 0U)
        {
            _tcscat_s(line, TEXT(", Shift"));
        }
        // Если нажата левая кнопка мыши.
        if ((keys & MK_LBUTTON) != 0U)
        {
            _tcscat_s(line, TEXT(", Left mouse button"));
        }
        // Если нажата средняя кнопка мыши.
        if ((keys & MK_MBUTTON) != 0U)
        {
            _tcscat_s(line, TEXT(", Middle mouse button"));
        }
        // Если нажата правая кнопка мыши.
        if ((keys & MK_RBUTTON) != 0U)
        {
            _tcscat_s(line, TEXT(", Right mouse button"));
        }
        // Если нажата первая дополнительная кнопка кнопка мыши.
        if ((keys & MK_XBUTTON1) != 0U)
        {
            _tcscat_s(line, TEXT(", First X mouse button"));
        }
        // Если нажата вторая дополнительная кнопка кнопка мыши.
        if ((keys & MK_XBUTTON2) != 0U)
        {
            _tcscat_s(line, TEXT(", Second X mouse button"));
        }

        _tcscat_s(line, TEXT("\r\n"));
        _fputts(line, file);

        fclose(file);
    }
}

LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    LRESULT result = 0;

    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            // Сообщение о двойном щелчке левой кнопки мыши.
        case WM_LBUTTONDBLCLK:
            AddMouseMessageInfo(TEXT("WM_LBUTTONDBLCLK"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение о нажатии левой кнопки мыши.
        case WM_LBUTTONDOWN:
            AddMouseMessageInfo(TEXT("WM_LBUTTONDOWN"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение об отпускании левой кнопки мыши.
        case WM_LBUTTONUP:
            AddMouseMessageInfo(TEXT("WM_LBUTTONUP"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение о двойном щелчке средней кнопки мыши.
        case WM_MBUTTONDBLCLK:
            AddMouseMessageInfo(TEXT("WM_MBUTTONDBLCLK"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение о нажатии средней кнопки мыши.
        case WM_MBUTTONDOWN:
            AddMouseMessageInfo(TEXT("WM_MBUTTONDOWN"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение об отпускании средней кнопки мыши.
        case WM_MBUTTONUP:
            AddMouseMessageInfo(TEXT("WM_MBUTTONUP"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение о перемещении курсора мыши над клиентской областью окна.
        case WM_MOUSEMOVE:
            AddMouseMessageInfo(TEXT("WM_MOUSEMOVE"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение о прокрутке колесика мыши.
        case WM_MOUSEWHEEL:
            AddMouseWheelMessageInfo(GET_KEYSTATE_WPARAM(wParam), GET_WHEEL_DELTA_WPARAM(wParam), GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            break;
            // Сообщение о двойном щелчке правой кнопки мыши.
        case WM_RBUTTONDBLCLK:
            AddMouseMessageInfo(TEXT("WM_RBUTTONDBLCLK"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение о нажатии правой кнопки мыши.
        case WM_RBUTTONDOWN:
            AddMouseMessageInfo(TEXT("WM_RBUTTONDOWN"), LOWORD(lParam), HIWORD(lParam));
            break;
            // Сообщение об отпускании правой кнопки мыши.
        case WM_RBUTTONUP:
            AddMouseMessageInfo(TEXT("WM_RBUTTONUP"), LOWORD(lParam), HIWORD(lParam));
            break;
        default:
            result = DefWindowProc(window, message, wParam, lParam);
            break;
    }

    return result;
}