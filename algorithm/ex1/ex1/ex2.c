#include <stdio.h>

int main()
{
    int b;
    printf("vvedite b=");
    scanf("%d", &b, 4);
    if (b == 1) {
        printf("Число простое \n");
    } else {
        int i = 2;
        int k = 2;
        while ((i < b)){
            if ((b % i) == 0) {
                //printf("Число не простое\n");

                k++;
                break;
            }
            i++;
        }
        if (k < 3) printf("Число простое \n");
        else printf("число непростое\n");
    }
    return 0;
}
