#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
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
	printf("===========================");
	GotoXY(x, y +1);
	printf("===========================");
	GotoXY(x, y +2);
	printf("=====살기위해뛰는 게임=====");
	GotoXY(x, y +3);
	printf("===========================");
	GotoXY(x, y +4);
	printf("===========================");
	GotoXY(x, y +5);
	printf("Z : 점프키");
	GotoXY(x, y +7);
	
	GotoXY(x, y +8);
	printf("나무에 부딫히면 목숨이 차감 --.");
	GotoXY(x, y +9);
	printf("당근을 먹으면 목숨이 늘어남 ++.");
	GotoXY(x, y +11);
	printf("게임시작 하려면 아무키나 누르시오.");
	printf("\n\n\n\n\n\n\n\n");
	_getch();
}

void DrawDino(int dinoY)
{
		GotoXY(0, dinoY);
		static BOOL legFlag = TRUE;
		printf("        &&      \n");
		printf("       &&&&     \n");
		printf("       &&&&&    \n");
		printf("       &&&&&    \n");
		printf("       &&& &&&  \n");
		printf("       &&&&&&   \n");
		printf("      &&&&&     \n");
		printf(" &&  &&&&&&&&   \n");
		printf(" &&  &&&&&&&    \n");
		printf("  && &&&&&&&    \n");
		printf("    &&&&&&&&    \n");

	if (legFlag)
	{
		printf(" &&  &&  \n");
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

void itme_effect(int itemX)
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
	printf("%%%%%%%%%%&&&&&&&&");
	GotoXY(x, y + 1);
	printf("게임 오버");
	GotoXY(x, y + 2);
	printf("%%%%%%%%%%&&&&&&&&");
	GotoXY(x, y + 5);
	printf("최종점수 : %d", score);

	printf("\n\n\n\n\n\n\n\n\n");
	system("pause");
}

bool isCollision(const int treeX, const int itemX, const int dinoY, const int life)
{
	GotoXY(0, 0);
	printf("treeX : %d, itemX : %d, dinoY : %d, life : %d", treeX, itemX, dinoY, life);
	if (treeX <= 7 && treeX >= 6 && dinoY > 8)
	{
		return true;
	}
	return false;
}

//bool isCollision(const int treeX, const int itemX, const int dinoY, const int life)
//{
//	GotoXY(0, 0);
//	printf("treeX : %d, itemX : %d, dinoY : %d, life : %d", treeX, itemX, dinoY, life);
//	if (itemX <= 8 && itemX >= 6 && dinoY < 4)
//	{
//		return true;
//	}
//	return false;
//}

int main()
{
	SetConsoleView(); 
	DrawGameStart();
	while (TRUE)
	{
		BOOL isJumping = FALSE;
		BOOL isBottom = TRUE;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;
		int itemX = ITEM_BOTTOM_X;

		int score = 0;  
		int life = 2;
		clock_t start, curr;
		start = clock();

		while (TRUE)
		{
			if (isCollision(treeX, itemX, dinoY, life)) 
			{
			
				life--;

				tree_effect(treeX);
				if (life != 0) break;
			}

			if (isCollision(treeX, itemX, dinoY, life)) 
			{
				life++;
				//item_effect(itemX);
			}

			if (GetKeyDown() == 'z' && isBottom)
			{
				isJumping = TRUE;
				isBottom = FALSE;
			}

			if (isJumping)
			{
				dinoY -= gravity;

			}
			else
			{
				dinoY += gravity;
			}

			if (dinoY >= DINO_BOTTOM_Y)
			{
				dinoY = DINO_BOTTOM_Y;
				isBottom = TRUE;
			}

			treeX -= 2;
			itemX -= 1;

			if (score >= 5) 
			{
				treeX -= 1;
			}

			if (treeX <= 0)
			{
				treeX = TREE_BOTTOM_X;
			}

			if (itemX <= 0)
			{
				itemX = ITEM_BOTTOM_X;
			}

			if (dinoY <= 4)
			{
				isJumping = FALSE;
			}

			DrawDino(dinoY);
			DrawTree(treeX);
			DrawItem(itemX);	

			curr = clock();
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)
			{
				score++;
				start = clock();
			}
			Sleep(70);
			system("cls");

			GotoXY(22, 0);
			printf("        점수표 : %d ", score);
		}

		DrawGameOver(score);
	}
	return 0;
}