#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
void DFS(int** matrix, int st);
int* visited = NULL;
int a = 0;
void main()
{
	setlocale(LC_ALL, "Rus");
	int** matrix = NULL;
	int i = 0;
	int j = 0;
	int sum = 0;
	printf_s("Введите количество вершин: ");
	scanf_s("%d", &a);
	srand(time(NULL));
	matrix = (int**)malloc(a * sizeof(int));
	visited = (int*)malloc(a * sizeof(int));
	for (i = 0; i < a; i++) visited[i] = 0;
	for (i = 0; i < a; i++)
	{
		matrix[i] = (int*)malloc(a * sizeof(int));
	}
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			if (rand() % 21 > 5) matrix[i][j] = 1;
			else matrix[i][j] = 0;
			matrix[j][i] = matrix[i][j];
		}

	}

	printf_s("Матрица:\n");
	for (i = 0; i < a; i++)
	{
		printf_s("%d|", i);
		for (j = 0; j < a; j++)
		{
			printf_s("%d ", matrix[i][j]);
		}
		printf_s("\n");
	}
	printf_s("Введите стартовый узел:");
	int start = 0;
	scanf_s("%d", &start);
	DFS(matrix, start);
}
void DFS(int** matrix, int st)
{
	int i = 0;
	visited[st] = 1;
	printf_s("%d", st);
	for (i = 0; i < a; i++)
	{
		if ((matrix[st][i] == 1) && (visited[i] == 0)) DFS(matrix, i);
	}
}