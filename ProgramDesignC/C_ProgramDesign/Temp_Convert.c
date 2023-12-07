#include <stdio.h>
#define FREEZING_PT 32.0
#define FTOC_FACTOR (5.0/9.0)
#define CTOF_FACTOR (9.0/5.0)

int main (void){
    double fah, cel;
    int option;
    printf("Welcome to the Temperature Conversion Program!\n Please choose your option:\n1. Convert the tempurature from F to C.\n2. Convert the tempurature from C to F.\n");
    scanf("%d",&option);
    if (option == 1){
        printf("Please enter the Fahrenheight tempurature:\n");
        scanf("%lf", &fah);
        cel = (fah - FREEZING_PT)*FTOC_FACTOR;
        printf("Celsius is %.2f when Fahrenheit is %.2f.\n", cel, fah);
    }
    else if (option == 2) {
        printf("Please enter the Celsius tempurature:\n");
        scanf("%lf", &cel);
        fah = (cel*FTOC_FACTOR) + FREEZING_PT;
        printf("Fahrenheit is %.2f when Celsius is %.2f.\n", fah, cel);
    }
    else{
        printf(" Invalid option! Please enter 1 or 2.\n");
        printf("1 for convert Fahrenheight to Celcius or 2 for convert Celsius to Fahrenheight.\n") ;
        scanf("%d",&option);
    }
    return 0;   
}