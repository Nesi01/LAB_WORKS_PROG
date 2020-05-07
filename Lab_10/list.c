#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"



node *create_node(comps *data)
{
      node *temp;
      temp = (node *)malloc(sizeof(node));
      temp -> data = data;
      temp -> next = NULL;
      return temp;
}


void list_out(node **head)
{
      node *p;
      p = *head;
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


void add(node **head, comps *data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp -> data = (comps**)malloc(sizeof(comps*));
    temp -> next = *head;
    temp -> data = data;
    *head = temp;
}

void menu(node *head)
{
    int choice;
    comps *str0=NULL;

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
            list_out(&head);
            break;
        case 2:     //User inputs data for new node
            system("cls");
            printf("Adding node:\n");
            str0 = new_struct();
            add(&head,str0);
            system("cls");
            break;
        case 3:
            system("cls");
            delete_nodes(&head);

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


void delete_nodes(node **head)
{
    int choice, chk;
    float value;
    node *p, *p1;


    do
    {
        printf("| | Choose field: |\n");
        printf("+-+---------------+\n");
        printf("|1| - Year        |\n");
        printf("|2| - Price       |\n");
        printf("|3| - Reviews     |\n");
        printf("|4| - Rating      |\n");
        printf("|0| - Back        |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        if(choice!=0)
        {
        printf("Enter value: ");
        scanf("%f", &value);
        }
        p1 = *head;
        chk = 0;        //Check for appropriate data
        switch(choice)
        {
        case 1:
          //Deleting head until data isn't appropriate//
            while((*head)->data->year==value)
            {   p1 = p1 -> next;
                free(head);
                        *head = p1;
                        chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1 -> next;
                if(p->data->year==value)
                {
                    chk = 1;
                    p1 -> next = p ->next;
                    free(p);
                }
                else
                {
                    p1 = p1 -> next;
                }
            }while (p1->next!=NULL);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }

            break;
        case 2:
          //Deleting head until data isn't appropriate//
            while((*head)->data->cost==value)
            {   p1 = p1 -> next;
                free(head);
                        *head = p1;
                        chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1 -> next;
                if(p->data->cost==value)
                {
                    chk = 1;
                    p1 -> next = p ->next;
                    free(p);
                }
                else
                {
                    p1 = p1 -> next;
                }
            }while (p1->next!=NULL);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }
            break;
        case 3:
          //Deleting head until data isn't appropriate//
            while((*head)->data->reviews==value)
            {   p1 = p1 -> next;
                free(head);
                        *head = p1;
                        chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1 -> next;
                if(p->data->reviews==value)
                {
                    chk = 1;
                    p1 -> next = p ->next;
                    free(p);
                }
                else
                {
                    p1 = p1 -> next;
                }
            }while (p1->next!=NULL);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }

            break;
        case 4:
          //Deleting head until data isn't appropriate//
            while((*head)->data->rating==value)
            {   p1 = p1 -> next;
                free(head);
                        *head = p1;
                        chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1 -> next;
                if(p->data->rating==value)
                {
                    chk = 1;
                    p1 -> next = p ->next;
                    free(p);
                }
                else
                {
                    p1 = p1 -> next;
                }
            }while (p1->next!=NULL);
            if (chk==0) printf("There is no such value\n\n");
            else
            {
                system("cls");
                printf("Nodes have been deleted\n");
                choice = 0;
            }

            break;
        case 0:

            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }
    }while(choice!=0);

}
