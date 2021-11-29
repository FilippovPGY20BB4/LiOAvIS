#include<stdio.h>
using namespace std;
#include<queue>
#include<locale.h>
#include<time.h>
#include<Windows.h>
void BFC_with_distanse(int** matrix, int start, int rasm);
void convert_matrix(int** mas1, int rasm);
void BFS_spisok(int start, int rasm);
void delete_spisok(int rasm);
void DFS(int** matrix, int start, int rasm);

void DFS_spisok(int start);
struct sp
{
	int num;
	struct sp* next;
};
struct sp* elem = NULL;
struct sp** MAS;
int* distanse_DFS = NULL;
int visited_DFS = -1;
void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP()
	int** matrix = NULL;
	int i = 0;
	int j = 0;
	int sum = 0;
	double diff_time = 0;
	int a = 0;
	//
	double time_bfs_matr = 0, time_bfs_sp = 0, time_dfs_matr = 0, time_dfs_sp = 0;
	while (1)
	{
		printf_s("Введите количество вершин, -1 для выхода ");
		scanf_s("%d", &a);
		if (a == -1) break;
		srand(time(NULL));
		matrix = (int**)malloc(a * sizeof(int));
		distanse_DFS = (int*)malloc(sizeof(int) * a);
		for (i = 0; i < a; i++) distanse_DFS[i] = -1;
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

				if (rand() % 21 > 10) matrix[i][j] = 1;
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
		//
		printf_s("Введите начальную вершину:");
		int start = 0;
		scanf_s("%d", &start);
		//

		convert_matrix(matrix, a);
		for (i = 0; i < a; i++)
		{
			elem = MAS[i];
			while (elem != NULL)
			{
				printf_s("%d->", elem->num);
				elem = elem->next;
			}
			printf_s("\n");
		}
		diff_time = clock();
		BFC_with_distanse(matrix, start, a);
		time_bfs_matr = (clock() - diff_time) / 1000;
		printf_s("Время обхода матрицы в ширину: %lf\n\n", time_bfs_matr);
		//
		diff_time = clock();
		BFS_spisok(start, a);
		time_bfs_sp = (clock() - diff_time) / 1000;
		printf_s("Время обхода списка в ширину: %lf\n\n", time_bfs_sp);
		//
		diff_time = clock();
		DFS(matrix, start, a);
		time_dfs_matr = (clock() - diff_time) / 1000;
		printf_s("Время обхода матрицы в глубину: %lf\n\n", time_dfs_matr);
		//

		for (i = 0; i < a; i++) distanse_DFS[i] = -1;
		visited_DFS = -1;
		diff_time = clock();
		DFS_spisok(start);
		time_dfs_sp = (clock() - diff_time) / 1000;
		printf_s("время обхода списка в глубину: %lf\n\n", time_dfs_sp);
		delete_spisok(a);
		free(distanse_DFS);
		for (i = 0; i < a; i++)
		{
			free(matrix[i]);
		}
	}
}


void BFC_with_distanse(int** matrix, int start, int rasm)
{
	int visited = start;
	queue <int> Q;
	int* distanse = (int*)malloc(rasm * sizeof(int));
	int i = 0;
	for (i = 0; i < rasm; i++) distanse[i] = -1;
	//
	distanse[visited] = 0;
	Q.push(visited);
	while (!Q.empty())
	{
		visited = Q.front();
		Q.pop();
		printf_s("Вершина: %d, : %d\n", visited, distanse[visited]);
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
			printf_s("\nВершина %d не пройдена, т.к. изолирована.\n", i);
	}
	free(distanse);
}

void convert_matrix(int** mas1, int rasm)
{

	int i = 0;
	int j = 0;
	struct sp* new_elem = NULL;
	MAS = (sp**)malloc(rasm * sizeof(sp));
	for (i = 0; i < rasm; i++)
	{
		elem = (sp*)malloc(sizeof(sp));
		elem->num = i;
		elem->next = NULL;
		MAS[i] = elem;
		for (j = 0; j < rasm; j++)
		{
			if (mas1[i][j] == 1)
			{
				new_elem = (sp*)malloc(sizeof(sp));
				new_elem->num = j;
				new_elem->next = NULL;
				elem->next = new_elem;
				elem = new_elem;
			}
		}
	}
}

void BFS_spisok(int start, int rasm)
{
	queue<int> Q;
	int visited = start;
	int* distanse = (int*)malloc(rasm * sizeof(int));
	int i = 0;
	for (i = 0; i < rasm; i++) distanse[i] = -1;
	elem = MAS[start];
	distanse[elem->num] = 0;
	Q.push(elem->num);
	while (!Q.empty())
	{
		visited = Q.front();
		elem = MAS[visited];
		Q.pop();
		printf_s("Вершина: %d, расстояние: %d\n", visited, distanse[visited]);
		while (elem != NULL)
		{
			if (distanse[elem->num] == -1)
			{
				Q.push(elem->num);
				distanse[elem->num] = distanse[visited] + 1;
			}

			elem = elem->next;
		}
	}
	free(distanse);
}

void delete_spisok(int rasm)
{
	int i = 0;
	sp* del_elem = NULL;
	for (i; i < rasm; i++)
	{
		del_elem = MAS[i];
		while (del_elem != NULL)
		{
			elem = del_elem->next;
			free(del_elem);
			del_elem = elem;
		}
	}
}

void DFS(int** matrix, int start, int rasm)
{
	int r = rasm;
	int i = 0;
	visited_DFS = visited_DFS++;
	distanse_DFS[start] = visited_DFS;
	printf_s("Вершина:%d, расстояние: %d\n", start, distanse_DFS[start]);
	for (i = 0; i < rasm; i++)
	{
		if ((matrix[start][i] == 1) && (distanse_DFS[i] == -1)) DFS(matrix, i, r);
	}
	visited_DFS == --visited_DFS;
}


void DFS_spisok(int start)
{
	int flag = 0;
	int i = 0;
	struct sp* node = MAS[start];
	visited_DFS = visited_DFS++;
	distanse_DFS[start] = visited_DFS;
	printf_s("Вершина:%d, расстояние: %d\n", start, distanse_DFS[start]);
	do
	{
		if (distanse_DFS[node->num] == -1)
		{
			DFS_spisok(node->num);
		}
		else
			node = node->next;
	} while (node != NULL);
	visited_DFS = --visited_DFS;
}