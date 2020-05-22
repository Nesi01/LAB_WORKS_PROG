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



void create_node(studs *data, head *head)
{
      node *temp=NULL;
      temp = (node *)malloc(sizeof(node));
      temp->data = (studs*)malloc(sizeof(studs));

      temp->next = NULL;
      temp->prev = NULL;
      head->first = temp;
      head->last = temp;
      head->cnt += 1;
      temp->data = data;
}


void print_header()
{
    printf("|%30s |%7s |%11s |\n","Surname","Group","Result");
    printf("+-------------------------------+--------+------------+\n");
}


void list_out(head *head, int ch)
{
    node *p;
      //int i;

    p = head->first;

    switch(ch)
    {
    case 0:
        while(p != NULL)
        {
            printf("|%30s |%7d |",
            p->data->name,
            p->data->group);
            if (p->data->result.pass==15) printf ("%11s |\n","Passed");
            else printf ("%11s |\n","Not passed");
            p = p->next;
        }
        break;
    case 1:
        while(p != NULL)
        {
            if (p->data->result.pass==15)
            {
                printf("|%30s |%7d |%11s |\n",
                p->data->name,
                p->data->group,"Passed");
            }
            p = p->next;
        }
        break;
    case -1:
        while(p != NULL)
        {
            if (p->data->result.pass!=15)
            {
                printf("|%30s |%7d |%11s |\n",
                p->data->name,
                p->data->group,"Not passed");
            }
            p = p->next;
        }
        break;
    default:
        puts("UNCKNOWN ERROR WITH OUTPUT");
        break;
    }
    printf("\n");
}

