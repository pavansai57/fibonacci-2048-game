#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Header1.h"
#include"Header.h"
#include"Header2.h"
#include"Header3.h"

void playGame(struct player *p, int n);

int Game(struct player* p,int n)
{
	while (1)
	{
		int g=canmove(p, 't', n);
		if (g == 11||g>0)
		{
			system("cls");
			displayboard(p, n);
			printf("\nENTER Move:");
			char move;
			scanf_s("%c", &move);
			while (move != 'a' && move != 'd' && move != 's' && move != 'w' && move != 'z')
				scanf_s("%c", &move);
			if (move == 'z')
			{
				saveplayer(p, n);
				return -4;
			}
			printf("\n");
			int y = makemove(p, move, n);
			if (y == -1)
			{
				if (p->max == fibo[2 * (op2 * 2 * op2 * 2) - 1])
				{
					p->endtime = time(NULL);
					return 123;
				}
				p->endtime = time(NULL);
				return -2;
			}
			if (y != -10)
			{
				p->moves = p->moves + 1;
				if (p->max == fibo[2 * (op2 * 2 * op2 * 2) - 1])
				{
					p->endtime = time(NULL);
					return 123;
				}
				generaterandomtile(p, n);
			}
		}
		else
		{
			p->endtime = time(NULL);
			if (p->max == fibo[2 * (op2 * 2 * op2 * 2) - 1])
			{
				return 123;
			}
			return -3;
		}
	}

}

int LeaderBoard()
{
	return 0;
}
int main()
{

	generatefibo();
	printf(" 1.Play Game\n");
	printf(" 2.Return to previous game\n");
	printf(" 3.LeaderBoard\n");
	printf(" 4.Show saved data\n");

	scanf_s("%d", &op1);
	if (op1 == 1)
	{
		printf(" Play which Game?\n 1. 2x2 Board\n 2. 4x4 Board\n\n ");
		scanf_s("%d", &op2);
		struct player* p=(struct player*)malloc(1*sizeof(struct player));
		entername(p);
		initializeboard(p, op2*2);
		generaterandomtile(p, op2*2);
		generaterandomtile(p, op2*2);
		p->starttime = time(NULL);
		int v=Game(p,op2*2);
		system("cls");
		displayboard(p, op2*2);
		p->timeelapsed = (p->endtime) - (p->starttime);
		if (v == -3)
		{
			printf("No Moves Left: Game Over\n\n");
		}
		else if (v == 123)
		{
			printf("\nYou WIN!\n");
			transferdetails(p, op2*2);
			displayleaderboardsorted();
		}
		else if (v == -4)
		{
			printf("\nSaved your game\n");
		}
		printf("Your Play Time is: %lld sec\n",(p->endtime)-(p->starttime));
	}
	else if (op1 == 2)
	{
		struct player* p = (struct player*)malloc(1 * sizeof(struct player));
		entername(p);
		int check = -1;
		struct storeplayer b = checkplayer(p, &check);
		p->starttime = time(NULL);
		if (check < 0)
		{
			printf("wrong username\n");
			char c, q;
			gets(&c);
			gets(&q);
			return 1;
		}
		else
		{
			int d = 0;
			printf("1.2x2\n2.4x4 ?\n");
			scanf("%d", &d);
			if (b.max2 == fibo[2 * d * 2 * d * 2 - 1])
			{
				printf("2x2 board is already solved\n");
				printf("press enter to exit\n");
				char c,q;
				gets(&c);
				gets(&q);
				return 1;
			}
			else if (b.max4 == fibo[2 * d * 2 * d * 2 - 1])
			{
				printf("4x4 board is already solved\n");
				printf("press enter to exit\n");
				char c,q;
				gets(&c);
				gets(&q);
				return 1;
			}
			loadplayer(p, b, d);
			playGame(p,d*2);
		}
	}
	else if (op1==3)
	{
		displayleaderboardsorted();
	}
	else if (op1 == 4)
	{
		printsavedplayer();
	}
	printf("press enter to exit\n");
	char c;
	gets(&c);
	gets(&c);
	return 0;
}

void playGame(struct player *p,int n)
{
	generatefibo();
	int e = checkifempty(p, n);
	op2 = n/2;
	if (e == 1)
	{
		generaterandomtile(p, n);
		generaterandomtile(p, n);
	}
	p->starttime = time(NULL);
	int v = Game(p, n);
	system("cls");
	displayboard(p, n);
	p->timeelapsed = (p->endtime) - (p->starttime);
	if (v == -3)
	{
		printf("No Moves Left: Game Over\n\n");
		printf("Your Play Time is: %lld sec\n", (p->endtime) - (p->starttime));
		//initializeboard(p, n);
	}
	else if (v == 123)
	{
		printf("\nYou WIN!\n");
		transferdetails(p, n);
		displayleaderboardsorted();
		printf("Your Play Time is: %lld sec\n", (p->endtime) - (p->starttime));
		//initializeboard(p, n);
	}
	else if (v == -4)
	{
		printf("\nSaved your game\n");
		printf("Your Play Time is: %lld sec\n", (p->endtime) - (p->starttime));
	}
}
