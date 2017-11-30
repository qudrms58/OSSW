//
//  main.c
//  Tic_Tac_Toe
//
//  Created by 김태균 on 2017. 11. 29..
//  Copyright © 2017년 김태균. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>

int a[7][7] = { 0 };			//a[3][3] => a[7][7]
int player=1,opponent=0;

int maxnum(int n,int b)
{
    if(n>b)
        return n;
    else
        return b;
}
int minnum(int n,int b)
{
    if(n<b)
    {
        return n;
    }
    else
        return b;
}

void init(); //오목판 좌표 초기화
int isempty(int g[][3])
{
    int m,l;
    for(m=0;m<3;m++)
    {
        for(l=0;l<3;l++)
        {
            if(g[m][l]==-1)
            {
                return 1;
            }
            
        }
    }
    return 0;
    
}
void display()
{
    printf("\n\n");
    
    printf("\t\t\t  %d | %d  | %d  \n", a[0][0],
           a[0][1], a[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %d | %d  | %d  \n", a[1][0],
           a[1][1], a[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t  %d | %d  | %d  \n\n",a[2][0],
           a[2][1], a[2][2]);
    
    return;
}

int iswin(int b[3][3])
{
    int row;
    int col;
    for ( row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }
    
    // Checking for Columns for X or O victory.
    for (col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return +10;
            
            else if (b[0][col]==opponent)
                return -10;
        }
    }
    
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }
    
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }
    
    // Else if none of them have won then return 0
    return 0;
}
int minimax(int player,int depth,int h[][3])
{
    
    int best,i,j,k,l;
    if(iswin(h)==10)
    {
        return 10;
    }
    if(iswin(h)==-10)
    {
        return -10;
    }
    if(isempty(h)==0)
    {
        return 0;
    }
    if (player==0)
    {
        best=99;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(h[i][j]==-1)
                {
                    h[i][j]=0;
                    best=min(best,minimax(1,depth+1,h));
                    
                    h[i][j]=-1;
                }
            }
        }
        return best;
    }
    if (player==1)
    {
        best=-99;
        for(k=0;k<3;k++)
        {
            for(l=0;l<3;l++)
            {
                if(h[k][l]==-1)
                {
                    h[k][l]=1;
                    best=max(best,minimax(0,depth+1,h));
                    h[k][l]=-1;
                }
            }
        }
        return best;
    }
    else
        return 0;
}

void bot()
{
    int bestval=99;
    int movex=-1;
    int movey=-1;
    int score;
    int m,n;
    for(m=0;m<3;m++)
    {
        for(n=0;n<3;n++)
        {
            if(a[m][n]==-1)
            {
                a[m][n]=0;
                score=minimax(1,0,a);
                if(score<bestval)
                {
                    bestval=score;
                    movex=m;
                    movey=n;
                }
                a[m][n]=-1;
            }
        }
    }
    a[movex][movey]=0;
    
    
}

void user()
{
    int x,y;
    printf("Enter x&y coordinates:");
    scanf("%d%d",&x,&y);
    
    a[x][y]=1;
}

int easymode(int f);

int main()
{
    int OptForMode, fir;
	int t;
	
	init();

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

    printf("Press 1:for user input\nPress 0:for bot input\n");
   // scanf("%d",&t);
    
    while(1)
    {
        if(t==1)
        {
            user();
            display();
            if(iswin(a)==10)
            {
                printf("User wins\n");
                exit(0);
            }
            t--;
            
        }
        if(t==0)
        {
            bot();
            display();
            if(iswin(a)==-10)
            {
                printf("Bot wins\n");
                exit(0);
            }
            t++;
        }
        if(isempty(a)==0)
        {
            printf("The game has resulted in a draw");
            exit(0);
        }
        
    }
}

void init()
{
	int i, j;
	for (i = 0; i<7; i++)
	{
		for (j = 0; j<7; j++)
		{
			a[i][j] = i + j + 1;
		}
	}
	return;
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
			//a[temp - 1] = 0;

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

		//	a[bot - 1] = -1;
			
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
