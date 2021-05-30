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

typedef struct Nodel {
    int dat;
    struct Nodel *next;
} Nodel;

typedef struct{
    Nodel *head;
    int size;
} List;

//----------------------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------

void listinit(List *list){
    list->head = NULL;
    list->size = 0;
}

void ins(List *list, int data){
    Nodel *new = (Nodel*) malloc(sizeof (Nodel));
    new->dat = data;
    new->next = NULL;

    Nodel *current = list->head;
    if (current == NULL){
        list->head = new;
        list->size++;
    } else {
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new;
        list->size++;
    }

}

void printNodel(Nodel *n){
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printList(List *list){
    Nodel *current = list->head;
    if (current == NULL){
        printNodel(current);
    } else {
        do{
            printNodel(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", list->size);
}

void cpl(List *l, List *d){
    Nodel *current = l->head;
    if (current == NULL){
        printNodel(current);
    } else do {
        ins(d, current->dat);
        current = current->next;
    } while (current != NULL);
}

void sortOrNot(List *lst){
    Nodel *current = lst->head;
    boolean check = true;
    if (current == NULL){
        printNodel(current);
    } else while (current != NULL) {
        if (current->next != NULL) {
            if (current->dat <= current->next->dat) {
                check = true;
            } else {
                printf("Список не отсортирован!\n");
                check = false;
                break;
            }
    }
    current = current->next;
    }
    if (check && (current == NULL)) printf("Список отсортирован с:\n");
}

int main()
{
   /* T p[20];
    scanf("%s", p);
    //printf("%s\n", p);
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);
    checkPSP(st, p);
    printOneLinkCharStack(st);*/

    List *lst = (List*) malloc(sizeof(List));
    List *lst2 = (List*) malloc(sizeof(List));
    init(lst);
    printList(lst);
    ins(lst, 1);
    ins(lst, 8);
    ins(lst, 6);
    printList(lst);
    init(lst2);
    cpl(lst, lst2);
    //printList(lst2);

    sortOrNot(lst2);
    return 0;
}
