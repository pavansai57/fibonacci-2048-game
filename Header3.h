void addtoleaderboard(struct leaderboardplayer* p, int n);

struct storeplayer checkplayer(struct player* p, int* check);

void displaystruct(struct leaderboardplayer x)
{
	printf("%-10s", x.name);
	/*for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%3d", x.board1[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d", x.board2[i][j]);
		}
		printf("\n");
	}*/
	if (x.played == 2)
		printf("2x2       ");
	else
		printf("4x4       ");
	printf("%-10d", x.moves);
	printf("%-10d\n", x.timeelapsed);
	//printf("%10d\n", x.max);
	
}



void displayleaderboardsorted()
{
	int count = 0;
	FILE* f = fopen("leader.bin", "rb");
	struct leaderboardplayer b;
	while (fread(&b, sizeof(struct leaderboardplayer), 1, f) == 1)
	{
		count++;
	}
	fclose(f);
	struct leaderboardplayer* x = (struct leaderboardplayer*)malloc(count*sizeof(struct leaderboardplayer));
	int i = 0;
	f = fopen("leader.bin", "rb");
	while (fread(&x[i], sizeof(struct leaderboardplayer), 1, f) == 1)
	{
		i++;
	}

	for (int j = 0; j < count; j++)
	{
		for (int k = 0; k < count-1; k++)
		{
			if (x[k].timeelapsed > x[k + 1].timeelapsed)
			{
				struct leaderboardplayer temp=x[k];
				x[k] = x[k + 1];
				x[k + 1] = temp;
			}
		}
	}
	printf("Name      Board     Moves     Time(sec)\n\n%");
	for (int k = 0; k < count; k++)
	{
		displaystruct(x[k]);
		printf("\n");
	}
}

void displayleaderboard()
{
	FILE* f = fopen("leader.bin", "rb");
	struct leaderboardplayer b;
	while (fread(&b, sizeof(struct leaderboardplayer), 1, f)==1)
	{
		printf("%s\n", b.name);
		/*for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%3d", b.board1[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%3d", b.board2[i][j]);
			}
			printf("\n");
		}*/
		printf("moves:%d\n", b.moves);
		printf("max:%d\n", b.max);
		printf("time elapsed:%d\n\n", b.timeelapsed);
	}
}

void transferdetails(struct player* p1,int n)
{
	struct leaderboardplayer p2;
	int i = 0;
	while (p1->name[i] != '\0')
	{
		p2.name[i] = p1->name[i];
		i++;
	}
	p2.name[i] = '\0';
	p2.moves = p1->moves;
	p2.max = p1->max;
	p2.starttime = p1->starttime;
	p2.endtime = p1->endtime;
	p2.timeelapsed = p1->timeelapsed;
	if (n == 2)
		p2.played = 2;
	else if (n == 4)
		p2.played = 4;
  /*if (n == 2)
	{
		p2.played2 = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				p2.board1[i][j] = p1->board[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				p2.board2[i][j] = 0;
			}
		}
	}
	else if (n == 4)
	{
		p2.played4 = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				p2.board2[i][j] = p1->board[i][j];
			}
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				p2.board1[i][j] = 0;
			}
		}
	}
	*/
	addtoleaderboard(&p2, n); 

}

void addtoleaderboard(struct leaderboardplayer* p, int n)
{
	FILE* f = fopen("leader.bin", "ab");
	if (f == NULL)
		printf("not open");
	else
	{
		fwrite(p, sizeof(struct leaderboardplayer), 1, f);
	}
	fclose(f);
}


