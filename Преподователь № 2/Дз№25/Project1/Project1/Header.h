#pragma once 

#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int row = 10, cols = 15;
const int size = 10;

void InitializeArray(int ar[], int size);
void InitializeArray(int ar[row][cols]);
void PrintArray(int ar[], int size);
void PrintArray(int ar[row][cols]);

void PrintField(COORD pos);
void GamePrc(COORD pos);

void Insert();
void Computer();




