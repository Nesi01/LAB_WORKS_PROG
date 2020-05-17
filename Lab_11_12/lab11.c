#include "lab11.h"


void do_lab11()
{
    int slen,i,number_of_lines;
    char **s2=NULL;
    comps *s3=NULL;
    char s1[256];
    char sep;
    FILE *df;
    head *head = NULL;

    head = create_head();
    sep=';';

    df=fopen("struct-data.csv","r");
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
        create_node(s3,head); //Creating first node

      //Splitting other strings, creating//
      //structures and making list      //
        for(i=0;i<number_of_lines-1;i++)
        {
            fgets(s1,256,df);
            slen=strlen(s1);
            s1[slen-1]='\0';
            slen=strlen(s1);

            s2=simple_split(s1,slen,sep);
            s3 = struct_fill(s2);       //Adding node in the
            add_last(head,s3);          //end of the list
        }
        if (fclose(df)==EOF) printf ("Error with closing file!");

      //Printing menu, where all other
      //main functions is being used
        menu(head);

      //Clearing memory
        if((head->cnt) == 1) free_head(head);
        else if((head->cnt) > 1) free_list(head);
        else if ((head->cnt) == 0) free(head);


    }
    else puts("File not found!");
}


void menu(head *head)
{
    int choice;

    do
    {
        printf("| |    Lab N 11   |\n");
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
            system("cls");
            break;
        default:
            system("cls");
            puts("Incorrect input!");
            break;
        }

    } while(choice!=0);
}
