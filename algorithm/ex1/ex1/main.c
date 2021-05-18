#include <stdio.h>
#include <math.h>

int bintodec(int dec);
int expo(int a, int b);
int rexpo(int a, int b);
int chstep(int a, int b);
int routes(int x, int y, int b);


int main()
{
   // printf("bin = %d\n", bintodec(2));
   // printf("%d\n", rexpo(2,3));
    //printf("chstep = %d\n", chstep(2, 6));
    int sx = 5;
    int sy = 5;
    int a[5][5];
    memset(a, 0, sizeof(a));
    a[2][2] = 1;
    for (int y= 0; y < sy; ++y){
        for (int x = 0; x < sx; ++x){
                printf("%5d", a[x][y]);
        }
        printf("\n");
    }
            printf("\n");
    for (int y= 0; y < sy; ++y){
        for (int x = 0; x < sx; ++x){
           printf("%5d", routes(x, y, a[x][y]));
        }
        printf("\n");
    }
    //printf("r=%d\n", routes(1, 1, 0));
    return 0;
}

int bintodec(int dec){
    if (dec > 0){
        return (dec % 2) + (bintodec(dec/2) * (10));
    } else return 0;
}

int expo(int a , int b){
    printf("Возведение числа %d в степень %d равна ", a, b);
    int ex = 1;
    while (b > 0){
        ex *= a;
        b--;
    }
    return ex;
}

int rexpo(int a, int b){
    if (b > 1) {
        printf("b= %d ", b);
        printf("a= %d\n", a);
        return a * rexpo(a, --b);
    } else return a;
}

int chstep(int a, int b){
    if (((b % 2) == 0) && (b > 1)){
        printf("a = %d\n", a);
        printf("point 1: b=%d\n", b);
        return chstep(a*a, b/2);
        } else if (b >= 1){
            printf("a = %d\n", a);
            printf("point 2: b=%d\n", b);
            return chstep(a*a, b-1);
        } else return a;
}

int routes(int x, int y, int b){
        if (b == 1) return 0;
        if (x == 0 && y == 0) return 0;
        else if (x == 0) {
             if ((routes(x, y-1, b) == 0 && y !=1 )) return 0;
             return 1;
        }
        else if (y == 0) {
            if ((routes(x-1, y, b) == 0 && x != 1)) return 0;
            return 1;
        }
        else return routes(x, y - 1, b) + routes(x - 1, y, b);
}
