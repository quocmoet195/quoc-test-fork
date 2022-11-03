#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<locale.h>
#define N 100
#define L 2

//Введите таблицу известных значений функции
void input(double arr[L][N], int n);

//Вывести на экран таблицу значений функции
void output(double arr[L][N], int n);

//Проверяю, между какими двумя точками находится точка Х?. Возвращает адрес точки больше Х 
int check(double arr[L][N], int n, double x);

// Вычислить значение функции в точке x: F = F' + ((F" - F') * (x - x')) / (x" - x')  (Формула линейная интерполяция)
double formula(double arr_in[L][N], double X_k, int add);

//
void add_element_X(double arr[L][N], int n, int add, double X_k, double F_k);


int main()
{
	int tem;
	do
	{
	int n,m,add=0;
	double X_k, F_k;
	double arr_in[L][N];
		setlocale(LC_ALL, "");
		printf("Введите количество известных точек функции n= ");
		scanf_s("%d", &n);

		printf("Введите таблицу значений функции f(x): \n");
		input(arr_in, n);

		printf("\nИмпортированная таблица значений функций: \n");
		output(arr_in, n);

		printf("Введите X_k для расчета: ");
		scanf_s("%lf", &X_k);

		add = check(arr_in, n, X_k);
		F_k = formula(arr_in, X_k, add);
		add_element_X(arr_in, n, add, X_k, F_k);

		printf("\nТаблица значений, подлежащих определению:\n");
		output(arr_in, n+1);

		printf("\nВведите «0» для выхода или «1» для повторного расчета: ");
		scanf_s("%d", &tem);
	} while (tem == 1);
	return 0;
}


//Введите таблицу известных значений функции
void input(double arr[L][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Введите точку X%d= ", i + 1);
		scanf_s("%lf", &arr[0][i]);
		printf("Введите значение F%d= ", i + 1);
		scanf_s("%lf", &arr[1][i]);
	}
}

//Вывести на экран таблицу значений функции
void output(double arr[L][N], int n)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.3lf\t\t", arr[i][j]);
		}
		printf("\n");
	}
}

//Проверяет, между какими двумя точками находится точка Х?. Возвращает адрес точки больше Х 
int check(double arr[L][N], int n, double x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (x < arr[0][i]) break;
	}
	return i;
}

// Вычислить значение функции в точке x: F = F' + ((F" - F') * (x - x')) / (x" - x')
double formula(double arr_in[L][N], double X_k, int add)
{
	double T1 = arr_in[1][add] - arr_in[1][add - 1]; //F" - F'
	double T2 = X_k - arr_in[0][add - 1];  //x - x'
	double T3 = arr_in[0][add] - arr_in[0][add - 1]; //x" - x'
	double T4 = arr_in[1][add - 1];                  //F'
	double F = T4 + (T1 * T2) / T3;                  //F
	return F;
}

void add_element_X(double arr[L][N], int n, int add, double X_k, double F_k)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = n-1; j >= add; j--)
		{
			arr[i][j + 1] = arr[i][j];
		}
	}
	arr[0][add] = X_k;
	arr[1][add] = F_k;
}

