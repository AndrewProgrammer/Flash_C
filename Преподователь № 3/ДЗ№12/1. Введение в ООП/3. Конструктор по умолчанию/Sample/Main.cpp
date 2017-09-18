#include <conio.h>
#include <iostream>
#include <Windows.h>

#include "Clock.h"

using namespace std;

void InputHours(Clock* const clock)
{
    unsigned int hours = 0U;

    system("cls");

    cout << "Enter hours: ";
    cin >> hours;

    clock->SetHours(hours);
}

void InputMinutes(Clock* const clock)
{
    unsigned int minutes = 0U;

    system("cls");

    cout << "Enter a minutes: ";
    cin >> minutes;

    clock->SetMinutes(minutes);
}

void InputSeconds(Clock* const clock)
{
    unsigned int seconds = 0U;

    system("cls");

    cout << "Enter a seconds: ";
    cin >> seconds;

    clock->SetSeconds(seconds);
}

int main()
{
    Clock clock;

    COORD coord = {};
    HANDLE hHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info = {};

    info.bVisible = false;
    info.dwSize = 10U;

    coord.X = 36;
    coord.Y = 10;

    SetConsoleCursorInfo(hHandle, &info);

    bool exit = false;

    for (;;)
    {
        while (!_kbhit())
        {
            clock.Tick();

            char buffer[100] = {};

            sprintf_s(buffer, "%2.2d:%2.2d:%2.2d", clock.GetHours(), clock.GetMinutes(), clock.GetSeconds());

            SetConsoleCursorPosition(hHandle, coord);

            system("cls");
            printf(buffer);

            Sleep(1000U);
        }

        switch (_getch())
        {
            case 'h':
                InputHours(&clock);
                break;
            case 'm':
                InputMinutes(&clock);
                break;
            case 's':
                InputSeconds(&clock);
                break;
            case 27:
                exit = true;
                break;
        }

        if (exit)
        {
            break;
        }
    }

    return 0;
}