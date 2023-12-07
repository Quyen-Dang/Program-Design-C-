/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written in order to manage the waiting list by storing      */
/*  requests for being added to the waiting list. Each request was stored       */
/*  with the classroom, the child’s first name, last name, and contact          */
/*  phone number.                                                               */
/*  Quyen Dang                                                                  */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROOM_LEN 100
#define NAME_LEN 30
#define PHONE_LEN 15

struct request{
	char classroom[ROOM_LEN];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char phone[PHONE_LEN+1];;

	struct request *next;
};


struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = NULL;
  printf("Operation Code:\na for appending to the list \nu for updating a book \np for printing the list \nq for quit.\n");
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
      case 'q': clearList(wait_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
//function to check the request for waiting list
struct request *append_to_list(struct request *list){

 //add your code
 struct request *current = NULL;
 struct request *new_node;
 new_node = malloc(sizeof(struct request));
 new_node->next = NULL;

    //Ask the user to enter the classroom, child’s first name, and last name.
    printf("\nEnter classroom: ");
    read_line(new_node->classroom, ROOM_LEN + 1);
    printf("\nEnter child first name: ");
    read_line(new_node->first, NAME_LEN + 1);
    printf("\nEnter child last name: ");
    read_line(new_node->last, NAME_LEN + 1);

 for(current = list; current != NULL; current = current->next)
 {
     //Check whether a request has already existed by classroom and the child’s first name and last name
     if (strcmp(current->classroom,new_node->classroom) == 0 && strcmp(current->first,new_node->first) == 0 && strcmp(current->last,new_node->last)==0)
     {
        //print the notice to request the update classroom
        printf("\n%s %s already on the waiting list for %s classroom.\n"
                   "To update the classroom, please enter code operation u.\n", new_node->first, new_node->last, new_node->classroom);
        return list;
     }
 }
 //the request has not exited, enter phone number
 printf("\nEnter phone number: \n");
 read_line(new_node->phone, PHONE_LEN + 1);


 if (list == NULL)//list is empty, return the pointer to the newly created linked list.
 {
     list = new_node;
     return list;
 }
 else//list is not empty, add the request to the end of the linked list and return the pointer to the linked list.
 {
     current = list;
     while (current->next != NULL)
        current = current->next;
     current-> next = new_node;
     return list;
 }
 return NULL;
 }

 //function to update the classroom
void update(struct request *list)
{

  //add your code
    struct request *current = NULL;
    struct request *update_node;
    update_node = malloc(sizeof(struct request));
    char new_classroom[ROOM_LEN + 1];

    printf("\nEnter classroom: ");
    read_line(update_node->classroom, ROOM_LEN + 1);
    printf("\nEnter child first name: ");
    read_line(update_node->first, NAME_LEN + 1);
    printf("\nEnter child last name: ");
    read_line(update_node->last, NAME_LEN + 1);

    for (current = list; current != NULL; current = current->next)
    {
        //check the matching child and update the new classroom
        if (strcmp(current->classroom,update_node->classroom) == 0 && strcmp(current->first,update_node->first) == 0 && strcmp(current->last,update_node->last)==0)
        {
            printf("\n%s %s is found on the waiting list for %s classroom.\n"
                    "Please enter the new classroom to update: \n", update_node->first, update_node->last, update_node->classroom);
            read_line(new_classroom, ROOM_LEN + 1);
            strcpy(current->classroom, new_classroom);
            return;
        }
    }
    //the child is not found, notice by message.
    printf("\n%s %s is not found on the waiting list for %s classroom.\n", update_node->first, update_node->last, update_node->classroom);
}

//function to print the waiting list at that time
void printList(struct request *list){

  //add your code
    struct request *p;
    printf("\n%-15s %-20s %-20s %-20s\n", "Classroom","First Name", "Last name", "Phone Number");
    for(p = list; p != NULL; p = p->next)
    printf("%-15s %-20s %-20s %-20s\n", p->classroom, p->first, p->last, p->phone);
    printf("\n");
}

//deallocated the memory that allocated for the linked list.
void clearList(struct request *list) //
{

 //add your code
    struct request *p;
    while (list != NULL)
    {
        p = list;
        if(p != NULL)
            free(p);// clear the memory has p that no more use.
        list = list->next;
    }
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;

   }
   str[i] = '\0';
   return i;
}
