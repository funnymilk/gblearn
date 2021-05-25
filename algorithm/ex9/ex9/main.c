#include <stdio.h>

#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

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
    return 0;
}


void DecToBin(int a){
    while (a > 0){
        push(a % 2);
        a /= 2;
    }
}
