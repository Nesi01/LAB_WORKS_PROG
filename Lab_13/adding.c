#include "adding.h"



void add_in_order(head *head2, studs *data)
{
    node *temp=NULL;

    temp = head2->first;
    if (data->group < temp->data->group)/*--------------------*/add_first(head2,data);
    else if ((strcmp(data->name,temp->data->name) <= 0) &&
            (data->group == temp->data->group))/*-------------*/add_first(head2,data);
    else
    {
        while (temp!=NULL &&
              (data->group > temp->data->group))/*------------*/temp = temp->next;
        while (temp!=NULL &&
              (strcmp(data->name,temp->data->name) > 0) &&
              (data->group==temp->data->group))/*-------------*/temp = temp->next;
        if (temp!=NULL) add_before(head2,temp,data);
        else add_last(head2,data);
    }
}


void add_first(head *head, studs *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (studs*)malloc(sizeof(studs));
    temp->prev = NULL;
    temp->next = head->first;
    head->first->prev = temp;
    head->first = temp;
    head->cnt += 1;
    temp->data = data;
}


void add_last(head *head, studs *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (studs*)malloc(sizeof(studs));
    temp->next = NULL;
    temp->prev = head->last;
    head->last->next = temp;
    head->last = temp;
    head->cnt += 1;
    temp->data = data;
}


void add_before(head *head, node *nownode, studs *data)
{
    node *temp;

    temp = (node *)malloc(sizeof(node));
    temp->data = (studs*)malloc(sizeof(studs));
    temp->prev = nownode->prev;
    temp->next = nownode;
    nownode->prev->next = temp;
    nownode->prev = temp;
    temp->data = data;
    head->cnt += 1;

}



studs *new_struct()
{
    studs *str0=NULL;
    int mark;

    str0=(studs*)malloc(sizeof(studs));
    str0 -> name = (char*)malloc(sizeof(char)*32);
    if(str0!=NULL)
    {
        printf("Enter name: ");
        fgets((*str0).name,64,stdin);
        printf("Enter group: ");
        scanf("%d",&(*str0).group);
        printf("Enter marks\n[1] - Passed\n[0] - Not passed\n");
        do
        {
            printf("Enter 1'st mark: ");
            scanf("%d",&mark);
            if(mark!=0&&mark!=1) printf("Incorrect input! Needs 0 or 1!\n");
        }while (mark!=0&&mark!=1);
        str0->result.marks.m1 = mark;
        do
        {
            printf("Enter 2'nd mark: ");
            scanf("%d",&mark);
            if(mark!=0&&mark!=1) printf("Incorrect input! Needs 0 or 1!\n");
        }while (mark!=0&&mark!=1);
        str0->result.marks.m2 = mark;
        do
        {
            printf("Enter 3'rd mark: ");
            scanf("%d",&mark);
            if(mark!=0&&mark!=1) printf("Incorrect input! Needs 0 or 1!\n");
        }while (mark!=0&&mark!=1);
        str0->result.marks.m3 = mark;
        do
        {
            printf("Enter 4'th mark: ");
            scanf("%d",&mark);
            if(mark!=0&&mark!=1) printf("Incorrect input! Needs 0 or 1!\n");
        }while (mark!=0&&mark!=1);
        str0->result.marks.m4 = mark;
        str0->name[strlen(str0->name)-1]='\0';
    }
    return str0;
}
