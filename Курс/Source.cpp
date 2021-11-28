#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>

int comp(const int*, const int*);
int* create_p(int** matrix, int rasm);
int colorize(int** matrix, int* sorted_mas, int rasm);
void main()
{
	setlocale(LC_ALL, "Rus");
	int** matrix = NULL;
	int i = 0;
	int j = 0;
	int sum = 0;
	int a = 0;
	int* sorted_mas = NULL;
	char type;
	char *str_matr;
	char buf[2];
	printf_s("Случайный граф: r; Ручной ввод: h, Чтение из файла: f");
	scanf_s("%c", &type,sizeof(char));
	
	switch (type)
	{
	case 'r':
	{
		printf_s("Введите количество вершин: ");
		scanf("%d", &a);
		srand(time(NULL));
		matrix = (int**)malloc(a * sizeof(int));
		if (matrix == NULL)
		{
			printf_s("Ошибка");
		}
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
		sorted_mas = create_p(matrix, a);//По данному указателю находится отсортированный массив вершин
		printf_s("\n");
		for (i = 0; i < a; i++) printf_s("%d ", sorted_mas[i]);
		int color = colorize(matrix, sorted_mas, a);
		printf_s("\nХроматическое число: %d", color);
		for (i = 0; i < a; i++)
		{
			free(matrix[i]);
		}
		free(matrix);
	}
	break;
	case 'h':
	{
		printf_s("Введите число вершин: ");
		scanf("%d", &a);
		matrix = (int**)malloc(a * sizeof(int));
		if (matrix == NULL)
		{
			printf_s("Ошибка");
		}
		for (i = 0; i < a; i++)
		{
			matrix[i] = (int*)malloc(a * sizeof(int));
		}
		str_matr = (char*)malloc(a * sizeof(char)+1);
		printf_s("Вводите строки матрицы без пробелов, после каждой строки нажимайте ENTER\n");
		for (i = 0; i < a; i++)
		{
			
			scanf("%s", str_matr);
		//	printf_s("\n%s", str_matr);
			for (j = 0; j < a; j++)
			{
			
				//buf[0] = str_matr[j];
				switch (str_matr[j])
				{
				case '0': matrix[i][j] = 0;
					break;
				case '1':matrix[i][j] = 1;
					
				}
			}
		}
		//
		printf_s("\nМатрица:\n");
		for (i = 0; i < a; i++)
		{
			printf_s("%d|", i);
			for (j = 0; j < a; j++)
			{
				printf_s("%d ", matrix[i][j]);
			}
			printf_s("\n");
		}
		sorted_mas = create_p(matrix, a);//По данному указателю находится отсортированный массив вершин
		printf_s("\n");
		for (i = 0; i < a; i++) printf_s("%d ", sorted_mas[i]);
		int color = colorize(matrix, sorted_mas, a);
		printf_s("\nХроматическое число: %d", color);
		for (i = 0; i < a; i++)
		{
			free(matrix[i]);
		}
		free(matrix);
	}
	break;
	case 'f':
	{

	}
	break;
	}
	
	
	
}

int colorize(int** matrix,int* sorted_mas, int rasm)
{
	int color = 1;
	int no_colorize = rasm;
	int i = 0, j = 0, k = 0;
	int *color_mas=NULL;
	color_mas = (int*)malloc(rasm * sizeof(int));
	if (color_mas == NULL) printf_s("error");
	for (i; i < rasm; i++) color_mas[i] = 0;
	i = 0;
	color_mas[i] = color;
	no_colorize = --no_colorize;
	while (no_colorize!= 0)
	{
		for (j = 0; j < rasm; j++)
		{
			if ((matrix[sorted_mas[i]][j] == 0) && (color_mas[j] == 0))
			{
				color_mas[j] = color;
				no_colorize = --no_colorize;
			}
			
		}
		i = i++;
		if (color_mas[sorted_mas[i]] == 0)
		{
			color = ++color;
			color_mas[sorted_mas[i]] = color;
			no_colorize = --no_colorize;	
		}
	}
	free(color_mas);
	free(sorted_mas);
	return color;
}

int* create_p(int** matrix, int rasm)//Эта функция сортирует номера вершин по убыванию порядка вершины
{
	struct sp
	{
		int num = 0;
		int por = 0;
	};
	sp hold;
	int i = 0;
	int j = 0;
	int sum = 0;
	sp* mas_struct=NULL;
	mas_struct = (sp*)malloc(rasm * sizeof(sp));
	int* mas = 0;
	mas = (int*)malloc(rasm * sizeof(int));
	for (i = 0; i < rasm; i++)
	{
		for (j = 0; j < rasm; j++)
		{
			sum = sum + matrix[i][j];
		}
		mas_struct[i].num = i;
		mas_struct[i].por = sum;
		sum = 0;
	}
	//Сортировка:
	int switched = 0;
	for (i =rasm-1;i>0;i--)
	{
		switched = 0;
		for (j = 0; j <i; j++)
		{
			if (mas_struct[j].por < mas_struct[j + 1].por)
			{
				switched = 1;
				hold = mas_struct[j];
				mas_struct[j] = mas_struct[j + 1];
				mas_struct[j + 1] = hold;
				switched = 1;
			}
		}
		
	}
	for (i = 0; i < rasm; i++)
	{
		mas[i] = mas_struct[i].num;
	}
	return mas;
}
