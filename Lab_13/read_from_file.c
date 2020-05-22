#include "read_from_file.h"




void read_from_csv(head *head2)
{
    int slen,i,number_of_lines;
    char **s2=NULL;
    studs *s3=NULL;
    char s1[256];
    char sep;
    FILE *df;

    sep=';';

    df=fopen("students-data.csv","r");
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
            add_in_order(head2,s3);
        }
        if (fclose(df)==EOF) printf ("Error with closing file!");
    }
    else puts("File not found!");
}


char **simple_split(char *str, int length, char sep)
{
    char **str_array=NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }

    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
        else
        {

            for(i=0;i<count;i++)
            {
                free(str_array[i]);
                str_array[i]=NULL;
            }
            free(str_array);
            str_array = NULL;
        }
     }
     return str_array;
}


studs *struct_fill(char **str)
{
    studs *str0=NULL;

    str0=(studs*)malloc(sizeof(studs));
    if(str0!=NULL)
    {
        str0->name=str[0];
        str0->group=atoi(str[1]);
        str0->result.marks.m1=atoi(str[2]);
        str0->result.marks.m2=atoi(str[3]);
        str0->result.marks.m3=atoi(str[4]);
        str0->result.marks.m4=atoi(str[5]);
    }
    return str0;
}
