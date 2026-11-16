#include "myarrfunc.h"
#include <stdio.h>

void clearBuffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

void fillArr(int *arrptr, size_t len){
    if (arrptr == NULL || len == 0){
        return;
    }

    for (size_t i = 0 ; i < len ; i++){
        while(1){
            printf("Print element [%zu]: ", i);
            int res = scanf("%d", arrptr + i);
            if(res == EOF){
                printf("\nEOF\n");
                return;
            }
            if (res == 1){
                clearBuffer();
                break;
            }
            printf("Bad format\n");
            clearBuffer();
        }
    }
}

void printArr(int *arrptr, size_t len){
    if(arrptr == NULL || len == 0) return;
    printf("\nIndex | value        | address\n");
    for (size_t i = 0 ; i < len ; i++){
        printf("\n%6zu | %12d | %p\n", i, *(arrptr+i), (void *)(arrptr+i));
    }
}

int elementsSum(int *arrptr, size_t len, size_t k, size_t m, int *res){
    if (arrptr == NULL || len == 0 || k > m || m >= len){
        return -1;
    }
    int sum = 0;
    for (int *p = arrptr + k ; p <= arrptr + m ; p++ ){
        sum += *p;
    }
    *res = sum;
    return 0;
}

int findIndices(int *arrptr, size_t len, int k, int m, size_t *indices, size_t *count){
    if (arrptr == NULL || len == 0 || k > m || indices == NULL || count == NULL){
        return -1;
    }
    size_t found = 0;
    for (size_t i = 0; i < len; i++) {
        if (*(arrptr + i) >= k && *(arrptr + i) <= m){
            *(indices + found) = i;
            found++;
        }
    }
    *count = found;
    return (found > 0) ? 0 : -1;
}

int findAboveAverage(int *arrptr, size_t len, size_t *indices, size_t *count, double *average){
    if (arrptr == NULL || len == 0 || indices == NULL || count == NULL) return -1;
    int sum = 0;
    for (size_t i = 0; i < len ; i++){
        sum += *(arrptr+i);
    }

    double avg = (double)sum / (double)len;
    if (average != NULL) {
        *average = avg;
    }

    size_t found = 0;
    for (size_t i = 0; i < len; i++) {
        if ((double)(*(arrptr + i)) > avg) {
            *(indices + found) = i;
            found++;
        }
    }

    *count = found;
    return (found > 0 ) ? 0 : -1;
}