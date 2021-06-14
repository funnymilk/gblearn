#include <stdio.h>
#include <string.h>
#include <math.h>
#include "geek.h"

void cezar(T cryp[256], int key){
    int len = 0;
    initQ();


    while (cryp[len] != 0){
        if ( ((cryp[len] > 64) && (cryp[len] < 91)) || ((cryp[len] > 96) && (cryp[len] < 123))){
           cryp[len] += key;
        }
        //printf("%c", cryp[len]);
        len++;
    }
    len = 0;
    printf("crypto = ");
    while (cryp[len] != 0){
        printf("%c", cryp[len]);
        len++;
    }
   //НЕ РАЗОБРАЛСЯ КАК ОБРАБАТЫВАТЬ МАСИВ СИМВОЛОВ НА ВЫХОДЕ ИЗ ФУКНЦИИ
} //ПОСМОТРЕТЬ СПИСКИ

void reshuffle(T cryp[256]){
    char mas[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
                 mas[i][j] = cryp[j + (4*i)];
        }
    }
    char buff;
    char key = 'carts';
//    for (int i = 0; i < 5; i++){
//        for (int j = 0; j < 5; j++){

//            if ()



//                if (j == 2){
//                    buff = mas[i][j];
//                    mas[i][j] = mas[i][j+1];
//                    mas[i][j+1] = buff;
//                }
//        }
//    }
//    ;





    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%3c", mas[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    char s[256] = "Hello, my dear friend";
     char *k;
    //n = s;
    int len = 0;
    printf("original = ");
    while (s[len] != 0){
        printf("%c", s[len]);
        len++;
    }
    printf("\n");
//    printf("crypto = %c", cezar(s, 3));
//    strcpy(n, cezar(s,3));
    cezar(s,3);
   printf("\n");
   reshuffle(s);

    printf("\n");
    return 0;
}
