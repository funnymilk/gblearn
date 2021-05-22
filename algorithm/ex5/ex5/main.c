#include <stdio.h>
#include "func.h"
#include <math.h>

void bubble(int *arr, int lenrow, int lencol);
void tpk(double *arr, int len);

int main()
{
    int a[3][3] = {{1,9,2},{5,7,6},{4,3,8}};
    printf("Hello World!\n");
    printer2(*a,3,3);
    printf("\n");
    bubble(*a,3,3);
    printer2(*a,3,3);
    printf("\n");

    double b[11];
    printf("Введите 11 чисел: ");

    for (int i=0; i<11; i++){
        scanf("%lf", &b[i]);
    }
    printer1(b, 11);
    tpk(b, 11);
    printer1(b, 11);

    return 0;
}

void bubble(int *arr, int lenrow, int lencol){
    int a, row = 0, col;
    int i = 0;
    while (i < lenrow*lencol){
        for (row=0; row<3; row++){
           for (col=0; col<3; col++){
               if (arr[row*3 + col] > arr[row*3 + (col+1)])
               {
                   //printf("\n", arr[row*lenr + col]);
                   //printf("\n", arr[row*lenr + (col+1)]);
                   a = arr[row*3 + col];
                   arr[row*3 + col] = arr[row*3 + (col + 1)];
                   arr[row*3 + (col + 1)] = a;
               }
           }
       }
       i++;
    }
}

void tpk(double *arr, int len){
    int i;
    double tmp;
    for (i = 0; i <= 5; i++){
        tmp = arr[i];
        arr[i] = arr[5*2 - i];
        arr[5*2 - i] = tmp;
    }
    for (i=0; i < len; i++){
        tmp = sqrt(fabs(arr[i])) + 5.0*pow(arr[i],3);
        if (tmp > 400) printf("Результат вычисления элемента %d превышает 400\n", i);
    }
}

