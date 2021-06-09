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

Nodel* findNode(Nodel** table, K data){
    Nodel *p = table[hash(data)];
    while (p && !(p->dat == data))
        p = p->next;
    return p;
}

void deleteNode(Nodel** table, K data){
    Nodel *parent, *current;
    parent = NULL;
    htIndex bucket = hash(data);
    current = table[bucket];
    while (current && !(current->dat ==  data)){
        parent = current;
        current = current->next;
    }
    if (!current){
        printf("Value not found \n");
        return;
    }
    if (parent)
        parent->next = current->next;
    else
        table[bucket] = current->next;
    free(current);
}

void printTable(Nodel** table, int size){
    Nodel *p;
    for (int i = 0; i < size; ++i){
        p = table[i];
        while (p){
            printf("%5d", p->dat);
            p = p->next;
        }
        printf("\n");
    }
    printf("\n");
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
//    int len = 0;
    Nodel *p;

    int sum = 0;
    for (int i = 0; i < size; ++i){
        p = table[i];
        if (p != NULL){
            //printf("i=%d\n", i);
            while (p){
                //printf("dat=%5d", p->dat);
                sum += p->dat;
                p = p->next;
                //printf("%5d", p->next->dat);
            }
        }
    }
    return sum;
}

int main()
{
    htSize = 8;
    int* arr;
    const int SZ = 20;
    arr = (int*) malloc(sizeof(int) * SZ);
    initarray(arr, SZ);

   /* Nodel** hashTable = (Nodel**) calloc(htSize, sizeof(Nodel*));
    for (int i = 0; i < SZ; ++i){
        insertNode(hashTable, arr[i]);
    }
    printTable(hashTable, htSize);

    //printNodel(findNode(hashTable, 17));
    //printNodel(findNode(hashTable, 23));
    //printNodel(findNode(hashTable, 9));

    for (int i = 0; i< SZ / 2; ++i){
        deleteNode(hashTable, arr[i]);
    }
    printTable(hashTable, htSize);*/
    char s[100] = "Hello world! I start to learn you. You have not chance!";
    int len = 0;
    Nodel** htChar = (Nodel**) calloc(htSize, sizeof(Nodel*));
    while (s[len] != 0){
        insertNode(htChar, s[len]);
        len++;
    }
    printTableChar(htChar, htSize);

//    Nodel** hashTable = (Nodel**) calloc(htSize, sizeof(Nodel*));
    printf("sum = %d\n", cSum(htSize, htChar));

    return 0;
}
