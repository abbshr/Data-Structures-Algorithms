#include <stdio.h>
#include <stdlib.h>

void Dijkstra(int** G, int* D, int* P, int row)
{
	int i, w, j;
	int* S = (int* )malloc(sizeof(int) * row);
	for (i = 0; i < row; i++) 
	{
		*(S + i) = 0;
		*(D + i) = *(*G + i);
		*(P + i) = 0;
	}
	*S = 1;
	for (i = 1; i < row; i++)
	{
		w = 1;
		for (j = 1; j < row; j++)
		{
			if (*(S + j))
				continue;
			if (*(D + j) <= *(D + w))
				w = j;
		}
		*(S + w)= 1;
		for (j = 1; j < row; j++)
			if (!*(S + j))
				if (*(D + j) > (*(D + w) + *(*(G + w) + j)))
				{
					*(D + j) = *(D + w) + *(*(G + w) + j);
					*(P + j) = w;
				}
	}
}

int main()
{
	int row = 0;
	printf("有向图的顶点数：\n");
	scanf("%d", &row);
	int** G = (int** )malloc(sizeof(int*) * row);
	int i = 0, j = 0;
	while (i < row) 
	{
		*(G + i) = (int* )malloc(sizeof(int) * row);
		i++;
	}
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < row)
		{
			if (i == j)
			{
				*(*(G + i) + j) = 0;
				j++;
				continue;
			}
			printf("输入第%d行，第%d列的value:\n", i + 1, j + 1);
			scanf("%d", (*(G + i) + j));
			j++;
		}
		i++;
	}
	int* D = (int* )malloc(sizeof(int) * row);
	int* P = (int* )malloc(sizeof(int) * row);
	Dijkstra(G, D, P, row);
	for (i = 1; i < row; i++)
	{
		printf("到达第%d个点, 路径为：", i);
		j = i;
		printf("%d ", j);
		while (j) {
			j = P[j];
			printf("%d ", j);
		}
		printf(": %d\n", *(D + i));
	}
	return 0;
}