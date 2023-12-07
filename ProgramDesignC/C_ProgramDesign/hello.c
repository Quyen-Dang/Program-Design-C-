#include <stdio.h>

int main (void){
    printf("Hello World\n");
    int i =8;
    int j = 4;
    i *= j++;
    printf("%d %d\n", i,j);
    i = 3; j = 3; int k = 0;
    i *= j *= ++k;
    printf("%d %d %d\n", i, j, k);

    return 0;
}