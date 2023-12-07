/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This file contain the main function which mainly tell the program will do.      */
/*  The user would enter the code that call the function need to be used.           */
/*  Quyen Dang.                                                                     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
int main(void)
{
  char code;

  struct request *wait_list = NULL;
  printf("Operation Code:\na for appending to the list \nu for updating a book \np for printing the list \nq for quit \nd for delete from the list.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n');   /* skips to end of line */

    switch (code) {
      case 'a': wait_list = append_to_list(wait_list);
                break;
      case 'u': update(wait_list);
                break;
      case 'p': printList(wait_list);
                break;
      case 'd': wait_list = delete_from_list(wait_list);
                break;
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
