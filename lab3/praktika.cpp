#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

# define N 100

void print_N_f(int n)
{
	if (n >= 0)
	{
		printf("%d ", n);
		print_N_f(n - 1);
		printf("%d ", n);
	}

}


int main()
{
	char str[] = "Hello world!";
	const char* p = str;
	while (*p) p++;
	int len = p - str;
	printf("string length is %d\n", len);
	printf("%s\n", str);
	return 0;
}


//int main()
//{
//	setlocale(lc_all, " ");
//	int n = 10;
//	print_n_f(n);
	//int n, max, min, imax=0, imin=0, sum=0, arr[N];
	//while (1)
	//{
	//	printf("Введите количество элементов массива (n<100) n=");
	//	scanf_s("%d", &n);
	//	if (n > 0 && n < 100)
	//		break;
	//	printf("Ошибка!\n");
	//}

	//printf("Введите элементы массива:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	printf("arr[%d]= ", i);
	//	scanf_s("%d", &arr[i]);
	//}
	//max = arr[0];
	//min = arr[0];
	//for (int i = 0; i < n; i++)
	//{
	//	if (max < arr[i])
	//	{
	//		max = arr[i];
	//		imax = i;
	//	}
	//	else if (min > arr[i])
	//	{
	//		min = arr[i];
	//		imin = i;
	//	}
	//}

	//if (imin < imax)
	//{
	//	for (int i = imin + 1; i < imax; i++)
	//	{
	//		sum = sum + arr[i];
	//	}
	//}
	//else
	//{
	//	for (int i = imax + 1; i < imin; i++)
	//	{
	//		sum = sum + arr[i];
	//	}
	//}

	//printf("Результат: %d", sum);
//	return 0;
//}