#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "read_from_file.h"
#include "adding.h"
#include "list.h"
#include "menu.h"
#include "clean_list.h"



int main()
{
    head *head2 = NULL;

    head2 = create_head();
    read_from_csv(head2);


    menu(head2);

    //Clearing memory
    if((head2->cnt) == 1) free_head(head2);
    else if((head2->cnt) > 1) free_list(head2);
    else if ((head2->cnt) == 0) free(head2);


    return 0;
}
