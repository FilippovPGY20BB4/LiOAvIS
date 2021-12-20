#define _CRT_SECURE_NO_WARNINGS
#define font_g SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN);
#define font_w SetConsoleTextAttribute(hstdout, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
#define font_r SetConsoleTextAttribute(hstdout,FOREGROUND_RED);
#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
int comp(const int*, const int*);
int* create_p(int** matrix, int rasm);
int colorize(int** matrix, int* sorted_mas, int rasm);
void save_matrix(int** matrix, int hrome, int size);
void read_file();
int** read_file_data(int size);
int get_size_file();
HANDLE hstdout;
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
	char* str_matr;
	char buf[2];
	char save;
	wchar_t name_console[] = L"Калькулятор хроматических чисел";
	SetConsoleTitle(name_console);
	Sleep(40);
	HWND console = FindWindow(NULL, name_console);
	MoveWindow(console, 400, 250, 1000, 500, TRUE);
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 40;
	position.Y = 10;
	//system("color 02");
	SetConsoleCursorPosition(hstdout, position);
	SetConsoleTextAttribute(hstdout, 23);
	printf("Курсовой проект по курсу ЛиОАвИЗ");
	position.Y = 11;
	position.X = 37;
	SetConsoleCursorPosition(hstdout, position);
	printf("Выполнил студент гр.20ВВ4 Филиппов Олег");
	Sleep(6000);
	SetConsoleTextAttribute(hstdout, 0|15);
	//system("color 07");
	system("cls");
	while (1)
	{
		printf_s("Случайный граф: r; Ручной ввод: h, Вывести сохраненные данные: f, Считать матрицу из файла data:x\n");
		scanf(" %c", &type, sizeof(char));

		switch (type)
		{
		case 'r':
		{
			font_r
			printf_s("Введите количество вершин: ");
			scanf("%d", &a);
			srand(time(NULL));
			matrix = (int**)malloc(a * sizeof(int));
			if (matrix == NULL)
			{
				printf_s("Ошибка");
			}
			font_w
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
		font_g
			printf("Созданная матрица:\n");
		font_w
			for (i = 0; i < a; i++)
			{
				printf("%d|", i);
				for (j = 0; j < a; j++)
				{
					printf("%d ", matrix[i][j]);
				}
				printf("\n");
			}
			sorted_mas = create_p(matrix, a);//По данному указателю находится отсортированный массив вершин
			int color = colorize(matrix, sorted_mas, a);
			font_g
			printf("\nХроматическое число: %d", color);
			font_w
			printf("\nВы хотите сохранить граф? (y/n) ");
			getchar();
			scanf(" %c", &save);
			if (save == 'y') save_matrix(matrix, color, a);
			if (save == 'n') system("cls");

			for (i = 0; i < a; i++)
			{
				free(matrix[i]);
			}
			free(matrix);
		}
		break;
		case 'h':
		{
			font_r
			printf("Необходимо ввести неориентированный невзвешенный граф без петель.\n");
			printf("Введите число вершин: ");
			scanf("%d", &a);
			matrix = (int**)malloc(a * sizeof(int));
			if (matrix == NULL)
			{
				printf("Ошибка");
			}
			font_w
			for (i = 0; i < a; i++)
			{
				matrix[i] = (int*)malloc(a * sizeof(int));
			}
			str_matr = (char*)malloc(a * sizeof(char) + 1);
			printf("Вводите строки матрицы без пробелов, после каждой строки нажимайте ENTER\n");
			for (i = 0; i < a; i++)
			{
				scanf("%s", str_matr);
				for (j = 0; j < a; j++)
				{
					switch (str_matr[j])
					{
					case '0': matrix[i][j] = 0;
						break;
					case '1':matrix[i][j] = 1;

					}
				}
			}
			//
			font_g
			printf("\nВведенная матрица:\n");
			font_w
			for (i = 0; i < a; i++)
			{
				printf("%d|", i);
				for (j = 0; j < a; j++)
				{
					printf("%d ", matrix[i][j]);
				}
				printf("\n");
			}
			sorted_mas = create_p(matrix, a);//По данному указателю находится отсортированный массив вершин
			int color = colorize(matrix, sorted_mas, a);
			font_g
			printf_s("\nХроматическое число: %d", color);
			font_w
			printf("\nВы хотите сохранить граф? (y/n) ");
			getchar();
			scanf(" %c", &save);
			if (save == 'y') save_matrix(matrix, color, a);
			if (save == 'n') system("cls");

			for (i = 0; i < a; i++)
			{
				free(matrix[i]);
			}
			free(matrix);
		}
		break;
		case 'f':
		{
			char end = NULL;
			system("cls");
			read_file();
			font_r
			printf("Для закрытия нажмите E: ");
			font_w
			scanf(" %c", &end);
			if (end != NULL) system("cls");
		}
		break;
		case 'x':
		{
			int size = get_size_file();
			int** matrix_d = read_file_data(size);
			sorted_mas = create_p(matrix_d, size);//По данному указателю находится отсортированный массив вершин
			int color = colorize(matrix_d, sorted_mas, size);
			font_g
			printf("\nХроматическое число: %d", color);
			font_w
			printf("\nВы хотите сохранить граф? (y/n) ");
			getchar();
			scanf(" %c", &save);
			if (save == 'y') save_matrix(matrix_d, color, size);
			if (save == 'n') system("cls");

			for (i = 0; i < a; i++)
			{
				free(matrix_d[i]);
			}
			free(matrix_d);
		}
		}

		printf("Завершить работу? y/n ");
		getchar();
		scanf(" %c", &save);
		if (save == 'y')
		{
			break;
			system("cls");
		}
		else
		{
			system("cls");
		}

	}


}

