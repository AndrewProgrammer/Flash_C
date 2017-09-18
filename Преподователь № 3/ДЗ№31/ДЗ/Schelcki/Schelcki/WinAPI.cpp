#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#include <tchar.h>
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
	TCHAR className[] = TEXT("MinimalWin32Application");

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
		UpdateWindow(window);//Нужно нам для того чтобы обновить наше окно
		break;
		// Сообщение о нажатии левой кнопки мыши.
	case WM_LBUTTONDOWN:
		COUNTLBUTTON++;
		MessageBox(0, TEXT("LButtonMousePress"), TEXT("WM_LBUTTONDOWN"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//Нужно нам для того чтобы обновить наше окно
		break;
		//Сообщение о двойном щелчке средней кнопки мыши.
	case WM_MBUTTONDBLCLK:
		COUNTMDBCLICK+= 2;
		MessageBox(0, TEXT("DoubleClikMMouse"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//Нужно нам для того чтобы обновить наше окно
		break;
		// Сообщение о нажатии средней кнопки мыши.
	case WM_MBUTTONDOWN:
		COUNTMBUTTON ++;
		MessageBox(0, TEXT("MButtonMousePress"), TEXT("WM_MBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//Нужно нам для того чтобы обновить наше окно
		break;
		// Сообщение о двойном щелчке правой кнопки мыши.
	case WM_RBUTTONDBLCLK:
		COUNTRDBCLICK += 2;
		MessageBox(0, TEXT("DoubleClikRMouse"), TEXT("WM_RBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//Нужно нам для того чтобы обновить наше окно
		break;
		// Сообщение о нажатии правой кнопки мыши.
	case WM_RBUTTONDOWN:
		COUNTRBUTTON++;
		MessageBox(0, TEXT("RButtonMousePress"), TEXT("WM_RBUTTONDBLCLK"), MB_OK | MB_ICONINFORMATION);
		_stprintf_s(INFOPANEL, TEXT("DMbutton % d DRButton % d DLButton: % d LButton: %d RButton : %d MButton : %d"), COUNTMDBCLICK, COUNTRDBCLICK, COUNTLDBCLICK, COUNTLBUTTON, COUNTRBUTTON, COUNTMBUTTON);
		SetWindowText(window, INFOPANEL);
		UpdateWindow(window);//Нужно нам для того чтобы обновить наше окно
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