#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <tchar.h>
#include <windowsx.h>
#include <ctime>
#include <windowsx.h>
// Библиотека Windows.h содержит определения, макросы и структуры, которые используются при написании приложений под Windows.
#include <Windows.h>

// Прототип оконной процедуры.
LRESULT CALLBACK WindowProcedure(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI _tWinMain(
	HINSTANCE instance, // Дескриптор экземпляра приложения.
	HINSTANCE /*previousInstance*/, // Всегда равен 0 и необходим для совместимости.
	LPTSTR /*commandLine*/, // Параметры командной строки (без имени исполняемого файла).
	INT showCommand // Способ визуализации окна при запуске программы.
	)
{
	// 1. Определение класса окна.

	// Имя класса окна.
	TCHAR className[] = TEXT("KeyBoard");

	WNDCLASSEX windowClass = {};
	windowClass.cbClsExtra = 0; // Используется Windows.
	windowClass.cbSize = sizeof(windowClass); // Размер структуры WNDCLASSEX.
	windowClass.cbWndExtra = 0; // Используется Windows.
	windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)); // Заполнение окна белым цветом.
	windowClass.hCursor = LoadCursor(nullptr, IDC_ARROW); // Загрузка стандартного курсора.
	windowClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION); // Загрузка стандатной иконки.
	windowClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION); // Загрузка стандатной иконки.
	windowClass.hInstance = instance; // Дескриптор данного приложения.
	windowClass.lpfnWndProc = WindowProcedure; // Адрес оконной процедуры.
	windowClass.lpszClassName = className; // Имя класса окна.
	windowClass.lpszMenuName = nullptr; // Приложение не содержит меню.
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS; // CS (Class Style) - стиль класса окна.

	// Стили класса окна:
	// CS_HREDRAW - Перерисовать все окно, если изменен размер по горизонтали.
	// CS_VREDRAW - Перерисовать все окно, если изменен размер по вертикали.

	INT exitCode = 0;

	// 2. Регистрация класса окна.

	if (RegisterClassEx(&windowClass))
	{
		// 3. Создание окна.

		// Создается окно и переменной window присваивается дескриптор окна.
		HWND window = CreateWindowEx(
			0UL, // Расширенный стиль окна.
			className, // Имя класса окна.
			TEXT("Minimal Win32 Application"), // Заголовок окна.
			WS_OVERLAPPEDWINDOW, // Стиль окна.
			CW_USEDEFAULT, // X-координата верхнего левого угла.
			CW_USEDEFAULT, // Y-координата верхнего левого угла.
			CW_USEDEFAULT, // Ширина окна.
			CW_USEDEFAULT, // Высота окна.
			nullptr, // Дескриптор родительского окна.
			nullptr, // Дескриптор меню окна.
			instance, // Дескриптор приложения, создавшего окно.
			nullptr // Указатель на область данных приложения.
			);

		// Стили окна:
		// WS_MINIMIZE - Создает первоначально минимизированное окно.
		// WS_MAXIMIZE - Создает первоначально максимизированное окно.
		// WS_BORDER - Создает окно с тонкой границей.
		// WS_CAPTION - Создает окно, у которого имеется заголовок (уже включает в себя стиль WS_BORDER).
		// WS_SYSMENU - Создает окно, у которого имеется оконное меню в заголовке (используется совместно со стилем WS_CAPTION).
		// WS_MAXIMIZEBOX - Создает окно, у которого имеется кнопка "Развернуть" в заголовке (используется совместно со стилем WS_SYSMENU).
		// WS_MINIMIZEBOX - Создает окно, у которого имеется кнопка "Свернуть" в заголовке (используется совместно со стилем WS_SYSMENU).
		// WS_THICKFRAME - Создает окно, у которого имеется изменяемая граница.
		// WS_OVERLAPPED - Создает перекрывающее окно (у перекрывающего окна имеется граница и заголовок).
		// WS_OVERLAPPEDWINDOW - Создает перекрывающее окно, включает в себя стили WS_OVERLAPPED, WS_CAPTION, WS_SYSMENU, WS_THICKFRAME, WS_MAXIMIZEBOX, WS_MINIMIZEBOX.

		// 4. Отображение окна.

		ShowWindow(window, showCommand);
		UpdateWindow(window); // Перерисовка окна.

		// 5. Запуск цикла обработки сообщений.

		MSG message = {};

		// Получение очередного сообщения из очереди сообщений.
		// Функция GetMessage возвращает значение отличное от ноля до тех пор, пока не получит сообщение WM_QUIT.
		while (GetMessage(&message, nullptr, 0U, 0U))
		{
			// Трансляция сообщения.
			TranslateMessage(&message);

			// Диспетчеризация сообщения.
			DispatchMessage(&message);
		}

		// Присваивание значения, которое было передано в функцию PostQuitMessage.
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
	static int WidthOfOurScreen = GetSystemMetrics(SM_CXSCREEN);//Ширина нашего экрана
	static int HightOfOurScreen = GetSystemMetrics(SM_CYSCREEN); //Высота нашего экрана
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
			// Уничтожение таймера по нажатию клавиши Escape.
			KillTimer(
				window, // Дескриптор окна.
				1U // Идентификатор установленного таймера.
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
	case WM_DESTROY: // Сообщение о завершении программы.
		PostQuitMessage(0); // Отправка сообщения WM_QUIT.
		//SetWindowText(window, L"Hello World");
		break;
	default:
		result = DefWindowProc(window, message, wParam, lParam);
		break;
	}

	return result;
}