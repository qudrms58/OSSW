#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[9] = { 1,2,3,4,5,6,7,8,9 };

int checkmode(int f) {
	int i = 0;;
	for (i; i < 9; i++) {
		if (a[i] == f && a[i + 1] == f &&a[i + 2] == f && i % 3 == 0)
			return 10;
		else if (a[i] == f &&a[i + 3] == f &&a[i + 6] == f && i / 3 < 1)
			return 10;
	}
	if (a[0] == f && a[4] == f && a[8] == f)
		return 10;
	if (a[2] == f && a[4] == f && a[6] == f)
		return 10;
}

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
			a[temp - 1] = 0;
			if (checkmode(0) == 10) {
				printf("\t\t  %d |  %d  | %d  \n", a[0], a[1], a[2]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[3], a[4], a[5]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[6], a[7], a[8]);
				printf("\n\tYou Win\n");
				break;
			}
			if (i == 9) {
				printf("\t\t  %d |  %d  | %d  \n", a[0], a[1], a[2]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[3], a[4], a[5]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[6], a[7], a[8]);
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
			a[bot - 1] = -1;
			if (checkmode(-1) == 10) {
				printf("\t\t  %d |  %d  | %d  \n", a[0], a[1], a[2]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[3], a[4], a[5]);
				printf("\t\t---------------\n");
				printf("\t\t  %d |  %d  | %d  \n", a[6], a[7], a[8]);
				printf("\n\tYou Lose\n");
				break;
			}
			printf("\t\t  %d |  %d  | %d  \n", a[0], a[1], a[2]);
			printf("\t\t---------------\n");
			printf("\t\t  %d |  %d  | %d  \n", a[3], a[4], a[5]);
			printf("\t\t---------------\n");
			printf("\t\t  %d |  %d  | %d  \n", a[6], a[7], a[8]);
		}
	}


	return 0;
}

void main() {
	int opt, fir;
	printf("Press 0:user vs user\nPress 1:user vs bot(easy)\nPress 2:user vs bot(hard) : ");
	scanf("%d", &opt);
	printf("Press 1:for user input\nPress 0:for bot input\n");
	scanf("%d", &fir);
	printf("YOU=0 COM=-1\n\n");
	printf("\t\t  %d |  %d  | %d  \n", a[0], a[1], a[2]);
	printf("\t\t---------------\n");
	printf("\t\t  %d |  %d  | %d  \n", a[3], a[4], a[5]);
	printf("\t\t---------------\n");
	printf("\t\t  %d |  %d  | %d  \n", a[6], a[7], a[8]);
	if (opt == 1)
		easymode(fir);
}