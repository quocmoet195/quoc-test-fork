# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <locale.h>
#define N 100
#define M 100
int main()
{
	int A[N][M];
	int C[M];

	setlocale(LC_ALL, " ");
	printf("Объявление матрица, число n - количество строк, число m - количество столбца\n");
	int n, m;
	while (true)
	{
		printf("Введите количество строк n (0<n<100): ");
		scanf_s("%d", &n);
		if (n > 0 && n < 100)
			break;
		printf("Ошибка!\n");
	}

	while (true)
	{
		printf("Введите количество столбца m (0<m<100): ");
		scanf_s("%d", &m);
		if (m > 0 && m < 100)
			break;
		printf("Ошибка!\n");
	}

	// Введите матрицу
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("Введите A[%d][%d]= ", i, j);
			scanf_s("%d", &A[i][j]);
		}
	}
	// Выходной матрицу
	printf("\n\nИсходная матрица A(n*m):\n ");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", A[i][j]);
		}
		printf("\n ");
	}

	// Найти максимальный элемент каждого столбца 
	for (int j = 0; j < m; j++)
	{
		int max = A[0][j];
		for (int i = 0; i < n; i++)
		{
			if (max < A[i][j])  max = A[i][j];
		}
		C[j] = max;
	}
	// Выхоной вектор С(м)
	printf("\nИсходная вектор С(m):\n ");
	for (int j = 0; j < m; j++)
	{
		printf("%d\t", C[j]);
	}

	// Найти сумму элеметов матриц
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum = sum + A[i][j];
		}
	}
	printf("\n\nСумму элеметов матриц: %d", sum);
	// Найти минимальный и максимальный элемент матрицы С(м) и сложить сумму элементов
	int min = C[0];
	int imin = 0;
	for (int j = 0; j < m; j++)
	{
		if (C[j] < min)
		{
			min = C[j];
			imin = j;
		}
	}

	int max = C[0];
	int imax = 0;
	for (int j = 0; j < m; j++)
	{
		if (C[j] > max)
		{
			max = C[j];
			imax = j;
		}
	}

	C[imin] = C[imin] + sum;
	C[imax] = C[imax] - sum;
	// Выхоной вектор С(м)
	printf("\n\nВектор изменился C(m): \n ");
	for (int j = 0; j < m; j++)
	{
		printf("%d\t", C[j]);
	}

	return 0;
}