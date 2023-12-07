/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written in order to compare two same size arrays by determining the number of different elements    */
/*  between them. The user enter the size and elements of the two array, then the program print out the number of the   */
/*  different elements.                                                                                                 */
/*  Quyen Dang.                                                                                                         */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>

void count_diff (int *a1, int *a2, int n, int *num_diff);

int main()
{
    int i, element, length, num_diff;

    printf("Please enter the length of the array: "); //get the length of the two array
    scanf("%d", &length);

    int array1[length], array2[length];

    printf("\nPlease enter the elements of the first array: ");
    for(i = 0; i < length; i++) // get values for the array
    {
        scanf("%d", &element);
        *(array1 + i) = element;
    }

    printf("\nPlease enter the elements of the second array: ");
    for(i = 0; i < length; i++) // get values for the array
    {
        scanf("%d", &element);
        *(array2 + i) = element;
    }

    count_diff (array1, array2, length, &num_diff);

    //print out the number of the different elements between two arrays.
    if (num_diff == 0)
        printf("\nThe arrays are identical.\n");
    else
        printf("\nThe arrays are different by %d element(s).\n", num_diff);

    return 0;
}

void count_diff(int *a1, int *a2, int n, int *num_diff)
{
    int i, count = 0;

    // from the first to the last element of the array, compare the value
    for(i = 0; i < n; i++)
    {
         if (*(a1 + i) != *(a2 + i)) //elements of two arrays are different.
            count ++;
    }
    *num_diff = count;

}
