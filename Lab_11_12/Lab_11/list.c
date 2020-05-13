#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"


head *create_head()
{
    head *ph=NULL;

    ph=(head*)malloc(sizeof(head));
    if(ph)
    {
        ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}



void create_node(comps *data, head *head)
{
      node *temp=NULL;
      temp = (node *)malloc(sizeof(node));
      temp->data = (comps*)malloc(sizeof(comps));

      temp->next = NULL;
      temp->prev = NULL;
      head->first = temp;
      head->last = temp;
      head->cnt += 1;
      temp->data = data;
}


void list_out(head *head)
{
      node *p;
      p = head->first;
      while(p != NULL){
            printf("|%30s |%10s |%5d |%16.2f |%6d |%5.1f |\n",
            p -> data -> name,
            p -> data -> type,
            p -> data -> year,
            p -> data -> cost,
            p -> data -> reviews,
            p -> data -> rating);
            p = p->next;
      }
      printf("\n");
}


void menu(head *head)
{
    int choice;

    do
    {
        printf("| |     Menu:     |\n");
        printf("+-+---------------+\n");
        printf("|1| - Show list   |\n");
        printf("|2| - Add node    |\n");
        printf("|3| - Delete nodes|\n");
        printf("|0| - Exit        |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:     //Shows list as a table
            system("cls");
            print_header();
            list_out(head);
            break;
        case 2:     //User inputs data for new node
            system("cls");
            add_info(head);
            break;
        case 3:
            system("cls");
            delete_nodes(head);

            break;
        case 0:

            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    } while(choice!=0);
}
