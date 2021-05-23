#include <stdio.h>
#include "func.h"

void qsrt(int *arr, int right);
void hoar(int *arr, int left, int right);
int main()
{
    printf("Class7!\n");
    int size = 25;
    int a[size];
    initarray(a, size);
    printer1int(a, size);
    qsrt(a, size-1);
    //hoar(a, 0, size-1);
    printer1int(a, size);
    return 0;
}


void qsrt(int *arr, int right){
    int i, tmp, s;
    printf("j=%d\n", right);
    if (right <= 10){
            printf("%d<=10\n", right);
            for (i = 1; i < right; i++){
               tmp = arr[i];
               s = i - 1;
               while (s>=0 && arr[s] > tmp){
                   arr[s + 1] = arr[s];
                   s--;
               }
               arr[s + 1] = tmp;
            }
    } else {
         /*//printf("else %d>10\n", j);
         x = arr[(l+j)/2];
         do {
             printf("x= %d\n", j/2);
             while((arr[l] < x) && (l < right)) l++;
             while((x < arr[j]) && (j > left)) j--;

                if(l <= j) {
                  y = arr[l];
                  arr[l] = arr[j];
                  arr[j] = y;
                  l++; j--;
                }

         } while (l <= j);
          printf("j=%d\n req", j);
         if(left < j) qsrt(arr, left, j);
         if(l < right) qsrt(arr, l, right);*/
        hoar(arr, 0, right);
    }

}

void hoar(int *arr, int left, int right){
    int x,y, j, l;
    l = left;
    j = right;
    x = arr[(l+j)/2];
    do {
        while((arr[l] < x) && (l < right)) l++;
        while((x < arr[j]) && (j > left)) j--;
           if(l <= j) {
             y = arr[l];
             arr[l] = arr[j];
             arr[j] = y;
             l++; j--;
           }
    } while (l <= j);
    if(left < j) hoar(arr, left, j);
    if(l < right) hoar(arr, l, right);
}
