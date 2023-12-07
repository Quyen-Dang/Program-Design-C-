/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This is program is written in order to accept as command line arguments the sign of a math      */
/*  operation (+, -, x, or /) and two integer numbers, and displays the result of the operation.    */
/*  The user enter the file, the operation letter, and two integers for the calculation.            */
/*  The output will be the calculation of the math operate that the user enter.                     */
/*  Quyen Dang.                                                                                     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    int number1, number2, result;
    char operation[10];

    //get operator letter
    strcpy (operation, argv[1]);
    //get the integer from the string entered
    number1 = atoi (argv[2]);
    number2 = atoi (argv[3]);

    //set the case of operator letter for calculation
    switch (operation[0])
    {
        case '+': result = number1 + number2;//sum
                  break;
        case '-': result = number1 - number2;//subtract
                  break;
        case 'x': result = number1 * number2;// multiple
                  break;
        case '/': result = number1 / number2;//divide
                  break;
        default: printf("Invalid option. +, -, x, or / followed by two operands.\n");
                 return 0;
    }

    printf("Output: %d\n", result);
    return 0;
}
