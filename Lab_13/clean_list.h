#ifndef CLEAN_LIST_H_INCLUDED
#define CLEAN_LIST_H_INCLUDED
#include <stdlib.h>
#include "structs.h"


void free_head(head *q);
void free_node(node *temp);
void free_list(head *q);

#endif // CLEAN_LIST_H_INCLUDED
