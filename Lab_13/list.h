#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"



head *create_head();
void create_node(studs *data, head *head);
void print_header();
void list_out(head *head, int ch);
int is_pass(node *p);


#endif // LIST_H_INCLUDED
