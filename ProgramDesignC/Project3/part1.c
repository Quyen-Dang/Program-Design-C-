/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written by Quyen Dang in order to find the first index of the value in the array.           */
/*  The user would enter the length, elements of the array, and also the value wanted to find.                  */
/*  The search function would find if the value the user want to find is in the array.                          */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>

int search(int a[], int n, int value)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == value)
            return i;//the first index that has the value need to find
    }
    return -1;// there is no element could find in the array.
}
int main(void)
{
    int i, length, value;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int elements[length];

    printf("\nEnter the elements of the array: ");
    for (i = 0; i < length; i++)
        scanf("%d", &elements[i]);

    printf("\nEnter the value for searching: ");
    scanf("%d", &value);

    printf("\nOutput: %d", search(elements, length, value));//print out the first index of the element has the same value as searching.

    return 0;
}
