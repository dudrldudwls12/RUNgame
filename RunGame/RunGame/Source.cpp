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
	system("Amumu, the Sad Mummy Run");
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

void DrawGameStart()  // 게임을 실행 했을때 나오는 상태창 입니다.
{
	system("cls");
	int x = 16;
	int y = 13;
	GotoXY(x, y);
	printf("============================");
	GotoXY(x, y +1);
	printf("============================");
	GotoXY(x, y +2);
	printf("====아무무 를 살려주세요====");
	GotoXY(x, y +3);
	printf("============================");
	GotoXY(x, y +4);
	printf("============================");
	GotoXY(x, y +5);
	printf("Z : 점프키");
	GotoXY(x, y +7);
	printf("※남은 기회는 5번이에요※");
	GotoXY(x, y +8);
	printf("※나무에 부딫히면 목숨이 줄어요ㅠㅠ※ ");
	GotoXY(x, y +9);
	printf("※미니언을 처치하면 목숨이 늘어나요!※ ");
	GotoXY(x, y +11);
	printf("※게임을 시작해서 아무무를 살려주세요 소환사님!※");
	printf("\n\n\n\n\n\n\n\n");
	_getch();
}

void DrawDino(int dinoY)
{
		GotoXY(0, dinoY);
		static bool legFlag = true;		// 아무무의 상체를 그리는 함수이며,
		printf("      &&&&&     \n");		// 고정된 상태입니다.
		printf("     &&&&&&&    \n");
		printf("     && & &&    \n");
		printf("     &&&&&&&    \n");
		printf("      &&&&      \n");
		printf("     &&&&&&     \n");
		printf("     &&&&&&    \n");
		printf("    && && &&    \n");
		printf("   &&  &&  &&   \n");
		printf("  &&   &&   &&  \n");
		printf(" &    &&      &   \n");

	if (legFlag)
	{
		printf("  &&      &&   \n");		// 아무무의 하체를 그리는 함수이며,
		printf("  &&      &&   \n");		// 고정된 상태입니다.
		legFlag = false;
	}
	else
	{
		printf("   &     &   \n");			// 아무무의 하체를 그리는 함수이며, 
		printf("  &       &   \n");			// 움직이는 상태입니다.
		legFlag = true;
	}
}

void DrawTree(int treeX)					// 장애물 을 나타내는 함수입니다.
{
	GotoXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$$$$");
	GotoXY(treeX, TREE_BOTTOM_Y + 1);
	printf("  $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 2);
	printf("  $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 3);
	printf("  $$  ");
	GotoXY(treeX, TREE_BOTTOM_Y + 4);
	printf("  $$  ");
}

 void DrawItem(int itemX)					// 미니언 을 나타내는 함수입니다.
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

void item_effect(int itemX)					// 미니언 처치시 나타나는 효과입니다.
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

void tree_effect(int treeX)					// 장애물에 부딪혔을때 나타나는 효과입니다.
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
	Sleep(100);
}

void DrawGameOver(const int score)				// 모든 기회를 소진시,
{																	// 게임이 종료되는 상태창 입니다.
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("                   ");
	GotoXY(x, y + 1);
	printf("       게임이       ");
	GotoXY(x, y + 2);
	printf("    종료되었습니다    ");
	GotoXY(x, y + 3);
	printf("                   ");
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
		return true;			// 장애물에 부딪히면 기회가 1개씩 줄어듭니다. 				
	}								// 아무무가 장애물에 걸리면 충돌로 처리됩니다.
	return false;	
}
bool isCollision2(const int treeX, const int itemX, const int dinoY, const int life)
{
	GotoXY(0, 0);
	printf("treeX : %d, itemX : %d, dinoY : %d, life : %d", treeX, itemX, dinoY, life);
	if (treeX <= 8 && treeX >= 6 && dinoY < 4)
	{
		return true;			// 미니언을 처치시 기회가 1개씩 추가되는 함수입니다.
	}
	return false;
}

int main()
{
	SetConsoleView();		// 
	DrawGameStart();
	while (true)
	{
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;
		int itemX = ITEM_BOTTOM_X;

		int score = 0;  
		int life = 5;
		clock_t start, curr;
		start = clock();

		while (true)
		{
			if (isCollision(treeX, itemX, dinoY, life)) 
			{
			
				life--;
				tree_effect(treeX);
				if (life <= 0)
					break;
			}

			if (isCollision2(treeX, itemX, dinoY, life)) 
			{
				life++;
				item_effect(itemX);
				
			}

			if (GetKeyDown() == 'z' && isBottom)
			{
				isJumping = true;
				isBottom = false;
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
				isBottom = true;
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
				isJumping = false;
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
			Sleep(60);
			system("cls");

			GotoXY(22, 0);
			printf("        점수표 : %d ", score);
		}

		DrawGameOver(score);
	}
	return 0;
}