int colorize(int** matrix, int* sorted_mas, int rasm)
{
	int color = 1;
	int no_colorize = rasm;
	int i = 0, j = 0, k = 0;
	int* color_mas = NULL;
	color_mas = (int*)malloc(rasm * sizeof(int));
	if (color_mas == NULL) printf_s("error");
	for (i=0; i < rasm; i++) color_mas[i] = 0;
	i = 0;
	color_mas[sorted_mas[i]] = color;
	no_colorize = --no_colorize;
	while (no_colorize != 0)
	{
		for (j = 0; j < rasm; j++)
		{
			if ((matrix[sorted_mas[i]][j] == 0) && (color_mas[j] == 0))
			{
				if (sorted_mas[i] == j) continue;
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
		int num=0;
		int por=0;
	};
	sp hold;
	int i = 0;
	int j = 0;
	int sum = 0;
	sp* mas_struct = NULL;
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
	for (i = rasm - 1; i > 0; i--)
	{
		switched = 0;
		for (j = 0; j < i; j++)
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

void save_matrix(int** matrix, int hrome, int size)
{
	FILE* file = NULL;
	file = fopen("data.txt", "a");
	fprintf(file, "\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fprintf(file, "%d ", matrix[i][j]);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "Хроматическое число: %d\n", hrome);
	fclose(file);
}

void read_file()
{
	FILE* file = NULL;
	file = fopen("data.txt", "r");
	char str[100];
	font_g
		printf("Сохраненные данные:");
	font_w
	while (fgets(str, 100, file) != NULL)
		printf("%s", str);
	fclose(file);
}

int** read_file_data(int size)
{
	FILE* file = NULL;
	file = fopen("matrix.txt", "r+");
	char c;
	int** matrix = NULL;
	int i = 0, j = 0;
	matrix = (int**)malloc(size * sizeof(int));
	if (matrix == NULL)
	{
		printf_s("Ошибка");
	}
	for (i = 0; i < size; i++)
	{
		matrix[i] = (int*)malloc(size * sizeof(int));
	}
	//fseek(file, 0, SEEK_SET);
	i = 0;
	do
	{
		c = fgetc(file);
		switch (c)
		{
		case '1':
		{
			matrix[i][j] = 1;
			j = ++j;
		}
		break;
		case '0':
		{
			matrix[i][j] = 0;
			j = ++j;
		}
		break;
		case'\n':
		{
			i = ++i;
			j = 0;
		}
		}


	} while (c != EOF);
	fclose(file);
	font_g
	printf("Матрица, считанная из файла:\n");
	font_w
	for (i = 0; i < size; i++)
	{
		printf("%d |", i);
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return matrix;
}

int get_size_file()
{
	FILE* file = fopen("matrix.txt", "r+");
	int size = 0;
	char c;
	do
	{
		c = fgetc(file);
		if (c == '1' || c == '0') size = ++size;
	} while (c != '\n');
	fclose(file);
	return size;
}
