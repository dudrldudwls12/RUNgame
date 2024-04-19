#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define ITEM_BOTTOM_Y 5
#define ITEM_BOTTOM_X 45

using namespace std;

typedef struct Character
{
	char name[20];
}Character;

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
	printf("======세기말 살기위해뛰는 게임=======");
	GoToXY(x, y, + 3);
	printf("===========================");
	GoToXY(x, y, + 4);
	printf("===========================");
	GoToXY(x, y, + 5);
	printf("Z : 점프키");
	GoToXY(x, y, + 7);
	printf("남은 목숨 5개");
	GoToXY(x, y, + 8);
	printf("나무에 부딫히면 목숨이 차감 --.");
	GoToXY(x, y, + 9);
	printf("당근을 먹으면 목숨이 늘어남 ++.");
	GoToXY(x, y, + 11);
	printf("게임시작 하려면 아무키나 누르시오.");
	printf("\n\n\n\n\n\n\n\n");
	getch();
}

void DrawDino(int dinoY)
{
	 GotoXY(0, dinoY);
	 static BOOL legFlag = TRUE;
	 printf("    &&&&    \n");
	 printf("  &&&&&&  \n");
	 printf(" &&&&&&& \n");
	 printf(" &&&&&&& \n");
	 printf("   &&&&&   \n");
	 printf("   &&&&&   \n");
	 printf("    &&&&    \n");
	 printf("     &&&     \n");
	 printf("     &&&     \n");
	 if (legFlag)
	 {
	 	printf	(" &&  &&  \n");
	 	printf("   &   &    \n");
	 	legFlag = FALSE;
	 }
	 else
	 {
	 	printf("     &&&  &     \n");
	 	printf("          &&    ");
		
	 	legFlag = TRUE;
	 }
}

void DrawTree(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf("  $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf("  $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf("  $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf("  $$  ");
}

void DrawItem(int itemX)
{
	GotoXY(itemX, ITEM_BOTTOM_Y);
	printf(" **** ");
	GotoXY(itemX, ITEM_BOTTOM_Y + 1);
	printf("   **   ");
	GotoXY(itemX, ITEM_BOTTOM_Y + 2);
	printf("   **  ");
	GotoXY(itemX, ITEM_BOTTOM_Y + 3);
	printf(" **** ");
}

void itme_effect(int itmeX)
{
	GotoXY(itemX, ITEM_BOTTOM_Y);
	printf(" ^^    ^^");
	GotoXY(itemX, ITEM_BOTTOM_Y + 1);
	printf(" ^    ^   ^");
	GotoXY(itemX, ITEM_BOTTOM_Y + 2);
	printf(" ^    ^   ^");
	GotoXY(itemX, ITEM_BOTTOM_Y + 3);
	printf(" ^    ^   ^");
	GotoXY(itemX, ITEM_BOTTOM_Y + 4);
	printf(" ^    ^   ^");
}

void tree_effect(int treeX)
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("@*@*@*@");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf("@*@*@*@");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf("@*@*@*@");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf("@*@*@*@");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf("@*@*@*@");
}

void DrawGameOver(const int score)
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("%%%%%%%%%%");
	GotoXY(x, y + 1);
	printf("%게임 종료 되었어요%");
	GotoXY(x, y + 2);
	printf("%%%%%%%%%%");
	GotoXY(x, y + 5);
	printf("최종점수 : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

BOOL isCollision(const int treeX, const int itemX, const int dinoY, const life)
{
	GotoXY(0, 0);
	printf("treeX : %d, itemX : %d, dinoY : %d, life : %d", treeX, itmeX, dinoY, life);
	if (treeX <= 7 && treeX >= 6 && dinoY > 8)
	{
		return TRUE;
	}
	return FALSE;
}

BOOL isCollision(const int treeX, const int itemX, const int dinoY, const life)
{
	GotoXY(0, 0);
	printf("treeX : %d, itemX : %d, dinoY : %d, life : %d", treeX, itmeX, dinoY, life);
	if (itemX <= 8 && itemX >= 6 && dinoY < 4)
	{
		return TRUE;
	}
	return FALSE;
}

int main()
{
	SetConsoleView();
	DrawGameStart();
	while (TRUE)
	{
		BOOL isJumping = FALSE;
		BOOL isBOTTOM = TRUE;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;
		int itemX = ITEM_BOTTOM_X;
	
		int score = 0;
	
		int life = 5;
		clock_t start,
	}
	
	Character 


	return 0;
}