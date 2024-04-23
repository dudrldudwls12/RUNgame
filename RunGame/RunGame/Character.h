#pragma once
#include <windows.h>

typedef struct Character
{
    int x, y;
    const char* shape;
}Character;

void GotoXY(int x, int y)
{
    COORD position = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);