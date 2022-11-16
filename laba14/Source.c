#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define N 100
double func(double x)
{
	return pow(x, 3) - 4 * pow(x, 2) + 2;
}
double* full_elements(double* ptr_array, int n)
{
	double shag = 2. / N;
	int i = 0;
	double x = 1;
	for (x, i; i < n; x += shag)
	{
		ptr_array[i] = func(x);
		i++;
	}
	return ptr_array;
}
//double* full_elements(double* ptr_array, int n)
//{
//	int shag = 1;
//	int i = 0;
//	double x = 1;
//	for (x, i; i < n; x += shag)
//	{
//		ptr_array[i] = x;
//		i++;
//	}
//	return ptr_array;
//}
int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d]= %lf\n", i + 1, ptr_array[i]);
	}
	return(0);
}
double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = (-1) * ptr_array[i];
	}
	return ptr_array;
}
int put_calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("a[%d] = %lf\n", i + 1, ptr_array[i]);
	}
	return(0);
}
double sum_elements(double* ptr_array, int begin, int end)
{
	double sum=0;
	for (int i=begin-1; i <= end-1; i++)
	{
		sum += ptr_array[i];
	}
	return sum;
}
int find_element(double* ptr_array, int n, double v)
{

	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == v)
			return i+1;
	}
	return -1;
}
int function(double* ptr_array, int n, int k)
{	
	int min=0, e, min_znach;
	min_znach = 10000000;
	for (int i = 1; i < n; i++)
	{
		e= ptr_array[i];
		if ((e % k)==0 && e < min_znach)
		{
			min = i + 1;
			min_znach = e;
		}

	}
	return min;
}
int min_znach(double* ptr_array, int n, int Q)
{
	int min = 0, e, min_znach;
	min_znach = 10000000;
	for (int i = 1; i < n; i++)
	{
		e = ptr_array[i];
		if (ptr_array[i] > Q && ptr_array[i] < min_znach)
		{
			min = i + 1;
			min_znach = e;
		}

	}
	return min;
}
main()
{
	setlocale(LC_ALL, "RU");

	double array[N], ved, v, k, kr, Q, y;
	double* prt_array;
	int size, n, a, b, begin, end, menu=9;
	printf("Введите размер массива > ");
	scanf("%d", &size);
	n = size;
	full_elements(array, n);
	printf("1-массив\n2-изменить массив\n3-вычислить сумму элементов массива\n4-найти введенное значение в массиве\n5-найти порядковый номер минимального значение, кратного введенному числу\n6-Поиск порядкового номера минимального элемента, большего заданного\n0-выход\n");
	while (menu != 0)
	{
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			put_elements(array, n);
			break;
		case 2:
			printf("Изменение массива\n");
			calc_elements(array, n);
			put_calc_elements(array, n);
			break;
		case 3:
			printf("Введите от какого и по какой элемент вычислять сумму\n");
			scanf("%d%d", &a, &b);
			begin = a;
			end = b;
			printf("Сумма: %lf\n", sum_elements(array, begin, end));
			break;
		case 4:
			printf("Введите значение\n");
			scanf("%lf", &ved);
			v = ved;
			printf("%d\n", find_element(array, n, v));
			break;
		case 5:
			printf("Введите значение, которому должно быть кратно число\n");
			scanf("%lf", &kr);
			k = kr;
			printf("%d\n", function(array, n, k));
			break;
		case 6:
			printf("Введите значение\n");
			scanf("%lf", &y);
			Q = y;
			printf("%d", min_znach(array, n, Q));
			break;
		default:
			printf("Неправильный ввод\n");
		}
	}
}