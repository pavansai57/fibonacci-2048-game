#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int op1;
int op2;
int maxi = 0;
long long fibo[32] = { 0 };


struct leaderboardplayer{
	char name[30];
	int moves = 0;
	int max = 0;
	int played = 0;
	time_t starttime;
	time_t endtime;
	long long timeelapsed = 0;
};


struct storeplayer{

	char name[30];
	int moves2 = 0;
	int moves4 = 0;
	int max2 = 0;
	int max4 = 0;
	int played2 = 0;
	int played4 = 0;
	time_t starttime2;
	time_t starttime4;
	time_t endtime2;
	time_t endtime4;
	long long timeelapsed2 = 0;
	long long timeelapsed4 = 0;
	int board1[2][2];
	int board2[4][4];

};

struct player
{
	char name[30];
	int moves = 0;
	int max = 0;
	time_t starttime;
	time_t endtime;
	long long timeelapsed = 0;
	int** board;

};

int find(long long x)
{
	for (int i = 0; i < 33; i++)
	{
		if (fibo[i] == x)
			return i;
	}
	return -1;
}

int generatefibo()
{
	int i = 0;
	int j = 1;
	fibo[0] = 0;
	fibo[1] = 1;
	int count = 2;
	while (count < 32)
	{
		fibo[count] = i + j;
		int k = j;
		j = j + i;
		i = k;
		count++;
	}
	return 1;
}


void entername(struct player* p)
{
	system("cls");
	printf("Enter Username: ");
	scanf("%s", p->name);
}
