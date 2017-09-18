#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int row = 4, cols = 4;

void PrintField(COORD pos);
void SetCursor(COORD pos);
void InitArray(int field[row][cols]);
void PrintArray(COORD pos, int field[row][cols]);
void Navigation(COORD pos, int field[row][cols]);
