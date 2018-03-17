

int canmove(struct player* p, char c, int n)
{
	int f = -10;
	if (c == 'd'||c=='t')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = n - 1;
			int j = n - 2;
			while (j >= 0)
			{
				while (p->board[h][i] == 0 && i>j)
				{
					i--;
					if (i < 0)
						break;
				}
				while (p->board[h][j] == 0 || j == i)
				{
					j--;
					if (j < 0)
						break;
				}

				if (i < 0 || j < 0 || j>i)
					break;
				int c1 = find(p->board[h][i]);
				int c2 = find(p->board[h][j]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[h][i] == 1 && p->board[h][j] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					return 11;
					f = 10;
					p->board[h][i] = p->board[h][j] + p->board[h][i];
					if (p->max < p->board[h][i])
						p->max = p->board[h][i];
					p->board[h][j] = 0;
					i = j - 1;
					j = j - 2;
				}
				else
				{
					i--;
					j--;
				}
			}
			i = n - 1;
			j = n - 2;
			while (p->board[h][i] != 0)
			{
				i--;
				if (i < 0)
					break;
			}
			if (i < 0)
				continue;
			j = i - 1;
			while (j >= 0)
			{
				if (i < 1 || j < 0)
					break;
				if (p->board[h][j] != 0)
				{
					return 11;
					f = 10;
					int k = p->board[h][j];
					p->board[h][i] = k;
					p->board[h][j] = 0;
					i--;
				}
				j--;
			}
		}
	}
	if (c == 'a'||c=='t')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = 0;
			int j = 1;
			while (j <= n - 1)
			{
				while (p->board[h][i] == 0)
				{
					i++;
					if (i >n - 2)
						break;
				}
				while (p->board[h][j] == 0 || j == i)
				{
					j++;
					if (j >n - 1)
						break;
				}

				if (i >n - 2 || j>n - 1 || j <= i)
					break;
				int c1 = find(p->board[h][i]);
				int c2 = find(p->board[h][j]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[h][i] == 1 && p->board[h][j] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					return 11;
					f = 10;
					p->board[h][i] = p->board[h][j] + p->board[h][i];
					if (p->max < p->board[h][i])
						p->max = p->board[h][i];
					p->board[h][j] = 0;
					i = j + 1;
					j = j + 2;
				}
				else
				{
					i++;
					j++;
				}
			}
			i = 0;
			j = 1;
			while (p->board[h][i] != 0)
			{
				i++;
				if (i > n - 2)
					break;
			}
			if (i > n - 2)
				continue;
			j = i + 1;
			while (j <= n - 1)
			{
				if (i > n - 2 || j > n - 1)
					break;
				if (p->board[h][j] != 0)
				{
					return 11;
					f = 10;
					long long k = p->board[h][j];
					p->board[h][i] = k;
					p->board[h][j] = 0;
					i++;
				}
				j++;
			}
		}
	}
	if (c == 's'||c=='t')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = n - 1;
			int j = n - 2;
			while (j >= 0)
			{
				while (p->board[i][h] == 0 && i>j)
				{
					i--;
					if (i < 0)
						break;
				}
				while (p->board[j][h] == 0 || j == i)
				{
					j--;
					if (j < 0)
						break;
				}

				if (i < 0 || j < 0 || j>i)
					break;
				int c1 = find(p->board[i][h]);
				int c2 = find(p->board[j][h]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[i][h] == 1 && p->board[j][h] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					return 11;
					f = 10;
					p->board[i][h] = p->board[j][h] + p->board[i][h];
					if (p->max < p->board[i][h])
						p->max = p->board[i][h];
					p->board[j][h] = 0;
					i = j - 1;
					j = j - 2;
				}
				else
				{
					i--;
					j--;
				}
			}
			i = n - 1;
			j = n - 2;
			while (p->board[i][h] != 0)
			{
				i--;
				if (i < 0)
					break;
			}
			if (i < 0)
				continue;
			j = i - 1;
			while (j >= 0)
			{
				if (i < 1 || j < 0)
					break;
				if (p->board[j][h] != 0)
				{
					return 11;
					f = 10;
					int k = p->board[j][h];
					p->board[i][h] = k;
					p->board[j][h] = 0;
					i--;
				}
				j--;
			}
		}
	}
	if (c == 'w'||c=='t')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = 0;
			int j = 1;
			while (j <= n - 1)
			{
				while (p->board[i][h] == 0)
				{
					i++;
					if (i >n - 2)
						break;
				}
				while (p->board[j][h] == 0 || j == i)
				{
					j++;
					if (j >n - 1)
						break;
				}

				if (i >n - 2 || j>n - 1 || j <= i)
					break;
				int c1 = find(p->board[i][h]);
				int c2 = find(p->board[j][h]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[i][h] == 1 && p->board[j][h] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					return 11;
					f = 10;
					p->board[i][h] = p->board[j][h] + p->board[i][h];
					if (p->max < p->board[i][h])
						p->max = p->board[i][h];
					p->board[j][h] = 0;
					i = j + 1;
					j = j + 2;
				}
				else
				{
					i++;
					j++;
				}
			}
			i = 0;
			j = 1;
			while (p->board[i][h] != 0)
			{
				i++;
				if (i > n - 2)
					break;
			}
			if (i > n - 2)
				continue;
			j = i + 1;
			while (j <= n - 1)
			{
				if (i > n - 2 || j > n - 1)
					break;
				if (p->board[j][h] != 0)
				{
					return 11;
					f = 10;
					long long k = p->board[j][h];
					p->board[i][h] = k;
					p->board[j][h] = 0;
					i++;
				}
				j++;
			}
		}
	
	}
	else
	{
		p->endtime = time(NULL);
		return -1;
	}
	return -1;
}




