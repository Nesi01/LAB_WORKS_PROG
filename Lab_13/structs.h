#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED



union total             //Union in 1 byte
{
    unsigned pass;      //==7 if all passed
    struct marks        //Four exams 1-passed,0-didn't
    {
        unsigned char m1:1;
        unsigned char m2:1;
        unsigned char m3:1;
        unsigned char m4:1;
    }marks;
};


struct students
{
    char *name;
    int group;
    union total result;
};
typedef struct students studs;


struct node{

    studs *data;
    struct node *next;
    struct node *prev;
};
typedef struct node node;


struct head {
    int cnt;
    struct node *first;
    struct node *last;
};
typedef struct head head;


#endif // STRUCTS_H_INCLUDED
