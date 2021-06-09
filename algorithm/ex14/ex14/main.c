#include <stdio.h>
#include "geek.h"
typedef int K;
typedef int htIndex;

int htSize;

htIndex hash(T data){
    return data % htSize;
}

boolean insertNode(Nodel** table, K data){
    Nodel *p, *p0;

    htIndex bucket = hash(data);
    p = (Nodel*) malloc(sizeof(Nodel));
    if (p == NULL){
        printf("Out of memory! \n");
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}

void printTableChar(Nodel** table, int size){
    Nodel *p;
    for (int i = 0; i < size; ++i){
        p = table[i];
        while (p){
            printf("%5c", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
}

int cSum(int size, Nodel** table){
    Nodel *p;

    int sum = 0;
    for (int i = 0; i < size; ++i){
        p = table[i];
        if (p != NULL){
            while (p){
                sum += p->dat;
                p = p->next;
            }
        }
    }
    return sum;
}


void profit(int *n, int query){
    int sum, i;
    sum = 0;
    i = 0;
    //printf("sum = %d", query);
    //int result[100];
    //List *result;
    List *result = (List*) malloc(sizeof(List));
    listinit(result);

    while (sum != query){
        //printf("sum = %d      ", sum);
        if ((sum + n[i]) <= query){
            //printf("sum2 = %d   ", sum);
            //printf("n = %d  ", n[i]);
            sum += n[i];
            ins(result, n[i]);
            //printf("i = %d\n", i);

        } else i++;
    }

   printList(result);
}

int main()
{
    //_______________________________________________________________________
//    htSize = 8;

//    char s[100] = "Hello world! I start to learn you. You have not chance!";
//    int len = 0;
//    Nodel** htChar = (Nodel**) calloc(htSize, sizeof(Nodel*));
//    while (s[len] != 0){
//        insertNode(htChar, s[len]);
//        len++;
//    }
//    printTableChar(htChar, htSize);
//    printf("sum = %d\n", cSum(htSize, htChar));
    //_______________________________________________________________________

    int nominal[5] = {50, 10, 5, 2, 1};
    const int query = 98;
    profit(nominal, query);

    return 0;
}
