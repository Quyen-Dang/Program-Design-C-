/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written in order to encrypt a number by replacing each digit of the number with another digit,  */
/*  and swap the position of the number. A number be entered would be replaced with another number by the function  */
/*  (digit + 6) % 10. Then, the value of number exchanged to the new number. Last, print out the digits of the      */
/*  number from last to first.                                                                                      */
/*  Quyen Dang.                                                                                                     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>

void swap(int *p, int *q);
void encrypt(int *a, int *b, int n);

int main()
{
    int i, number, number_digit;

    printf("Please enter number of digits of the input number: ");
    scanf("%d", &number_digit);

    int input[number_digit], output[number_digit];

    printf("\nPlease enter the number: ");
    for (i = 0; i < number_digit; i++) //store each digit in the array input.
    {
        scanf("%1d", &number);
        *(input + i) = number;
    }

    encrypt(input, output, number_digit);
    swap(&output[i], &input[i]);

    for (i = number_digit - 1; i >= 0; i--)
        printf("%d", *(output + i));

    return 0;
}

void encrypt(int *a, int *b, int n)
{
    int *c;
    for (c = a; c < n + a; c++) //replacing the input array (pointer a) by output array (pointer b)
    {
        *b = (*c + 6) % 10; // each digit of the new number is replacing by the remainder of the input digit plus six
        b++;
    }
}

void swap(int *p, int *q) //exchange the value of *p and *q
{
    int temp;

    temp = *p;
    *p = *q;
    *q = temp;

}

