#include<stdio.h>
#include<locale.h>
#include<time.h>
#include<stdlib.h>
#define N 5000
void shell(int* items, int count);
void qs(int* items, int left, int right);
int comp(const int* i, const int* j);
void main()
{
	double diff=0;
	setlocale(LC_ALL, "rus");
	int m[N] = { 0 };
	int* mas;
	int i = 0;
	//Случайные числа
	//Алгоритм Шелла
	mas = &m[0];
	srand(time(NULL));
	
	for (i; i < N; ++i) m[i] =rand()%100;
    mas = &m[0];
	diff = clock();
	shell(m, N);
	diff = (clock() - diff)/1000;
	printf_s("Время сортировки по алгоритму Шелла для случайного массива:%lf \n",diff);	
	//Быстрая сортировка
	mas = &m[0];
	for (i=0; i < N; ++i) m[i] = rand() % 100;
    diff = clock();
	qs(mas, 0, N-1);
	diff = (clock() - diff)/1000;
	printf_s("Время быстрой сортировки: %lf\n",diff);
	//Стандартная сортировка
	mas = &m[0];
	for (i = 0; i < N; ++i) m[i] = rand() % 100;
	mas = &m[0];
	diff = clock();
	qsort(mas, N, sizeof(int), (int(*) (const void*, const void*)) comp);
    diff = (clock() - diff)/1000;
	printf_s("Время стандартной сортировки:%lf \n",diff);
	printf_s("\n");
	//Возрастающая последовательность:
	//алгоритм Шелла:
	mas = &m[0];
	for (i = 0; i < N; i++) mas[i] = i + 1;
	mas = &m[0];
	diff = clock();
	shell(m, N);
	diff = (clock() - diff)/1000;
	printf_s("Время сортировки по алгоритму Шелла для возрастающей последовательноси:%lf \n", diff);
	//Быстрая сортировка:
	for (i = 0; i < N; i++) m[i] = i + 1;
	diff = clock();
	qs(mas, 0, N - 1);
	diff = (clock() - diff)/1000;
	printf_s("Время быстрой сортировки: %lf\n", diff);
	//Стандартная сортировка
	mas = &m[0];
	for (i = 0; i < N; i++) mas[i] = i + 1;
	mas = &m[0];
	diff = clock();
	qsort(mas, N, sizeof(int), (int(*) (const void*, const void*)) comp);
	diff = (clock() - diff)/1000;
	printf_s("Время стандартной сортировки:%lf \n",diff);
	printf_s("\n");
	//Убывающая последовательность:
	//Алгоритм Шелла:
	mas = &m[0];
	for (i = 0; i < N; i++) mas[i] = N - i;
	mas = &m[0];
    diff = clock();
	shell(m, N);
	diff = (clock() - diff)/1000;
	printf_s("Время сортировки по алгоритму Шелла для убывающей последовательности:%lf \n", diff);
	//Быстрая сортировка:
	mas = &m[0];
	for (i = 0; i < N; i++) mas[i] = N - i;
	mas = &m[0];
	diff = clock();
	qs(mas, 0, N - 1);
	diff = (clock() - diff)/1000;
	printf_s("Время быстрой сортировки: %lf\n", diff);
	//Стандартная функция:
	mas = &m[0];
	for (i = 0; i < N; i++) mas[i] = N - i;
	mas = &m[0];
	diff = clock();
	qsort(mas, N, sizeof(int), (int(*) (const void*, const void*)) comp);
	diff = (clock() - diff)/1000;
	printf_s("Время стандартной сортировки:%lf \n",diff);
	printf_s("\n");
	//Половина массива возрастающая, половина - убывающая
	//Алгоритм Шелла
	mas = &m[0];
	for (i = 0; i < N/2; i++) mas[i] = i+1;
	for (i = N / 2; i < N; i++) mas[i] = N - i;
	mas = &m[0];
	diff = clock();
	shell(m, N);
	diff = (clock() - diff)/1000;
	printf_s("Время сортировки по алгоритму Шелла для возрастающей и убывающей последовательности:%lf \n",diff);
	//Быстрая сортировка:
	mas = &m[0];
	for (i = 0; i < N / 2; i++) mas[i] = i + 1;
	for (i = N / 2; i < N; i++) mas[i] = N - i;
	mas = &m[0];
	diff = clock();
	qs(mas, 0, N - 1);
	 diff = (clock() - diff)/1000;
	printf_s("Время быстрой сортировки: %lf\n", diff);
	//Стандартная сортировка:
	mas = &m[0];
	for (i = 0; i < N / 2; i++) mas[i] = i + 1;
	for (i = N / 2; i < N; i++) mas[i] = N - i;
	mas = &m[0];
	diff = clock();
	qsort(mas, N, sizeof(int), (int(*) (const void*, const void*)) comp);
	diff = clock() - diff;
	diff = (clock() - diff)/1000;;
	printf_s("Время стандартной сортировки:%lf \n",diff);
	getchar();
}




void shell(int *items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	
	for (k = 0; k < 5; k++)
	{
		gap = a[k];
		for (i = gap; i < count; ++i)
		{
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap]=x;
		}
	}
	
}

void qs(int* items, int left, int right)
{
	int i, j;
	int x, y;
	i = left;
	j = right;
	x = items[(left + right) / 2];
	do
	{
		while ((items[i] < x) && (i < right))i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j)
		{
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}
int comp(const int* i, const int* j)
{
	return *i - *j;
}
