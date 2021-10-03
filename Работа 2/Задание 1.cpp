#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
void function(int);
void main(void)
{
	setlocale(LC_ALL, "rus");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf_s("\nÌàòðèöà 100*100: \n");
	function(100);
	printf_s("\nÌàòðèöà 200*200: \n");
	function(200);
printf_s("\nÌàòðèöà 400*400: \n");
	function(400);
	printf_s("\nÌàòðèöà 1000*1000: \n");
	function(1000);
	printf_s("\nÌàòðèöà 2000*2000: \n");
	function(2000);
	printf_s("\nÌàòðèöà 4000*4000: \n");
	function(4000);
	printf_s("\nÌàòðèöà 10000*10000: \n");
	function(10000);
	
	
}

void function(int rasmer)
{
	int** mas1, ** mas2, ** mas3;
	int i = 0, j = 0, r = 0; int elem_c;
	time_t start, end,start1, end1;
	double rasn=0, rasn1=0;
	start1 = time(NULL);
	mas1=(int**)malloc(rasmer * sizeof(int));
	
	for (i = 0; i < rasmer; i++)
	{
		mas1[i] = (int*)malloc(rasmer * sizeof(int));
		
	}
	i = 0;
	mas2 = (int**)malloc(rasmer * sizeof(int));
	for (i = 0; i < rasmer; i++)
	{
		mas2[i] = (int*)malloc(rasmer * sizeof(int));
	}
	i = 0;

	mas3 = (int**)malloc(rasmer * sizeof(int));
	for (i = 0; i < rasmer; i++)
	{
		mas3[i] = (int*)malloc(rasmer * sizeof(int));
	}
	i = 0;
	srand(time(NULL));

	while (i < rasmer)
	{
		j = 0;
		while (j < rasmer)
		{
			mas1[i][j] = rand() % 100 + 1;
		    j++;
		}
		i++;
	}
	srand(time(NULL));
	i = 0;
	while (i < rasmer)
	{
		j = 0;
		while (j < rasmer)
		{
			mas2[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	//Ïåðåìíîæåíèå ìàòðèö:
	start = time(NULL);
	for (i = 0; i < rasmer; i++)
	{
		for (j = 0; j < rasmer; j++)
		{
			elem_c = 0;
			for (r = 0; r < rasmer; r++)
			{
				elem_c = elem_c + mas1[i][r] * mas2[r][j];
				mas3[i][j] = elem_c;
				
			}
		}

	}
	end = time(NULL);
	rasn = difftime(end, start);
	for (i = 0; i < rasmer; i++)
	{
		free(mas1[i]);
		free(mas2[i]);
		free(mas3[i]);
	}
	free(mas1);
	free(mas2);
	free(mas3);
	end1 = time(NULL);
	rasn1 = difftime(end1, start1);
	printf_s("Âðåìÿ âûïîëíåíèÿ ôóíêöèè: %lf\n", rasn1);
	printf_s("Âðåìÿ âûïîëíåíèÿ óìíîæåíèÿ: %lf\n", rasn);
	
}
