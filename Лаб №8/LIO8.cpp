#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
using namespace std;
#include<queue>
int BFC_R(int** matrix, int size, int start);
int* stepen_versh(int** matrix, int size);
void main()
{
	int** matrix = NULL;
	int* mas = NULL;
	int size = 0;
	int i = 0, j = 0;
	setlocale(LC_ALL, "rus");
	printf("Введите количество вершин: ");
	scanf("%d", &size);
	matrix = (int**)malloc(size * sizeof(int));
	for (i = 0; i < size; i++) matrix[i] = (int*)malloc(size * sizeof(int));
	mas = (int*)malloc(size * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			if (rand() % 21 < 8) matrix[i][j] = 0;
			else matrix[i][j] = rand()%10;
			matrix[j][i] = matrix[i][j];
		}

	}
	printf("Матрица:\n");
	for (i = 0; i < size; i++)
	{
		printf("%d|", i);
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < size; i++) mas[i] = BFC_R(matrix, size, i);
	int max = 0, min = 1001;
	for (i = 0; i < size; i++)
	{
		if (mas[i] > max) max = mas[i];
	}
	for (i = 0; i < size; i++)
	{
		if (mas[i]<min) min = mas[i];
	}

	
	printf("Радиус = %d; диаметр = %d\n", min, max);
	//Переферийные
	printf("Переферийные вершины:\n");
	for (i = 0; i < size; i++)
	{
		if (mas[i] == max) printf("%d ",i);
	}
	//Центральные
	printf("\nЦентральные вершины:\n");
	for (i = 0; i < size; i++)
	{
		if (mas[i] == min) printf("%d ", i);
	}
	printf("\n");
	int* stepen = stepen_versh(matrix, size);
	printf("Изолированные вершины:\n");
	for (i = 0; i < size; i++)
	{
		if (stepen[i] == 0) printf("%d ", i);
	}
	printf("\nКонцевые вершины:\n");
	for (i = 0; i < size; i++)
	{
		if (stepen[i] == 1) printf("%d ", i);
	}
	printf("\nДоминирующие вершины:\n");
	for (i = 0; i < size; i++)
	{
		if (stepen[i] == (size-1)) printf("%d ", i);
	}
	for (i = 0; i < size; i++) free(matrix[i]);
	free(mas);
	free(matrix);
}


int BFC_R(int** matrix, int size, int start)
{
	
		queue <int> Q;
		int* distanse = (int*)malloc(size * sizeof(int));
		for (int i = 0; i < size; i++) distanse[i] = 1000;
		distanse[start] = 0;
		int visited;
		int max=0;
		int i = 0;
		Q.push(start);
		while (!Q.empty())
		{
			visited = Q.front();
			Q.pop();
			for (int i = 0; i < size; i++)
			{
				if (matrix[i][visited] > 0 && distanse[i] > distanse[visited] + matrix[i][visited])
				{
					Q.push(i);
					distanse[i] = distanse[visited] + matrix[i][visited];
				}
			}
		}
		for (i = 0; i < size; i++)
		{
			if (distanse[i] > max) max = distanse[i];
		}
		free(distanse);
		return max;
	
}

int* stepen_versh(int** matrix, int size)
{
	int* D = (int*)malloc(size * sizeof(int));
	int i = 0, j = 0;
	for (i = 0; i < size; i++) D[i] = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (matrix[i][j] != 0) D[i] = D[i] + 1;
		}
	}
	return D;
}