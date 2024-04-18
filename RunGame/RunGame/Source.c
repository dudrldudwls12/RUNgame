#include <stdio.h>
#include <Windows.h>
#include <conio.h>

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
		return _getch();
	}
	return 0;
}

void DrawGameStart()
{
	system("cls");
	int x = 16;
	int y = 13;
	GoToXY(x, y);
	printf("===========================");
	GoToXY(x, y, + 1);
	printf("===========================");
	GoToXY(x, y, + 2);
	printf("======���⸻ �پ�� �������=======");
	GoToXY(x, y, + 3);
	printf("===========================");
	GoToXY(x, y, + 4);
	printf("===========================");
	GoToXY(x, y, + 5);
	printf("Z : ����Ű");
	GoToXY(x, y, + 7);
	printf("���� ��� 5��");
	GoToXY(x, y, + 8);
	printf("������ �΋H���� ����� ���� --.");
	GoToXY(x, y, + 9);
	printf("����� ������ ����� �þ ++.");
	GoToXY(x, y, + 11);
	printf("���ӽ��� �Ϸ��� �ƹ�Ű�� �����ÿ�.");
	printf("\n\n\n\n\n\n\n\n");
	getch();
}

void DrawDino(int dinoY)
{
	GotoXY(0, dinoY);
	static bool legFlag = true;
	printf("         $$     \n");
	printf("        $$$     \n");
	printf("        $$$     \n");
	printf("        $$$$$   \n");
	printf("       $$$ $$$  \n");
	printf("       $$$$$$   \n");
	printf("      $$$$$     \n");
	printf(" $$  $$$$$$$$$$$\n");
	printf(" $$$$$$$$$$$    \n");
	printf("  $$$$$$$$$$    \n");
	printf("    $$$$$$$$    \n");
	if (legFlag)
	{
		printf("     $    $$$    \n");
		printf("     $$          ");
		legFlag = false;
	}
	else
	{
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = true;
	}
}

void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");

}
int main()
{

	return 0;
}