#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<windows.h>
void main()
{
    setlocale(LC_ALL, "rus");
    int** a;  // указатель на массив указателей на строки
    int i, j, n, m;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    printf("Введите количество столбцов: ");
    scanf("%d", &m);
    // Выделение памяти под массив указателей
    a = (int**)malloc(n * m * sizeof(int));
    //Ввод элементов массива
    for (i = 0; i < n; i++)  // цикл по строкам
    { 
        a[i] = (int*)malloc(m * sizeof(int));//Выделение памяти для строки
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            a[i][j] = rand() % 100;
        }
    }
    // Вывод элементов массива
    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    //Максимальный элемент
    int max = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }

    }
    printf("Максимальный элемент = %d", max);
    printf("\n");
    //Вычисление суммы каждой строки
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            sum = sum + a[i][j];
        }
        printf("Сумма элементов %d строки = %d", i + 1, sum);
        printf("\n");
        sum = 0;
    }
    free(a);

    //Работа со структурами:
    struct st
    {
        char famil[20];
        char name[20];
        int num;
    }student[5];
    student[0].num = 1;
    strcpy(student[0].famil, "Ivanov");
    strcpy(student[0].name, "Ivan");

    student[1].num = 2;
    strcpy(student[1].famil, "Petrov");
    strcpy(student[1].name, "Petr");

    student[2].num = 3;
    strcpy(student[2].famil, "Sidorovich");
    strcpy(student[2].name, "Sidor");

    student[3].num = 4;
    strcpy(student[3].famil, "Vasilev");
    strcpy(student[3].name, "Vasili");

    student[4].num = 5;
    strcpy(student[4].famil, "Sergeev");
    strcpy(student[4].name, "Sergay");
    char ind;
    int flag = 0;
    char stroka[20] = { '/0' };
    int nomer = 0;
label:
    flag = 0;
    printf("Введите F для поиска по фамилии, N для поиска по имени, C для поиска по номеру: ");
    scanf_s("%c", &ind);
    ind = getchar();
    switch (ind)
    {
    case 'F':
    {
        printf("Введите фамилию:");
        scanf("%s", stroka);
        for (i = 0; i < 5; ++i)
        {
            if (strcmp(stroka, student[i].famil) == 0)
            {
                printf("Найдено: %d, %s, %s", student[i].num, student[i].famil, student[i].name);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Ничего не найдено\n");
            goto label;
        }
    }
    break;
    case 'N':
    {
        printf("Введите имя:");
        scanf("%s", stroka);
        for (i = 0; i < 5; ++i)
        {
            if (strcmp(stroka, student[i].name) == 0)
            {
                printf("Найдено: %d, %s, %s", student[i].num, student[i].famil, student[i].name);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Ничего не найдено\n");
            goto label;
        }
    }
    break;
    case 'C':
    {
        printf("Введите номер:");
        scanf("%d", &nomer);
        for (i = 0; i < 5; ++i)
        {
            if (student[i].num == nomer)
            {
                printf("Найдено: %d, %s, %s", student[i].num, student[i].famil, student[i].name);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            printf("Ничего не найдено\n");
            goto label;
        }
    }
    break;
    default:
    {
        printf("Ошибка\n");
        goto label;
    }

    }
    getchar();
    getchar();
}