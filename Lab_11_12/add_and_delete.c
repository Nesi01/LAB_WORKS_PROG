#include "add_and_delete.h"

//Used for SINGLY CURCULAR list
void add_signly(head *head, comps *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (comps*)malloc(sizeof(comps));
    temp->next = head->first;
    head->first = temp;
    head->cnt += 1;
    temp->data = data;
    head->last->next = temp; //Making circular list
}


void add_info(head *head)
{
    int choice;
    comps *str0=NULL;

    do
    {
        printf("| |Position to add|\n");
        printf("+-+---------------+\n");
        printf("|1| - First       |\n");
        printf("|2| - Last        |\n");
        printf("|0| - Exit        |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            printf("Adding node:\n");
            str0 = new_struct();
            add_first(head,str0);
            system("cls");
            printf("Added the first\n");
            choice = 0;
            break;
        case 2:     //User inputs data for new node
            system("cls");
            printf("Adding node:\n");
            str0 = new_struct();
            add_last(head,str0);
            system("cls");
            printf("Added the last\n");
            choice = 0;
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


void add_first(head *head, comps *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (comps*)malloc(sizeof(comps));
    temp->prev = NULL;
    temp->next = head->first;
    head->first->prev = temp;
    head->first = temp;
    head->cnt += 1;
    temp->data = data;
}


void add_last(head *head, comps *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (comps*)malloc(sizeof(comps));
    temp->next = NULL;
    temp->prev = head->last;
    head->last->next = temp;
    head->last = temp;
    head->cnt += 1;
    temp->data = data;
}


void delete_nodes(head *head)
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
        p1 = head->first;
        chk = 0;        //Check for appropriate data
        switch(choice)
        {
        case 1:
          //Deleting head until data isn't appropriate//
            while(p1->data->year==value)
            {
                p = p1->next;
                free(p1);
                p1 = p;
                p1->prev = NULL;
                head->first = p1;
                head->cnt -= 1;
                chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1->next;
                if(p->data->year==value)
                {
                    chk = 1;
                    p1->next = p->next;
                    if(p->next!=NULL) p->next->prev = p1;
                    else head->last = p1;
                    head->cnt -= 1;
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
            while(p1->data->cost==value)
            {
                p = p1->next;
                free(p1);
                p1 = p;
                p1->prev = NULL;
                head->first = p1;
                head->cnt -= 1;
                chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1->next;
                if(p->data->cost==value)
                {
                    chk = 1;
                    p1->next = p->next;
                    if(p->next!=NULL) p->next->prev = p1;
                    else head->last = p1;
                    head->cnt -= 1;

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
            while(p1->data->reviews==value)
            {
                p = p1->next;
                free(p1);
                p1 = p;
                p1->prev = NULL;
                head->first = p1;
                head->cnt -= 1;
                chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1->next;
                if(p->data->reviews==value)
                {
                    chk = 1;
                    p1->next = p->next;
                    if(p->next!=NULL) p->next->prev = p1;
                    else head->last = p1;
                    head->cnt -= 1;

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
            while(p1->data->rating==value)
            {
                p = p1->next;
                free(p1);
                p1 = p;
                p1->prev = NULL;
                head->first = p1;
                head->cnt -= 1;
                chk = 1;
            }

          //Goes through list and delete nodes//
          //With appropriate data             //
            do
            {
                p = p1->next;
                if(p->data->rating==value)
                {
                    chk = 1;
                    p1->next = p->next;
                    if(p->next!=NULL) p->next->prev = p1;
                    else head->last = p1;
                    head->cnt -= 1;

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
        case 0:

            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }
    }while(choice!=0);

}
