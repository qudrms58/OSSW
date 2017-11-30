//  main.c
//  Tic_Tac_Toe
//
//  Created by 김태균 on 2017. 11. 29..
//  Copyright © 2017년 김태균. All rights reserved.

//룰은 3목은 너무 쉽고 5목은 코드 짜기 힘들어 4목으로 한다.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[7][7] = { 0 };			//a[3][3] => a[7][7]
int player = 1, opponent = 0;

void init(); //4목판 좌표 초기화
void display(); //4목판 좌표 보여주기
void user(); //유저가 돌 놓기
void bot(); //봇이 돌 놓기
int iswin(int b[7][7]); //승리자 보여주기

int maxnum(int n, int b);
int minnum(int n, int b);
int minimax(int player, int depth, int h[][3]);
int easymode(int f);
void hardmode(int fir);

int main()
{
	int OptForMode, fir;
	int t, i;

	init();
	display();
	//모드 선택
	printf("Press 0:user vs user\n");
	printf("Press 1:user vs bot(easy)\n");
	printf("Press 2:user vs bot(hard) : ");
	scanf("%d", &OptForMode);
	printf("\n");

	printf("Press 1:for user input\nPress 0:for bot input : ");
	scanf("%d", &fir);
	printf("\n");

	hardmode(fir);
	//if (OptForMode == 1)
//		easymode(fir);
//	else if (OptForMode == 2)
//		hardmode(fir);

	printf("Press 1:for user input\nPress 0:for bot input\n");
	scanf("%d", &t);

	while (1)
	{
		if (t == 1)
		{
			user();
			i++;
			display();
			if (iswin(a) == 10)
			{
				printf("User wins\n");
				exit(0);
			}
			t--;

		}
		if (t == 0)
		{
			bot();
			i++;
			display();
			if (iswin(a) == -10)
			{
				printf("Bot wins\n");
				exit(0);
			}
			t++;
		}
		if (i == 49)
		{
			printf("The game has resulted in a draw");
			exit(0);
		}

	}
}

