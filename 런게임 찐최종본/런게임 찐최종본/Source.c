#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define ITEM_BOTTOM_Y 5
#define ITEM_BOTTOM_X 45

void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("Dinosaurs Run");
}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		char key = _getch();

	}
	return 0;
}

void DrawGameStart()
{
	system("cls");
	int x = 16;
	int y = 13;
	printf("===========================");
	GoToXY(x, y, +1);
	printf("===========================");
	GoToXY(x, y, +2);
	printf("======���⸻ ������ضٴ� ����=======");
	GoToXY(x, y, +3);
	printf("===========================");
	GoToXY(x, y, +4);
	printf("===========================");
	GoToXY(x, y, +5);
	printf("Z : ����Ű");
	GoToXY(x, y, +7);
	printf("���� ��� 5��");
	GoToXY(x, y, +8);
	printf("������ �΋H���� ����� ���� --.");
	GoToXY(x, y, +9);
	printf("����� ������ ����� �þ ++.");
	GoToXY(x, y, +11);
	printf("���ӽ��� �Ϸ��� �ƹ�Ű�� �����ÿ�.");
	printf("\n\n\n\n\n\n\n\n");
	getch();
}

int main()
{
	
	return;
}