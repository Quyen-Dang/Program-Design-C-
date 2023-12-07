/*  *   *   *   *   **   *   *   *   *  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written in order to print out the range of character if the input has one.      */
/*  The range will be in the valid form [character-character] if the input contains one.            */
/*  The main function take input, read it, and call the replace function to print out the output.   */
/*  If there is a range in the output, print out the output that is the string from the input with  */
/*  the replace character that contains in the range. If there is no range in the input, print out  */
/*  no range message.                                                                               */
/*  Quyen Dang.                                                                                     */
/*  *   *   *   *   **   *   *   *   *  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000

int read_line(char *str, int n);
int replace(char *s1, char *s2);
void str_del(char *s, int n);
void str_ins(char *s, char *sub);
int main ()
{
    char input[N + 1], output[N + 1];
    int result;
    printf("Please enter the input: ");
    read_line(input,N);

    result = replace(input, output);
    printf("\nOutput: ");
    if (result == 1)
        printf("%s", output);
    else printf("There is no range in the input.");

    return 0;
}
// read the input line
int read_line(char *str, int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        {
            if (i < n)
            {
                *str++ = ch;
                i++;
            }
        }
        *str = '\0';
        return i;
}

int replace (char *s1, char *s2)
{
    int i, j, pos = -1;
    char add_str[30];

    //find the position of the range if exits
    for (i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '[' && s1[i + 2] == '-' && s1[i + 4] == ']')
            {
                pos = i;
                break;
            }

    }

    if(pos != -1)
    {
        int k = s1[pos + 3] - s1[pos + 1];
        for(j = 0; j <= k; j++)
        {
            add_str[j] = s1[pos + 1] + j; //replace the character contain in the range
        }
        add_str[k+1] = '\0';
        strcpy(s2,s1);//copy string s1 to s2 in order to modify it
        str_del(s2 + pos, 5);
        str_ins(s2 + pos, add_str);
        return 1;

    }
    else
        return 0;
}

//delete the range in the string to replace it
void str_del(char *s, int n)
{
    memmove(s, s + n, strlen(s+n)+1);
}
//edit and copy the new modified string to the range
void str_ins(char *s, char *sub)
{
    int len = strlen(sub);
    memmove(s + len, s, strlen(s)+1);
    strncpy(s, sub, len);
}







