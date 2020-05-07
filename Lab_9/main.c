#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bike_components {
    char *name;
    char *type;
    int year;
    float cost;
    int reviews;
    float rating;
};
typedef struct bike_components comps;

//Вывод хэдера
void print_header();

//Вывод строки данных
void struct_out(comps *str0);

//Очистка массива строк
void ClearStringArray(char **str, int n);

//Очистка памяти структуры
void ClearStructure(comps *str0);

//Разделить строку по разделителю
char **simple_split(char *str, int length, char sep);

//Заполнить структуру данными массива строк
comps *struct_fill(char **str);

//Выбор вывода по значениям
float YearValue(comps **str0, int i0);
float PriceValue(comps **str0, int i0);
float ReviewValue(comps **str0, int i0);
float RatingValue(comps **str0, int i0);

//Сортировка данных в обратном алфавитном порядке
void sort_realphabet(int n, comps **str0);

//Вывод данных со значением не больше среднего
void output_below_average(int n, comps **str0, float (*funcName)(comps**, int));


int main()
{
    comps **comp0=NULL;
    float (*kind[4])(comps**, int);
    int slen,i,n,option;
    char **s2=NULL;
    char s1[128];
    char sep;
    FILE *df;
    sep = ';';

    df=fopen("struct-data.csv","r");
    if(df!=NULL)
    {
        n=0;
        while((fgets(s1,128,df))!=NULL) n++;
        rewind(df);
        comp0=(comps**)malloc(n*sizeof(comps*));
        if(comp0!=NULL)
        {
            printf("%30s\n\n","Initial data:");
            print_header();
            for(i=0;i<n;i++)
            {
                fgets(s1,128,df);
                slen=strlen(s1);
                s1[slen-1]='\0';
                slen=strlen(s1);

                s2=simple_split(s1,slen,sep);
                if(s2!=NULL)
                {
                    comp0[i]=struct_fill(s2);
                    if(comp0[i]!=NULL) struct_out(comp0[i]);
                    else
                    {
                        puts("Structure not allocated!");
                        i=n;
                    }
                }
                else puts("Error at data reading!");
            }
        }
        else puts("No memory allocation!");
        fclose(df);

        if(comp0!=NULL)
        {
            kind[0] = YearValue;
            kind[1] = PriceValue;
            kind[2] = ReviewValue;
            kind[3] = RatingValue;
            option = 0;
            printf("\n\n");
            do
            {
                if(option>4) system("cls");
                printf("Show data with less [value] than average:\n");
                printf("1 - [year]\n");
                printf("2 - [price]\n");
                printf("3 - [amount of reviews]\n");
                printf("4 - [rating]\n");
                printf("Enter your choice: ");

                scanf("%d",&option);
            } while((option<1)||(option>4));

            sort_realphabet(n, comp0);
            printf("\n\n%30s\n\n","Sorted data:");
            print_header();
            output_below_average(n,comp0,kind[option-1]);
        }
        free(comp0);
        comp0=NULL;
    }
    else puts("File not found!");

    return 0;
}

void print_header()
{
    printf("|%30s |%10s |%5s |%9s |%4s|%5s|\n","Name of the bike component","Type","Year","Price(in pounds)","Reviews","Rating");
    printf("+-------------------------------+-----------+------+-----------------+-------+------+\n");
}

void struct_out(comps *str0)
{
    printf("|%30s |%10s |%5d |%16.2f |%6d |%5.1f |\n",
        str0->name,str0->type,str0->year,str0->cost,str0->reviews,str0->rating);
}

void ClearStringArray(char **str, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;

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
            ClearStringArray(str_array,count);
        }
     }
     return str_array;
}

comps *struct_fill(char **str)
{
    comps *str0=NULL;

    str0=(comps*)malloc(sizeof(comps));
    if(str0!=NULL)
    {
        str0->name=str[0];
        str0->type=str[1];
        str0->year=atoi(str[2]);
        str0->cost=atof(str[3]);
        str0->reviews=atoi(str[4]);
        str0->rating=atof(str[5]);
    }
    return str0;
}

float YearValue(comps **str0, int i0)
{
    return str0[i0]->year;
}

float PriceValue(comps **str0, int i0)
{
    return str0[i0]->cost;
}

float ReviewValue(comps **str0, int i0)
{
    return (int)str0[i0]->reviews;
}

float RatingValue(comps **str0, int i0)
{
    return (int)str0[i0]->rating;
}

void sort_realphabet(int n, comps **str0)
{
    comps *tmp_struct;
    int i, j, r;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            r = strcmp(str0[j]->type,str0[j+1]->type);
            if (r<=0)
            {
                tmp_struct=str0[j];
                str0[j]=str0[j+1];
                str0[j+1]=tmp_struct;
            }
        }
    }
}

void output_below_average(int n, comps **str0, float (*funcName)(comps**, int))
{
    int i;
    float avg;
    avg = 0;

    for(i=0;i<n;i++)
    {
        avg += funcName(str0,i);
    }
    avg /= n;
    for (i=0;i<n;i++)
    {
        if(funcName(str0,i)<=avg)
        {
            struct_out(str0[i]);
            ClearStructure(str0[i]);
        }
    }
}

void ClearStructure(comps *str0)
{
    free(str0->name);
    free(str0->type);
    str0->name=NULL;
    str0->type=NULL;
    free(str0);
    str0=NULL;
}
