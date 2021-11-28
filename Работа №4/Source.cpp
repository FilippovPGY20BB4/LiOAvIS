#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#include<stack>
void DFS(int** matrix, int st);
void convert_matrix(int** mas1);
void DFS_spisok(int st);
void DFC_no_recurs(int** mas1, int st);
int* visited = NULL;
int a = 0;
struct sp
{
	int num;
	struct sp* next;
};

struct sp *elem = NULL;
struct sp **MAS;
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
	convert_matrix(matrix);
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
	printf_s("Введите стартовый узел:");
	int start = 0;
	scanf_s("%d", &start);
	printf_s("Результат обхода матрицы:\n");
	DFS(matrix, start);
    for (i = 0; i < a; i++) visited[i] = 0;
	printf_s("\n");
	printf_s("Результат обхода списка:\n");
	DFS_spisok(start);	
	for (i = 0; i < a; i++) visited[i] = 0;
	printf_s("\nРезультат нерекурсивного обхода:\n");
	DFC_no_recurs(matrix, start);
	
}
void convert_matrix(int** mas1)
{
	
	int i = 0;
	int j = 0;
	struct sp* new_elem = NULL;
	MAS = (sp**)malloc(a * sizeof(sp));
	for (i = 0; i < a; i++)
	{
		elem = (sp*)malloc(sizeof(sp));
		elem->num = i;
		elem->next = NULL;
		MAS[i] = elem;
		for (j = 0; j < a; j++)
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
 void DFS_spisok(int st)
{
	int flag = 0;
	int i = 0;
	struct sp* node = MAS[st];
	visited[st] = 1;
	printf_s("%d", node->num);
		do
		{
			if (visited[node->num] == 0)
			{
				DFS_spisok(node->num);
			}
			else
			node = node->next;
			//if (flag == 1) elem = elem->next;
		} while (node != NULL);
		
}
void DFC_no_recurs(int** mas1, int st)
{
	int q = 0;
	int i = 0;
	stack <int> s;
	s.push(st);
	do
	{
		q = s.top();
		s.pop();
		printf_s("%d", q);
		visited[q] = 1;
		for (i = 0; i < a; i++)
		{
			if (mas1[q][i] == 1 && visited[i] == 0)
			{
				visited[i] = 1;
              s.push(i);
			}
				
		}
	} while (!s.empty());
}