int makemove(struct player* p, char c, int n)
{
	int f = -10;
	if (c == 'd')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = n - 1;
			int j = n - 2;
			while (j >= 0)
			{
				while (p->board[h][i] == 0 && i>j)
				{
					i--;
					if (i < 0)
						break;
				}
				while (p->board[h][j] == 0 || j == i)
				{
					j--;
					if (j < 0)
						break;
				}

				if (i < 0 || j < 0 || j>i)
					break;
				int c1 = find(p->board[h][i]);
				int c2 = find(p->board[h][j]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[h][i] == 1 && p->board[h][j] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					f = 10;
					p->board[h][i] = p->board[h][j] + p->board[h][i];
					if (p->max < p->board[h][i])
						p->max = p->board[h][i];
					p->board[h][j] = 0;
					i = j - 1;
					j = j - 2;
				}
				else
				{
					i--;
					j--;
				}
			}
			i = n - 1;
			j = n - 2;
			while (p->board[h][i] != 0)
			{
				i--;
				if (i < 0)
					break;
			}
			if (i < 0)
				continue;
			j = i - 1;
			while (j >= 0)
			{
				if (i < 1 || j < 0)
					break;
				if (p->board[h][j] != 0)
				{
					f = 10;
					int k = p->board[h][j];
					p->board[h][i] = k;
					p->board[h][j] = 0;
					i--;
				}
				j--;
			}
		}
		if (f == -10)
			return f;
		return 1;
	}
	else if (c == 'a')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = 0;
			int j = 1;
			while (j <= n - 1)
			{
				while (p->board[h][i] == 0)
				{
					i++;
					if (i >n - 2)
						break;
				}
				while (p->board[h][j] == 0 || j == i)
				{
					j++;
					if (j >n - 1)
						break;
				}

				if (i >n - 2 || j>n - 1 || j <= i)
					break;
				int c1 = find(p->board[h][i]);
				int c2 = find(p->board[h][j]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[h][i] == 1 && p->board[h][j] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					f = 10;
					p->board[h][i] = p->board[h][j] + p->board[h][i];
					if (p->max < p->board[h][i])
						p->max = p->board[h][i];
					p->board[h][j] = 0;
					i = j + 1;
					j = j + 2;
				}
				else
				{
					i++;
					j++;
				}
			}
			i = 0;
			j = 1;
			while (p->board[h][i] != 0)
			{
				i++;
				if (i > n - 2)
					break;
			}
			if (i > n - 2)
				continue;
			j = i + 1;
			while (j <= n - 1)
			{
				if (i > n - 2 || j > n - 1)
					break;
				if (p->board[h][j] != 0)
				{
					f = 10;
					long long k = p->board[h][j];
					p->board[h][i] = k;
					p->board[h][j] = 0;
					i++;
				}
				j++;
			}
		}
		if (f == -10)
			return f;
		return 1;
	}
	else if (c == 's')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = n - 1;
			int j = n - 2;
			while (j >= 0)
			{
				while (p->board[i][h] == 0 && i>j)
				{
					i--;
					if (i < 0)
						break;
				}
				while (p->board[j][h] == 0 || j == i)
				{
					j--;
					if (j < 0)
						break;
				}

				if (i < 0 || j < 0 || j>i)
					break;
				int c1 = find(p->board[i][h]);
				int c2 = find(p->board[j][h]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[i][h] == 1 && p->board[j][h] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					f = 10;
					p->board[i][h] = p->board[j][h] + p->board[i][h];
					if (p->max < p->board[i][h])
						p->max = p->board[i][h];
					p->board[j][h] = 0;
					i = j - 1;
					j = j - 2;
				}
				else
				{
					i--;
					j--;
				}
			}
			i = n - 1;
			j = n - 2;
			while (p->board[i][h] != 0)
			{
				i--;
				if (i < 0)
					break;
			}
			if (i < 0)
				continue;
			j = i - 1;
			while (j >= 0)
			{
				if (i < 1 || j < 0)
					break;
				if (p->board[j][h] != 0)
				{
					f = 10;
					int k = p->board[j][h];
					p->board[i][h] = k;
					p->board[j][h] = 0;
					i--;
				}
				j--;
			}
		}
		if (f == -10)
			return f;
		return 1;
	}
	else if (c == 'w')
	{
		int h = 0;
		for (h = 0; h < n; h++)
		{
			int i = 0;
			int j = 1;
			while (j <= n - 1)
			{
				while (p->board[i][h] == 0)
				{
					i++;
					if (i >n - 2)
						break;
				}
				while (p->board[j][h] == 0 || j == i)
				{
					j++;
					if (j >n - 1)
						break;
				}

				if (i >n - 2 || j>n - 1 || j <= i)
					break;
				int c1 = find(p->board[i][h]);
				int c2 = find(p->board[j][h]);
				if ((c2>0 && c1>0) && c2 - c1 == 1 || c1 - c2 == 1 || (p->board[i][h] == 1 && p->board[j][h] == 1) || (c1 == 1 && c2 == 3) || (c1 == 3 && c2 == 1))
				{
					f = 10;
					p->board[i][h] = p->board[j][h] + p->board[i][h];
					if (p->max < p->board[i][h])
						p->max = p->board[i][h];
					p->board[j][h] = 0;
					i = j + 1;
					j = j + 2;
				}
				else
				{
					i++;
					j++;
				}
			}
			i = 0;
			j = 1;
			while (p->board[i][h] != 0)
			{
				i++;
				if (i > n - 2)
					break;
			}
			if (i > n - 2)
				continue;
			j = i + 1;
			while (j <= n - 1)
			{
				if (i > n - 2 || j > n - 1)
					break;
				if (p->board[j][h] != 0)
				{
					f = 10;
					long long k = p->board[j][h];
					p->board[i][h] = k;
					p->board[j][h] = 0;
					i++;
				}
				j++;
			}
		}
		if (f == -10)
			return f;
		return 1;
	}
	else
	{
		p->endtime = time(NULL);
		return -1;
	}
	return 0;
}