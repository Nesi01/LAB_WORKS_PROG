#include "clean_list.h"


void free_head(head *q){
    free_node(q->first);
    q->first = NULL;
    q->last = NULL;
    free(q);
}


void free_node(node *temp){
    if((temp->next) != NULL) temp->next = NULL;


    free(temp->data->name);
    free(temp->data);
    free(temp);
}


void free_list(head *q){

    node *temp = NULL;
    node *p = NULL;
    int i,n;

    temp = q->first->next;
    n = q->cnt;
    free_head(q);

    //while((temp->next) != NULL){
    for(i=0;i<n-2;i++){
        p = temp;
        temp = temp -> next;
        free_node(p);
    }

    free_node(temp);
}
