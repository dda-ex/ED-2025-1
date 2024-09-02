/*
    dlist.h
*/
#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/*
    Doubled linked list node
*/
typedef struct DListNode_ {
    void *data;
    struct DListNode_ *next;
    struct DListNode_ *prev;
} DListNode;

/*
    Struct for doubled linked list nodes
*/
typedef struct DList_ {
    int size;
    
    void (*destroy) (void *data);
    
    DListNode *head;
    DListNode *tail;
} DList;

/*
    Public Interfaces
*/
void dlist_init (DList *list, void (*detroy)(void *data));
void dlist_destroy (DList *list);

int dlist_ins_next (DList *list, DListNode *node, const void *data);
int dlist_ins_prev (DList *list, DListNode *node, const void *data);
int dlist_remove (DList *list, DListNode *node, void **data);

/*
    Macros
*/
#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)

#define dlist_is_head(node) ((node)->prev == NULL ? 1 : 0)
#define dlist_is_tail(node) ((node)->next == NULL ? 1 : 0)

#define dlist_data(node) ((node)->data)
#define dlist_next(node) ((node)->next)
#define dlist_prev(node) ((node)->prev)

#endif
    