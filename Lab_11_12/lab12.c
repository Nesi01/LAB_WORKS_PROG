#include "lab12.h"


void do_lab12()
{
    int slen,i,number_of_lines, c;
    char **s2=NULL;
    comps *s3=NULL;
    char s1[256];
    char sep;
    FILE *df;
    head *head2 = NULL;
    head *rehead = NULL;

    head2 = create_head();
    rehead = create_head();
    sep=';';

    printf("Make data easy to check?\n");
    printf("[1] - Yes\n");
    printf("[2] - No\n");
    scanf("%d",&c);
    if (c==1) df=fopen("simple-data.csv","r");
    else df=fopen("struct-data.csv","r");
    //df=fopen("struct-data.csv","r");
    if(df!=NULL)
    {
        number_of_lines=0;
        while((fgets(s1,256,df))!=NULL) number_of_lines++;
        rewind(df);
        fgets(s1,256,df);
        slen=strlen(s1);
        s1[slen-1]='\0';
        slen=strlen(s1);

        s2=simple_split(s1,slen,sep);
        s3 = struct_fill(s2);
        create_node(s3,head2); //Creating first node

      //Splitting other strings, creating//
      //structures and making list      //
        for(i=0;i<number_of_lines-1;i++)
        {
            fgets(s1,256,df);
            slen=strlen(s1);
            s1[slen-1]='\0';
            slen=strlen(s1);

            s2=simple_split(s1,slen,sep);
            s3 = struct_fill(s2);
            add_signly(head2,s3);        //Adding node (circularize too!)
        }
        if (fclose(df)==EOF) printf ("Error with closing file!");

      //Printing menu, where all other
      //main functions is being used
        menu_for_12(head2, rehead);

      //Clearing memory
        if((head2->cnt) == 1) free_head(head2);
        else if((head2->cnt) > 1) free_list(head2);
        else if ((head2->cnt) == 0) free(head2);


    }
    else puts("File not found!");
}

void menu_for_12(head *head2, head *rehead)
{
    int choice;
    comps *str0=NULL;

    do
    {
        printf("| |    Lab N 12   |\n");
        printf("+-+---------------+\n");
        printf("|1| - Reshape     |\n");
        printf("|2| - Add node    |\n");
        printf("|0| - Exit        |\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            printf("Initial positions:\n");
            print_header();
            list_out(head2);

            reshape_list(head2,rehead);

            printf("\n\nReshaped positions:\n");
            print_header();
            list_out(rehead);
           // if((rehead->cnt) > 1) free_nodes_only(rehead);
            break;
        case 2:
            system("cls");
            printf("Adding node:\n");
            str0 = new_struct();
            add_signly(head2,str0);
            system("cls");
            printf("Node added\n");
            break;
        case 0:
            system("cls");
            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    } while(choice!=0);
}


void reshape_list(head *head2,head *rehead)
{
    node *center=NULL;
    node *temp=NULL;
    int i, half;

    temp = head2->first;
   // rehead = create_head();
    if(head2->cnt%2==0)
    {
        half = head2->cnt/2;
        for(i=0;i<half;i++) temp = temp->next;
        create_node(temp->data,rehead);
        for(i=1;i<head2->cnt;i++)
        {
            temp = temp->next;
            add_signly(rehead,temp->data);
        }
    }
    else
    {
        half = head2->cnt/2;
        for(i=0;i<half;i++) temp = temp->next;
        center = temp;
        temp = temp->next;
        create_node(temp->data,rehead);
        for(i=1;i<half;i++)
        {
            temp = temp->next;
            add_signly(rehead,temp->data);
        }
        add_signly(rehead,center->data);
        for(i=0;i<half;i++)
        {
            temp = temp->next;
            add_signly(rehead,temp->data);
        }
    }


}
