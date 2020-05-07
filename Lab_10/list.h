#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "struct_csv.h"


struct node{

    comps *data;
    struct node *next;
};
typedef struct node node;

node *create_node(comps *data);
void list_out(node **head);
void add(node **head, comps *data);
void menu(node *head);
void delete_nodes(node **head);

#endif // LIST_H_INCLUDED
