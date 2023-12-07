/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written by Quyen Dang in order to delete all the instance value that the user want.         */
/*  The user would enter the length, elements of the array, and also the value wanted to be deleted.            */
/*  The search function would find if the value the user want to delete is in the array.                        */
/*  The delete function would reduce the length of the array, change the value of the elements after delete.    */
/*  Also, shift the value of other element to relocated them in the array. The delete function would return     */
/*  the new size of the array.                                                                                  */
/*  And the main function would call delete and print the output.                                               */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <stdio.h>

int search(int a[], int n, int value) //search function to find the index of the value need to be deleted
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == value)
            return i;
    }
    return -1;
}

int delete(int a[], int n, int value)
{
    int i, j, position;

    position = search(a, n, value);

    if (position != 1);//when the array has the value need to be deleted
    {
        for(i=0; i<n; i++)
        {
            if(a[i] == value)
            {
                for(j=i; j<n-1; j++)
                {
                    a[j] = a[j+1];//change the value of the next element to the place of the element need to be deleted
                }
                n--; //whenever the array has the value need to be deleted, the length is reduce one
                i--; //shift the array to the left
            }
        }
        return n; //the length of th array after deleted.
    }
}

int main(void)
{
    int i, length, value, new_size;

    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int elements[length];

    printf("\nEnter the elements of the array: ");
    for (i = 0; i < length; i++)
        scanf("%d", &elements[i]);

    printf("\nEnter the value for deleting: ");
    scanf("%d", &value);

    new_size = delete(elements, length, value);

    printf("\nOutput array: ");
    for (i = 0; i < new_size ; i++) //print the array after be deleted.
        printf("%d ",  elements[i]);


    return 0;
}
