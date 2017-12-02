#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[7][7];
int player = 1, opponent = 0;

void init() {
	int i, j, k = 1;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 7; j++) {
			a[i][j] = k++;
		}
	}
}

void user(){
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

void display(){
	int i, j;
	printf("\n\n");
	for (i = 0; i < 7; i++) {
		printf("\t\t\t *---*---*---*---*---*---*---*\n");
		printf("\t\t\t |");
		for (j = 0; j < 7; j++) {
			printf("%3d|", a[i][j]);
		}
		printf("\n");
	}
	printf("\t\t\t *---*---*---*---*---*---*---*\n");
	printf("\n");
}

void bot(){
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

int iswin(int b[7][7]){
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

	// Else if none of them have won then return 0
	return 0;
}

int hardmode(int fir){
	int i = 0;

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
	return 0;
}

int easymode(int fir) {
	int i = 0;
	while (1) {
		if (fir == 1) { //유저의 선공
			user();
			i++;
			if (iswin(a) == 10) { //사용자체크
				display();
				printf("\n\tYou Win\n");
				break;
			}

			if (i == 49) { //무승부
				display();
				printf("\n\tThe Game Is DRAW\n");
				break;
			}

			bot();
			i++;

			if (iswin(a) == 10) { //컴퓨터 체크
				display();
				printf("\n\tYou Lose\n");
				break;
			}

			display(); //계속두기
		}
	}
	return 0;
}

void main()
{
	int OptForMode, fir;

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

	if (OptForMode == 1)
		easymode(fir);
	else if (OptForMode == 2)
		hardmode(fir);
	/*else if (OptForMode == 0) 유저모드가 생길경우
	usermode(fir);*/
}