void saveplayer(struct player* p,int n)
{
	int check = -1;
	struct storeplayer b=checkplayer(p, &check);

	if (check >=0)
	{
		if (n == 2)
		{
			b.moves2 =p->moves;
			b.max2 = p->max;
			if (b.played2 == 0)
				b.starttime2 = p->starttime;
			p->endtime = time(NULL);
			b.endtime2 = p->endtime;
			b.timeelapsed2 = b.timeelapsed2 + (p->endtime) - (p->starttime);
			b.played2 = 2;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					b.board1[i][j] = p->board[i][j];
				}
			}
		}
		else if (n == 4)
		{
			b.moves4 = p->moves;
			b.max4 = p->max;
			if (b.played4 == 0)
				b.starttime4 = p->starttime;
			p->endtime = time(NULL);
			b.endtime4 = p->endtime;
			b.timeelapsed4 = b.timeelapsed4 + (p->endtime) - (p->starttime);
			b.played4 = 4;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					b.board2[i][j] = p->board[i][j];
				}
			}
		}
		
		FILE* f = fopen("saved.bin", "wb");
		//fseek(f, check*sizeof(struct storeplayer), SEEK_CUR);
		fwrite(&b, sizeof(struct storeplayer), 1, f);
		fclose(f);
	}
	else
	{
		FILE* f = fopen("saved.bin", "wb");
		struct storeplayer c;
		int v = 0;
		while (p->name[v] != '\0')
		{
			c.name[v] = p->name[v];
			v++;
		}
		c.name[v] = '\0';

		if (n == 2)
		{
			c.moves2 = p->moves;
			c.moves4 = 0;
			c.max2 = p->max;
			c.max4 = 0;
			c.starttime2 = p->starttime;
			p->endtime = time(NULL);
			c.endtime2 = time(NULL);
			c.timeelapsed2 =c.endtime2 - (p->starttime);
			c.timeelapsed4 = 0;
			c.played2 = 2;
			c.played4 = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					c.board1[i][j] = p->board[i][j];
				}
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					c.board2[i][j] = 0;
				}
			}
		}
		else if (n == 4)
		{
			c.moves4 = p->moves;
			c.moves2 = 0;
			c.max4 = p->max;
			c.max2 = 0;
			c.starttime4 = p->starttime;
			p->endtime = time(NULL);
			c.endtime4 = time(NULL);
			c.timeelapsed4 = c.endtime4 - (p->starttime);
			c.timeelapsed2 = 0;
			c.played4 = 4;
			c.played2 = 0;
			
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					c.board2[i][j] = p->board[i][j];
				}
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					c.board1[i][j] = 0;
				}
			}
		}

		fwrite(&c, sizeof(struct storeplayer), 1, f);
		fclose(f);
	}	
}

struct storeplayer checkplayer(struct player* p,int* check)
{
	FILE* f = fopen("saved.bin", "rb");
	struct storeplayer b;
	int i = 0;
	while (fread(&b, sizeof(struct storeplayer), 1, f) == 1);
	{
		if (strcmp(b.name, p->name) == 0)
		{
			*check = i;
			fclose(f);
			return b;
		}
		i++;
	}
	fclose(f);
	return b;
}

void printsavedplayer()
{
	FILE* f = fopen("saved.bin", "rb");
	struct storeplayer b;
	while (fread(&b, sizeof(struct storeplayer), 1, f))
	{
		printf("name:%s\n", b.name);
		printf("moves2:%d\n",b.moves2);
		printf("moves4:%d\n",b.moves4);
		printf("max2:%d\n",b.max2);
		printf("max4:%d\n", b.max4);
		printf("played2:%d\n", b.played2);
		printf("played4:%d\n", b.played4);
		printf("starttime2:%d\n", b.starttime2);
		printf("starttime4:%d\n", b.starttime4);
		printf("endtime2:%d\n", b.endtime2);
		printf("endtime4:%d\n", b.endtime4);
		printf("timeelapsed2:%lld\n", b.timeelapsed2);
		printf("timeelapsed4:%lld\n\n", b.timeelapsed4);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%d", b.board1[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				printf("%d", b.board2[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	}
}

void loadplayer(struct player* p, struct storeplayer b,int d)
{
	if (d == 1)
	{
		initializeboard(p, d * 2);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				p->board[i][j] = b.board1[i][j];
			}
		}
		p->starttime = time(NULL);
		p->moves = b.moves2;
		p->max = b.max2;
		p->timeelapsed = b.timeelapsed2;
		return;
	}
	else if (d == 2)
	{
		initializeboard(p, d * 2);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				p->board[i][j] = b.board2[i][j];
			}
		}
		p->starttime = time(NULL);
		p->moves = b.moves4;
		p->max = b.max4;
		p->timeelapsed = b.timeelapsed4;
		return;
	}
}