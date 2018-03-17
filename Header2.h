void initializeboard(struct player* p, int n)
{
	p->board = (int**)malloc(n*sizeof(int*));
	for (int i = 0; i < n; i++)
		p->board[i] = (int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p->board[i][j] = 0;
		}
	}
	p->moves = 0;
	p->max = 0;
	p->starttime = time(NULL);

}


void displayboard(struct player *p, int n)
{
	printf("\n\n\n");
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%3d", p->board[i][j]);
		}
		printf("\n\n\n");
	}
	printf("Move Count is: %d                          MaxTile is: %d\n", p->moves, p->max);
}



int checkiffull(struct player* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (p->board[i][j] == 0)
				return 0;
		}
	}
	return 1;
}



int generaterandomtile(struct player* p, int n)
{
	if (!checkiffull(p, n))
	{
		srand((unsigned)time(NULL));
		while (1)
		{
			int x = rand() % n;
			int i = 0;
			int j = 0;
			for (i = 0; i < n; i++)
			{
				if (p->board[x][i] == 0)
				{
					p->board[x][i] = 1;
					return x;
				}
			}
		}
	}
	return -1;
}

int checkifempty(struct player* p,int n)
{
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (p->board[i][j] != 0)
			{
				return 0;
			}
		}
	}
	return 1;
}