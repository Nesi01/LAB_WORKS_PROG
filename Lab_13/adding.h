#ifndef ADDING_H_INCLUDED
#define ADDING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"


void add_in_order(head *head2, studs *data);
void add_first(head *head, studs *data);
void add_last(head *head, studs *data);
void add_before(head *head, node *nownode, studs *data);
studs *new_struct();


#endif // ADDING_H_INCLUDED
