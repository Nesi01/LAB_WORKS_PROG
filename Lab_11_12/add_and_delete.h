#ifndef ADD_AND_DELETE_H_INCLUDED
#define ADD_AND_DELETE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "struct_csv.h"


void add_signly(head *head, comps *data);
void add_info(head *head);
void add_first(head *head, comps *data);
void add_last(head *head, comps *data);
void delete_nodes(head *head);

#endif // ADD_AND_DELETE_H_INCLUDED
