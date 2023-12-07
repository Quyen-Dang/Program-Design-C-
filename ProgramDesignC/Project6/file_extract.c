/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written to reads the content of the file and extract the first letter of each word,     */
/*  then writes the resulting message to a file with the same name but an added extension of .dcf.          */
/*  Open the file for reading, store the content of file open to the temporary string, separate word from   */
/*  string and store in a 2-dimensional array. Then use a function to get only the first character of each  */
/*  word and write to the output file.                                                                      */
/*  Quyen Dang.                                                                                             */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 100
#define NAME_LEN 100
#define N 1000

void extract(char words[][WORD_LEN + 1], int num_words, char *result);

int main(void)
{
    char input[N][WORD_LEN+1];
    char buffer[N + 1];
    int i = 0, j = 0;
    FILE *rFile = NULL;
    char file_name[NAME_LEN + 1];
    char result[N + 1];

    printf("Enter the file name: ");
	scanf("%s",&file_name);//get file name input

    rFile = fopen(file_name, "r"); //open file name enter to read
    while(fgets(buffer,sizeof(buffer),rFile))//get the content of file enter to string buffer
    {
      char *p = strtok(buffer," ");//function that separate the word before space character and store to buffer
      while(p != NULL)
      {
         strcpy(input[i],p);// copy the word to array input
         i++;
         p = strtok(NULL," ");//
         j++;
      }
    }

    FILE *wFile = NULL;
    wFile = fopen(strcat(file_name, ".dcf"), "w"); //create and write on new file from the file name enter
    printf("\nOutput file name: %s\n", file_name);
    extract(input,j,result);//call the function to extract the first character of each string word.
    fprintf(wFile,"%s",result); //write the content on the file open for writing

    //closing files
    fclose(wFile);
    fclose(rFile);
    return 0;
}
void extract (char words[][WORD_LEN + 1], int num_words, char *result)
{
    int i;
    for (i = 0; i < num_words; i ++)
    {
        result[i] = words [i][0];//only take the first character of each string.
    }
}
