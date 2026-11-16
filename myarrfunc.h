//f10 Вычисление суммы элементов в заданном диапазоне индексов k–m
//f17 Определение индексов элементов массива, находящихся в заданном диапазоне значений k–m
//f28 Вычисление индексов элементов, значения которых выше среднего значения массива
#ifndef MYARRFUNC_H
#define MYARRFUNC_H
#include <stddef.h>
 
void fillArr(int *arrptr, size_t len);

void printArr(int *arrptr, size_t len);

int elementsSum(int *arrptr, size_t len, size_t k, size_t m, int *res);

int findIndices(int *arrptr, size_t len, int k, int m, size_t *indices, size_t *count);

int findAboveAverage(int *arrptr, size_t len, size_t *indices, size_t *count, double *average);
#endif