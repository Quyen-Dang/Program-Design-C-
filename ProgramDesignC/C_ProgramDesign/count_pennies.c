#include <stdio.h>

#define QUATER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int main (void){
    int pennies, real;
    int quater, dime, nickel, penny;
    printf("Please enter the number of quater you want to count: \n");
    scanf("%d", &quater);
    printf("Please enter the number of dime you want to count: \n");
    scanf("%d", &dime);
    printf("Please enter the number of nickel you want to count: \n");
    scanf("%d", &nickel);
    printf("Please enter the number of penny you want to count: \n");
    scanf("%d", &penny);
    printf("Number of quater %d, dime %d, nickel %d, penny %d", quater, dime, nickel, penny);
    pennies = quater*QUATER + dime*DIME + nickel*NICKEL + pennies*PENNY;

    real = 1*QUATER + 1*DIME + 1*NICKEL + 1*PENNY;
    printf("There are %d pennies.\n", pennies);
    printf("There are %d pennies.\n", real);
    return 0;
}