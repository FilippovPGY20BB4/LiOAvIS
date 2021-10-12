#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define N 5
void tosgest(int** mas);
void stagivanie(int** mas);
void main()
{
	setlocale(LC_ALL, "rus");
	int** matrix1;
	int** matrix2;
	int i = 0;
	int j = 0;
	int ch = 0;
	matrix1 = (int**)malloc(N * sizeof(int));
	matrix2 = (int**)malloc(N * sizeof(int));
	for (i = 0; i < N; i++)
	{
		matrix1[i] = (int*)malloc(N * sizeof(int));
		matrix2[i] = (int*)malloc(N * sizeof(int));
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
			{
				matrix1[i][j] = 0;
				continue;
			}

			if (rand() % 31 < 10) matrix1[i][j] = 1;
			else matrix1[i][j] = 0;
			matrix1[j][i] = matrix1[i][j];
		}

	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf_s("%d", matrix1[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == j)
			{
				matrix2[i][j] = 0;
				continue;
			}

			if (rand() % 31 < 10) matrix2[i][j] = 1;
			else matrix2[i][j] = 0;
			matrix2[j][i] = matrix2[i][j];
		}

	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf_s("%d", matrix2[i][j]);
		}
		printf_s("\n");
	}
	//tosgest(matrix1);
	stagivanie(matrix1);
	;
	getchar();
	getchar();
}

void tosgest(int** mas)
{
	int a, b;
	int matr1[N][N] = { 0 };
	int matr2[N - 1][N - 1] = { 0 };
	int m[N - 1];
	int j = 0;
	int i = 0;
	int r = 0;
	a = b = 0;
	label:
	printf_s("¬ведите вершину 1: ");
	scanf_s("%d", &a);
	printf_s("¬ведите вершину 2: ");
	scanf_s("%d", &b);
	if (a > b)
	{
		i = b;
		b = a;
		a = i;
	}
	if(a==b) 
	{
		printf_s("ќшибка\n");
		goto label;
	}
		
	for(i=0;i<N;i++)
		for (j = 0; j < N; j++)
		{
			matr1[i][j] = mas[i][j];
		}
	for (j = 0; j < N; j++)
	{
		if ((mas[j][a] == 0) && (mas[j][b] == 0)) matr1[j][a] = 0;
		else matr1[j][a] = 1;

		if ((mas[a][j] == 0) && (mas[b][j] == 0)) matr1[a][j] = 0;
		else matr1[a][j] = 1;
	}
	for (i = 0; i < (N - 1); i++)
	{
		if (i == b)
		{
			r = i + 1;
		}
		m[i] = matr1[a][r];
		r = r++;
	}//в массив записываетс€ строка, еЄ нужно вставить в результирующую матрицу.
	r = 0;//счетчик строки с результатом сложени€
	int q = 0;
	int g = 0;//—четчики дл€ массива mas[]
	for (i = 0; i < (N - 1); i++)
	{
		j = 0;
		if (i == a)
		{
			j = 0;
			while (j != (N-1))
			{
				matr2[i][j] = m[j];
				j++;
			}
			i++;
			j = 0;
			q = i+1;
			r++;
		}
	        g = 0;
			while (j < a)
			{
				matr2[i][j] = matr1[q][g];
				j++; g++;
			}
			if (j == a) {
				matr2[i][j] = m[r];
				r++; j++; g = g + 2;
			}
			while (j < (N - 1))
			{
				matr2[i][j] = matr1[q][g];
				j++; g++;
			}
			q = q++;
		
	}

}

void stagivanie(int** mas)
{
	int a, b;
	int matr1[N][N] = { 0 };
	int matr2[N - 1][N - 1] = { 0 };
	int m[N - 1];
	int j = 0;
	int i = 0;
	int r = 0;
	a = b = 0;
label:
	printf_s("¬ведите вершину 1: ");
	scanf_s("%d", &a);
	printf_s("¬ведите вершину 2: ");
	scanf_s("%d", &b);
	if (a > b)
	{
		i = b;
		b = a;
		a = i;
	}
	if (a == b)
	{
		printf_s("ќшибка\n");
		goto label;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			matr1[i][j] = mas[i][j];
		}
	//”даление ребра:
	matr1[a][b] = 0;
	matr1[b][a] = 0;
	for (j = 0; j < N; j++)
	{
		if ((mas[j][a] == 0) && (mas[j][b] == 0)) matr1[j][a] = 0;
		else matr1[j][a] = 1;

		if ((mas[a][j] == 0) && (mas[b][j] == 0)) matr1[a][j] = 0;
		else matr1[a][j] = 1;
	}
	for (i = 0; i < (N - 1); i++)
	{
		if (i == b)
		{
			r = i + 1;
		}
		m[i] = matr1[a][r];
		r = r++;
	}//в массив записываетс€ строка, еЄ нужно вставить в результирующую матрицу.
	r = 0;//счетчик строки с результатом сложени€
	int q = 0;
	int g = 0;//—четчики дл€ массива mas[]
	for (i = 0; i < (N - 1); i++)
	{
		j = 0;
		if (i == a)
		{
			j = 0;
			while (j != (N - 1))
			{
				matr2[i][j] = m[j];
				j++;
			}
			i++;
			j = 0;
			q = i + 1;
			r++;
		}
		g = 0;
		while (j < a)
		{
			matr2[i][j] = matr1[q][g];
			j++; g++;
		}
		if (j == a) {
			matr2[i][j] = m[r];
			r++; j++; g = g + 2;
		}
		while (j < (N - 1))
		{
			matr2[i][j] = matr1[q][g];
			j++; g++;
		}
		q = q++;

	}
}
void logical_plus(int** mas1, int** mas2)
{
	int result_mas[N][N] = { 0 };
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			result_mas[i][j] = mas1[i][j] | mas2[i][j];
		}
}
void logical_ymnog(int** mas1, int** mas2)
{
	int result_mas[N][N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			result_mas[i][j] = mas1[i][j] & mas2[i][j];
		}
}
void logical_xor(int** mas1, int** mas2)
{
	int result_mas[N][N] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			result_mas[i][j] = mas1[i][j] ^ mas2[i][j];
		}
}