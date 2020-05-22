#ifndef READ_FROM_FILE_H_INCLUDED
#define READ_FROM_FILE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "adding.h"
#include "list.h"


void read_from_csv(head *head2);
char **simple_split(char *str, int length, char sep);
studs *struct_fill(char **str);



#endif // READ_FROM_FILE_H_INCLUDED
