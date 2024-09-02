/*
    list.h
*/
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/*
    Linked list node
*/
typedef struct ListNode_ {
    void *data;
    struct ListNode_ *next;
} ListNode;

/*
    Struct for linked list nodes
*/
typedef struct List_ {
    int size;
    
    void (*destroy) (void *data);
    
    ListNode *head;
    ListNode *tail;
} List;

/*
    Public Interfaces
*/
void list_init (List *list, void (*destroy)(void *data));
void list_destroy (List *list);

int list_ins_next (List *list, ListNode *node, const void *data);
int list_rem_next (List *list, ListNode *node, void **data);

/*
    Macros
*/
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)

#define list_is_head(list, node) ((node) == (list)->head ? 1 : 0)
#define list_is_tail(node) ((node)->next == NULL ? 1 : 0)

#define list_data(node) ((node)->data)
#define list_next(node) ((node)->next)

#endif
    