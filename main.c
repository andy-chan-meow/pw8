#include <stdio.h>
#include "myarrfunc.h"

#define MAX_LEN 1000

int main(){
    int buffer[MAX_LEN];
    int *arr = buffer;
    size_t len = 0;
    char choice;
    int ch;
    int isFilled = 0;

    while(1){

        printf("\na  Задать размер массива\n");
        printf("b  Заполнить массив\n");
        printf("c  Представление массива (значения, адреса)\n");
        printf("d  Сумма элементов в заданном диапазоне индексов k-m\n");
        printf("e  Индексы элементов в заданном диапазоне значений k-m\n");
        printf("f  Индексы элементов со значением выше среднего\n");
        printf("g  Выход\n");
        printf("Выберите пункт: ");

        if (scanf(" %c", &choice) != 1) {
            printf("\nEOF or input error\n");
            return 0;
        }
        while((ch = getchar()) != '\n' && ch != EOF);

        switch(choice){
            case 'a': {
                printf("Enter size (1-%d): ", MAX_LEN);
                int input = scanf("%zu", &len);
                if (input == EOF){
                    printf("\nEOF\n");
                    return 0;
                }
                while((ch = getchar()) != '\n' && ch != EOF);

                if (input != 1 || len == 0 || len > MAX_LEN){
                    printf("\nIncorrect size\n");
                    len = 0;
                    break;
                }
                for(size_t i = 0 ; i < len ; i++){
                    *(arr+i) = 0;
                }
                isFilled = 0;
                printf("\nSize: %zu\n", len);
                break;
            }

            case 'b':
                if (len == 0) {
                    printf("\nSize hasn't been set");
                    break;
                }
                fillArr(arr, len);
                isFilled = 1;
                printf("\nArray filled\n");
                break;

            case 'c': 
                if (len == 0) {
                    printf("Size hasn't been set\n");
                    break;
                }
                if (!isFilled) {
                    printf("Empty array\n");
                }
                printArr(arr,len);
                break;
            
            case 'd': {
                if (len == 0 || !isFilled) {
                    printf("Empty array/ Size hasn't been set\n");
                    break;
                }
                size_t k = 0;
                size_t m = 0;
                printf("Enter k & m: ");
                int res = scanf("%zu %zu", &k, &m);
                if (res == EOF) {
                    return 0;
                }
                while((ch = getchar()) != '\n' && ch != EOF);

                if (res != 2) {
                    printf("Bad indices\n");
                    break;
                }

                int sum = 0;
                if (elementsSum(arr, len, k, m, &sum) == 0) {
                    printf("Sum of elements [%zu-%zu]: %d\n", k, m, sum);
                } else {
                    printf("Wrong indices 0 <= k <= m < %zu\n", len);
                }
                break;
            }

            case 'e': {
                if (len == 0 || !isFilled) {
                    printf("Empty array/ Size hasn't been set\n");
                    break;
                }
                int k = 0;
                int m = 0;
                printf("Enter k & m: ");
                int res = scanf("%d %d", &k, &m);
                if (res == EOF) {
                    return 0;
                }
                while((ch = getchar()) != '\n' && ch != EOF);

                if (res != 2) {
                    printf("Wrong values\n");
                    break;
                }

                size_t indices[len];
                size_t count = 0;
                if (findIndices(arr, len, k, m, indices, &count) == 0) {
                    printf("Find elements (%zu), indices: ", count);
                    for (size_t i = 0; i < count; i++) {
                        printf("%zu ", *(indices + i));
                    }
                    printf("\n");
                } else {
                    printf("have no elements in [%d-%d]\n", k, m);
                }
                break;
            }

            case 'f': {
                if (len == 0 || !isFilled) {
                    printf("Empty array/ Size hasn't been set\n");
                    break;
                }

                size_t indices[len];
                size_t count = 0;
                double avg = 0.0;
                if (findAboveAverage(arr, len, indices, &count, &avg) == 0) {
                    printf("avg arthmetic: %.2f\n", avg);
                    printf("Indices elements above average: ");
                    for (size_t i = 0; i < count; i++) {
                        printf("%zu ", *(indices + i));
                    }
                    printf("\n");
                } else {
                    printf("avg arithmetic: %.2f. Have no elements above avg.\n", avg);
                }
                break;
            }

            case 'g':
                printf("Exit\n");
                return 0;

            default:
                printf("Unknown parameter '%c'. Select a-g\n", choice);
                break;
        }
    }
    
    return 0;
}
