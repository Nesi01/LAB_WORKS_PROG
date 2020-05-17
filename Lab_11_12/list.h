#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structs.h"
#include "struct_csv.h"
#include "add_and_delete.h"


head *create_head();
void create_node(comps *data, head *head);
void list_out(head *head);

#endif // LIST_H_INCLUDED
