#include <stdio.h>
#include <stdlib.h>

#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1
#define sz 10
typedef int boolean;
typedef struct{
    int pr;
    int dat;
} Item;

Item* arr[sz];
int head;
int tail;
int items;

void init(){
    for (int i = 0; i < sz; ++i){
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat){
    Item *item = (Item*) malloc(sizeof(Item));
    item->dat = dat;
    item->pr = pr;
    if (items < sz) {
        arr[tail++] = item;
        items++;
    } else if (items == sz){
        printf("%s \n", "Queue is full");
        return;
    }
}

Item* rem(int pr){
    int i = 0;
    if (items == 0){
        return NULL;
    } else {
        Item *tmp;
        while (i <= tail-1){
            if (arr[i]->pr == pr){
                tmp = arr[i];
               for(int j = i; j <= tail-2; j++){
                    arr[j] = arr[j+1];
                }
                arr[tail-1] = NULL;
                items--;
                tail--;
                return arr[tail];
            }
            i++;
        }
    }
}

void printQueue(){
    printf("[");
    for (int i = 0; i < sz-1; i++){
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf("]\n");
}

int cursor = -1;
T Stack[SIZE];

boolean push(T data){
    if (cursor < SIZE) {
        Stack[++cursor] =  data;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop(){
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void DecToBin(int a);

int main()
{
    DecToBin(5069);
    while (cursor != -1){
        printf("%d ", pop());
    }
    printf("\n");
    printf("----------------------------------\n");

    init();
    ins(1, 1);
    ins(4, 22);
    ins(5, 23);
    ins(1, 223);
    ins(2, 0);
    ins(4, 43);
    ins(7, 12);
    ins(2, 15);
    ins(9, 11);
    printQueue();

    for (int i = 0; i < tail; i++){
        rem(2);

    }
    printQueue();


    ins(1, 1);
    printQueue();


    return 0;
}


void DecToBin(int a){
    while (a > 0){
        push(a % 2);
        a /= 2;
    }
}
