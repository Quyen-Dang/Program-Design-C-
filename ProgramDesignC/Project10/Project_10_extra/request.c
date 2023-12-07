/*
Request file contain the content of the functions that the user need to execute the
the program
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "request.h"
#include "readline.h"

struct request *append_to_list(struct request *list){
 struct request *current, *previous;
 struct request *last_cur, *last_pre;
 struct request *first_cur, *first_pre;
 struct request *new_node;
 new_node = malloc(sizeof(struct request));

    if(new_node == NULL)
    {
        printf("Database is full, can't add more children.\n");
        return list;
    }
//Ask the user to enter the classroom, child’s first name, and last name.
    printf("\nEnter classroom: ");
    read_line(new_node->classroom, ROOM_LEN + 1);
    printf("\nEnter child first name: ");
    read_line(new_node->first, NAME_LEN +1);
    printf("\nEnter child last name: ");
    read_line(new_node->last, NAME_LEN + 1);

//loop to order the list by checking if the child enter is before or after the others that already in order by classroom
    for(current = list, previous = NULL;
        current != NULL && strcmp(new_node->classroom, current ->classroom) > 0;
        previous = current, current = current-> next);
    //check if the child enter is already in the list
        if(current!= NULL && strcmp(new_node->classroom, current->classroom) == 0
			  && strcmp(new_node->first, current->first) == 0
			  && strcmp(new_node-> last, current-> last)== 0)
        {
            printf("\n%s %sis already on the waiting list for %s classroom.\n", new_node->first, new_node->last, new_node->classroom);
            free(new_node);
            return list;
        }
        //check if the classroom is the same
        if(current != NULL && strcmp(new_node->classroom, current-> classroom) == 0)
    	{
    		//order the child by last name
    		last_cur = current;
    		last_pre = previous;
            while(last_cur != NULL && strcmp(new_node->classroom, last_cur-> classroom) != 0);
            if(strcmp(new_node->last, last_cur ->last) > 0 )
            {
                last_pre = last_cur;
                last_cur = last_cur-> next;
            }

            printf("\nEnter phone number: ");
            read_line(new_node->phone, PHONE_LEN + 1);
            new_node->next = last_cur;

            if(last_pre == NULL)//list is empty, the new child enter become the first one in the list
                list = new_node;
            else//new child enter is insert to the list between previous and current
                last_pre-> next = new_node;
            return list;

        }

        if(current != NULL && strcmp(new_node->classroom, current-> classroom) == 0 && strcmp(new_node->last, current-> last) == 0)
        {
            first_cur = current;
    		first_pre = previous;
            while(first_cur != NULL && strcmp(new_node->classroom, first_cur-> classroom) != 0);
            if(strcmp(new_node->last, first_cur ->last) > 0 )
            {
                first_pre = first_cur;
                first_cur = first_cur-> next;
            }

            printf("\nEnter phone number: ");
            read_line(new_node->phone, PHONE_LEN + 1);
            new_node->next = first_cur;

            if(first_pre == NULL)//list is empty, the new child enter become the first one in the list
                list = new_node;
            else//new child enter is insert to the list between previous and current
                first_pre-> next = new_node;
            return list;
        }


    printf("\nEnter phone number: ");
    read_line(new_node->phone, PHONE_LEN + 1);

    new_node-> next = current;
    if(previous == NULL)//list is empty, the new child enter become the first one in the list
        list = new_node;
    else//new child enter is insert to the list between previous and current
        previous-> next = new_node;
    return list;
 }
 //function to update the classroom
void update(struct request *list)
{
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
    struct request *p;
    printf("\n%-15s %-20s %-20s %-20s\n", "Classroom","First Name", "Last name", "Phone Number");
    for(p = list; p != NULL; p = p->next)
    printf("%-15s %-20s %-20s %-20s\n", p->classroom, p->first, p->last, p->phone);
    printf("\n");
}

//deallocated the memory that allocated for the linked list.
void clearList(struct request *list) //
{
    struct request *p;
    while (list != NULL)
    {
        p = list;
        if(p != NULL)
            free(p);// clear the memory has p that no more use.
        list = list->next;
    }
}
struct request *delete_from_list(struct request *list){
    struct request *del_node, *current, *previous;
    del_node = malloc(sizeof(struct request));

//Ask the user to enter the classroom, child’s first name, and last name.
    printf("\nEnter classroom: ");
    read_line(del_node->classroom, ROOM_LEN + 1);
    printf("\nEnter child first name: ");
    read_line(del_node->first, NAME_LEN + 1);
    printf("\nEnter child last name: ");
    read_line(del_node->last, NAME_LEN + 1);

    //loop to check and return the position of the child to be deleted
    for(current = list, previous = NULL;
            current != NULL && (strcmp(del_node->classroom, current ->classroom)!= 0
                            || strcmp(del_node->last, current ->last)!= 0
                            || strcmp(del_node->last, current ->last)!= 0);
            previous = current, current = current-> next);

    if(current == NULL)//the child enter not in the list
    {
        printf("\n%s %s is not found on the waiting list for %s classroom.\n", del_node->first, del_node->last, del_node->classroom);
        return list;
    }

    if (previous == NULL)//the child enter in the first of the list
        list = list-> next;
    else//the child need to be delete is in any position
    {
        previous-> next = current-> next;
        free(current);
    }

    printf("\n%s %s is deleted on the waiting list for %s classroom.\n", del_node->first, del_node->last, del_node->classroom);
    return list;
}
