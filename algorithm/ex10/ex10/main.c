#include <stdio.h>
#include <stdlib.h>
#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct{
    Node *head;
    int size;
} Stack;

void init(Stack *stack){
    stack->head = NULL;
    stack->size = 0;
}


boolean push(Stack *stack, T value){
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack){
    if (stack->size == 0){
        printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack ->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void printOneLinkCharNode(Node *n){
    if (n == NULL){
        printf("[]");
        return;
    }
    printf("%c ", n->dat);
}

void printOneLinkCharStack(Stack *stack) {
    Node *current = stack -> head;
    if (current == NULL){
        printOneLinkCharNode(current);
    } else {
        do {
            printOneLinkCharNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}

void checkPSP(Stack *stack, T p[20]){
    int len = 0;
    boolean check = true;
    T tmp;
    while ((p[len] != 0) ){
        //printf("%c\n",p[len]);  ||
        if (((p[len] == '(') || (p[len] == '[') || (p[len] == '{'))) push(stack, p[len]);
        else if (((p[len] == '}') || (p[len] == ']') || (p[len] == ')'))) break;
        len++;
    }
    while (p[len] != 0){
        if (((p[len] == '}') || (p[len] == ']') || (p[len] == ')'))) {
            tmp = pop(stack);
            if (    ((tmp == '(') && (p[len] == ')')) || ((tmp == '{') && (p[len] == '}')) ||  ((tmp == '[') && (p[len] == ']'))    )
            check = true;
            else {
                check = false;
                break;
            }
        }
        len++;
        }

    if (check && (stack->size == 0)) printf("Скобочная последовательность правильная\n");
    else printf("Скобочная последовательность неправильная\n");
}


int main()
{
    T p[20];
    scanf("%s", p);
    //printf("%s\n", p);

    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    checkPSP(st, p);
    printOneLinkCharStack(st);
    /*

    push(st, 'h');
    push(st, 'k');
    push(st, 'm');
    printOneLinkCharStack(st);
    printf("%c \n", pop(st));
    printOneLinkCharStack(st);*/
    return 0;
}