void init()
{
	int i, j, k = 1;

	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			a[i][j] = k++;
		}
	}
}
void display()
{
	int i, j;

	printf("\n\n");

	for (i = 0; i < 7; i++) {
		printf("\t\t\t  ");
		for (j = 0; j < 7; j++) {
			printf("%-3d|", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void user()
{
	int location, x, y;

	while (1) {
		printf("Enter location:");
		scanf("%d", &location);

		x = (location - 1) / 7;
		y = (location - 1) % 7;

		if (a[x][y] == 0 || a[x][y] == -1) {
			printf("Other location\n");
			continue;
		}
		else break;
	}

	a[x][y] = 0;

}
void bot()
{
	int bot, x, y;

	srand(time(NULL));

	while (1) {
		bot = rand() % 10;
		x = (bot - 1) / 7;
		y = (bot - 1) % 7;
		if (bot != 0 && a[x][y] != 0 && a[x][y] != -1) {
			a[x][y] = -1;
			break;
		}
	}
}
int iswin(int b[7][7])
{
	int hor, col;

	// Checking for horizontal
	for (col = 0; col < 7; col++) {
		for (hor = 0; hor < 4; hor++) {
			if (b[col][hor] == b[col][hor + 1] && b[col][hor + 1] == b[col][hor + 2]
				&& b[col][hor + 2] == b[col][hor + 3]) {
				return 10;
			}
		}
	}

	// Checking for Columns
	for (hor = 0; hor < 7; hor++) {
		for (col = 0; col < 4; col++) {
			if (b[col][hor] == b[col + 1][hor] && b[col + 1][hor] == b[col + 2][hor]
				&& b[col + 2][hor] == b[col + 3][hor]) {
				return 10;
			}
		}
	}

	// Checking for Diagonals for X or O victory.
	for (hor = 0; hor < 4; hor++) {
		for (col = 0; col < 4; col++) {
			if (b[col][hor] == b[col + 1][hor + 1] && b[col + 1][hor + 1] == b[col + 2][hor + 2]
				&& b[col + 2][hor + 2] == b[col + 3][hor + 3]) {
				return 10;
			}
		}
	}

	/*
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
	if (b[0][0] == player)
	return +10;
	else if (b[0][0] == opponent)
	return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
	if (b[0][2] == player)
	return +10;
	else if (b[0][2] == opponent)
	return -10;
	}*/

	// Else if none of them have won then return 0
	return 0;
}

int maxnum(int n, int b)
{
	if (n>b)
		return n;
	else
		return b;
}

int minnum(int n, int b)
{
	if (n<b)
	{
		return n;
	}
	else
		return b;
}
/*
int minimax(int player, int depth, int h[][3])
{

	int best, i, j, k, l;
	if (iswin(h) == 10)
	{
		return 10;
	}
	if (iswin(h) == -10)
	{
		return -10;
	}
	if (isempty(h) == 0)
	{
		return 0;
	}
	if (player == 0)
	{
		best = 99;
		for (i = 0; i<3; i++)
		{
			for (j = 0; j<3; j++)
			{
				if (h[i][j] == -1)
				{
					h[i][j] = 0;
					best = min(best, minimax(1, depth + 1, h));

					h[i][j] = -1;
				}
			}
		}
		return best;
	}
	if (player == 1)
	{
		best = -99;
		for (k = 0; k<3; k++)
		{
			for (l = 0; l<3; l++)
			{
				if (h[k][l] == -1)
				{
					h[k][l] = 1;
					best = max(best, minimax(0, depth + 1, h));
					h[k][l] = -1;
				}
			}
		}
		return best;
	}
	else
		return 0;
}
*/
/*
int easymode(int f) {
	int temp, bot, i = 0;;

	srand(time(NULL));

	while (1) {
		if (f == 1) {
			printf("Enter location:");
			scanf("%d", &temp);

			if (a[temp - 1] == 0 || a[temp - 1] == -1) {
				printf("Other location\n");
				continue;
			}

			i++;
			//a[temp - 1] = 0;

			if (checkmode(0) == 10) {
				printf("\t\t  %d |  %d  | %d  \n", a[0][0], a[0][1], a[0][2]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[1][3], a[1][4], a[1][5]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[2][6], a[2][7], a[2][8]);
				printf("\n\tYou Win\n");
				break;
			}

			if (i == 9) {
				printf("\t\t  %d |  %d  | %d  \n", a[0][0], a[0][1], a[0][2]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[1][3], a[1][4], a[1][5]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[2][6], a[2][7], a[2][8]);
				printf("\n\tThe Game Is DRAW\n");
				break;
			}

			while (1) {
				bot = rand() % 10;
				if (bot != 0 && a[bot - 1] != 0 && a[bot - 1] != -1) {
					i++;
					break;
				}
			}

			//	a[bot - 1] = -1;

			if (checkmode(-1) == 10) {
				printf("\t\t  %d |  %d  | %d  \n", a[0][0], a[0][1], a[0][2]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[1][3], a[1][4], a[1][5]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[2][6], a[2][7], a[2][8]);
				printf("\n\tYou Lose\n");
				break;
			}

			printf("\t\t  %d |  %d  | %d  \n", a[0][0], a[0][1], a[0][2]);
			printf("\t\t---------------\n");
			printf("\t\t  %d |  %d  | %d  \n", a[1][3], a[1][4], a[1][5]);
			printf("\t\t---------------\n");
			printf("\t\t  %d |  %d  | %d  \n", a[2][6], a[2][7], a[2][8]);
		}
	}

	return 0;
}
*/

void hardmode(int fir)
{
	int temp, i = 0;
	int x, y;

	srand(time(NULL));

	while (1) {
		//유저가 먼저 돌을 놓는다.
		if (fir == 1) {
			user();
			i++;

			//유저가 이겼다
			if (iswin(a) == 10) {
				display();
				printf("\n\tYou Win\n");
				break;
			}

			//게임이 비겼다
			if (i == 49) {
				display();
				printf("\n\tThe Game Is DRAW\n");
				break;
			}

			//봇이 돌을 놓을 곳을 찾는다.
			bot();
			i++;

			//봇이 이겼다.
			if (iswin(a) == 10) {
				display();
				printf("\n\tYou Lose\n");
				break;
			}

			//누구도 이기지 않아 현재상황만 출력한다.
			display();
		}
	}
}