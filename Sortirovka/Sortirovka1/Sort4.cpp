/*! \file Sort4.cpp
\brief FastSorting
More Information...
*/
#include "stdafx.h"
#include "malloc.h"
#include "stdlib.h"

//! Quick sort func
void qs(int* s_arr, int first, int last)
{
	// Опорный элемент - центральный
    int i = first, j = last, x = s_arr[(first + last) / 2];
	
	// Разбиваем массив на части
    do {
        while (s_arr[i] < x) i++;
        while (s_arr[j] > x) j--;
 
        if(i <= j) {
            if (s_arr[i] > s_arr[j]) {
				int tmp = s_arr[i];
				s_arr[i] = s_arr[j];
				s_arr[j] = tmp;
			}

            i++;
            j--;
        }
    } while (i <= j);
	
	// Сортируем оставшиеся блоки рекурсивно
    if (i < last)
        qs(s_arr, i, last);
    if (first < j)
        qs(s_arr, first, j);
}

//! Функция main() − точка входа в программу.
int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0;
	scanf("%d", &n);
	
	// Забираем массив
	int* arr = (int *)malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	// Сортируем
	qs(arr, 0, n - 1);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}

	system("pause");

	return 0;
}

