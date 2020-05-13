#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_csv.h"
#include "list.h"
#include "add_and_delete.h"



int main()
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


    }
    else puts("File not found!");

    return 0;
}
