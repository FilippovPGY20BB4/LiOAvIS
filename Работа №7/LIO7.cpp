#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>
#include<string.h>
using namespace std;
#include<queue>
void BFS(int** matrix, int size, int start);
void BFS_orient(int** matrix, int size, int start);
void noweight_noorient(int** matrix, int size);
void noweight_orient(int** matrix, int size);
void weight_noorient(int** matrix, int size);
void weight_orient(int** matrix, int size);
void BFS_noweight_noorient(int** matrix, int start, int rasm);
void BFS_noweight_orient(int** matrix, int start, int rasm);
int main(int argc,char* argv[])
{
	int** matrix = NULL;
	int size = 0;
	int i = 0, j = 0;
	int type_graf = 0;
	int type_graf_w = 0;
	int start = 0;
	setlocale(LC_ALL, "rus");
	//
	if (strcmp(argv[1], "orient") == 0) type_graf = 1;
	if (strcmp(argv[1], "noorient") == 0) type_graf = 2;
	if (strcmp(argv[2], "weight") == 0) type_graf_w = 1;
	if (strcmp(argv[2], "noweight") == 0) type_graf_w = 2;
	if (type_graf == 0 || type_graf_w == 0)
	{
		printf("Введен неверны аргумент");
		return 0;
	}
	//
	printf_s("Ведите число вершин: ");
	scanf("%d", &size);
	matrix = (int**)malloc(size * sizeof(int));
	printf("\n");
	for (i = 0; i < size; i++) matrix[i] = (int*)malloc(size * sizeof(int));
	//
	switch (type_graf)
	{
	case 1:
	{
		switch (type_graf_w)
		{
		case 1:
		{
			weight_orient(matrix, size);
			printf("Введите стартовую вершину: ");
			
			scanf("%d", &start);
			BFS_orient(matrix, size, start);
		}
		break;
		case 2:
		{
			noweight_orient(matrix, size);
			printf("Введите стартовую вершину: ");
			scanf("%d", &start);
			BFS_noweight_orient(matrix, start, size);
		}
		
		}
	}
	break;
	case 2:
	{
		switch (type_graf_w)
		{
		case 1:
		{
			weight_noorient(matrix, size);
			printf("Введите стартовую вершину: ");
			scanf("%d", &start);
			BFS(matrix, size, start);
		}
		break;
		case 2:
		{
			noweight_noorient(matrix, size);
			printf("Введите стартовую вершину: ");
			scanf("%d", &start);
			BFS_noweight_noorient(matrix, start, size);
		}
		}
	}
	}
	//
	for (i = 0; i < size; i++) free(matrix[i]);
	free(matrix);
}

void BFS(int** matrix, int size, int start)
{
	queue <int> Q;
	int* distanse = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) distanse[i] = 1000;
	distanse[start] = 0;
	int visited;
	Q.push(start);
	while (!Q.empty())
	{
		visited = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++)
		{
			if (matrix[visited][i] > 0 && distanse[i] > distanse[visited] + matrix[visited][i])
			{
				Q.push(i);
				distanse[i] = distanse[visited] + matrix[visited][i];
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (distanse[i] == 1000) printf("Вершина %d не посещена", i);
		else
     printf("Вершина %d, расстояние %d\n", i, distanse[i]);
	}
	free(distanse);
}

void BFS_orient(int** matrix, int size, int start)
{
	queue <int> Q;
	int* distanse = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) distanse[i] = 1000;
	distanse[start] = 0;
	int visited;
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
	for (int i = 0; i < size; i++)
	{
		if (distanse[i] == 1000) printf("Вершина %d не посещена", i);
		else
			printf("Вершина %d, расстояние %d\n", i, distanse[i]);
	}
	free(distanse);
}

void noweight_noorient(int** matrix, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}
			if (rand() % 21 > 9) matrix[i][j] = 1;
			else matrix[i][j] = 0;
			matrix[j][i]=matrix[i][j];
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d| ", i);
		for (int j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void noweight_orient(int** matrix, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}
			if (rand() % 21 > 9) matrix[i][j] = 1;
			else matrix[i][j] = 0;
			
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d| ", i);
		for (int j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void weight_noorient(int** matrix, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}
			if (rand() % 21 > 9) matrix[i][j] = rand() % 10;
			else matrix[i][j] = 0;
			matrix[j][i] = matrix[i][j];

		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d| ", i);
		for (int j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void weight_orient(int** matrix, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}
			if (rand() % 21 > 9) matrix[i][j] = rand() % 10;
			else matrix[i][j] = 0;

		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d| ", i);
		for (int j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void BFS_noweight_noorient(int** matrix, int start, int rasm)
{
	int visited = start;
	queue <int> Q;
	int i = 0;
	int* distanse = (int*)malloc(rasm * sizeof(int));
	for (i = 0; i < rasm; i++) distanse[i] = -1;
	//
	distanse[visited] = 0;
	Q.push(visited);
	while (!Q.empty())
	{
		visited = Q.front();
		Q.pop();
		printf_s("Вершина: %d, расстояние: %d\n", visited, distanse[visited]);
		for (i = 0; i < rasm; i++)
		{
			if (matrix[visited][i] == 1 && distanse[i] == -1)
			{
				Q.push(i);
				distanse[i] = distanse[visited] + 1;
			}

		}
	}
	for (i = 0; i < rasm; i++)
	{
		if (distanse[i] == -1)
			printf_s("\nВершина %d не посещена, т.к. изолирована.\n", i);
	}
	free(distanse);
}
void BFS_noweight_orient(int** matrix, int start, int rasm)
{
	int visited = start;
	queue <int> Q;
	int i = 0;
	int* distanse = (int*)malloc(rasm * sizeof(int));
	for (i = 0; i < rasm; i++) distanse[i] = -1;
	//
	distanse[visited] = 0;
	Q.push(visited);
	while (!Q.empty())
	{
		visited = Q.front();
		Q.pop();
		printf_s("Вершина: %d, расстояние: %d\n", visited, distanse[visited]);
		for (i = 0; i < rasm; i++)
		{
			if (matrix[i][visited] == 1 && distanse[i] == -1)
			{
				Q.push(i);
				distanse[i] = distanse[visited] + 1;
			}

		}
	}
	for (i = 0; i < rasm; i++)
	{
		if (distanse[i] == -1)
			printf_s("\nВершина %d не посещена, т.к. изолирована.\n", i);
	}
	free(distanse);
}
