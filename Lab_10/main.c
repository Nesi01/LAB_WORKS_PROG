#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_csv.h"
#include "list.h"



int main()
{
    int slen,i,number_of_lines;
    char **s2=NULL;
    comps *s3=NULL;
    char s1[256];
    char sep;
    FILE *df;
    node *head = NULL;
    node *temp, *p;

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
        temp = create_node(s3);
        head = temp;
        for(i=0;i<number_of_lines-1;i++)
        {
            fgets(s1,256,df);
            slen=strlen(s1);
            s1[slen-1]='\0';
            slen=strlen(s1);

            s2=simple_split(s1,slen,sep);
            s3 = struct_fill(s2);
            p = create_node(s3);
            temp -> next = p;
            temp = p;
        }
        if (fclose(df)==EOF) printf ("Error with closing file!");


        menu(head);


    }
    else puts("File not found!");

    return 0;
}



