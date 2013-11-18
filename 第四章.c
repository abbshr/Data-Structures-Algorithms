//26
void Floyd(D, G, n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			D[i][j] = G[i][j];
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j])
					D[i][j] = D[i][k] + D[k][i];
}

int main() 
{
	int G = {
		{0   , 20  , 15  , NULL, NULL, NULL},
		{2   , 0   , NULL, NULL, 10  , 30  },
		{NULL, 4   , 0   , NULL, NULL, 10  },
		{NULL, NULL, NULL, 0   , NULL, NULL},
		{NULL, NULL, NULL, 15  , 0   , NULL},
		{NULL, NULL, NULL, 4   , 10  , 0   },
	};

	int** D = (int** )malloc(sizeof(int* ) * 6);
	*D = (int* )malloc(sizeof(int) * 6);
	*(D + 1) = (int* )malloc(sizeof(int) * 6);
	*(D + 2) = (int* )malloc(sizeof(int) * 6);
	*(D + 3) = (int* )malloc(sizeof(int) * 6);
	*(D + 4) = (int* )malloc(sizeof(int) * 6);
	*(D + 5) = (int* )malloc(sizeof(int) * 6);

	Floyd(D, G, n);

	int i, j, k;
	int* E = (int* )malloc(sizeof(int) * 6);
	int* C;
	for (j = 0; j < 6; j++) 
	{
		k = 1;
		for (i = 0; i < 6; i++)
		{
			if (i = j) continue;
			if (D[i][j] >= D[k][j]) k = i;
		}
		E[j] = D[k][j];
	}

	k = 1;
	for (i = 0; i < 6; i++)
		if (E[i] <= E[k]) k = i;
	C = E + k;
	printf("%d\n", *C);

	return 0;
}

//30