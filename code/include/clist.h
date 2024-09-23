/*
    clist.h
*/
#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

/*
    Circular list node
*/
typedef struct CListNode_ {
    void *data;
    struct CListNode_ *next;
} CListNode;

/*
    Struct for circular list nodes
*/
typedef struct CList_ {
    int size;
    
    int (*match)(const void *key1, const void *key2);
    void (*destroy) (void *data);
    
    CListNode *head;
} CList;

/*
    Public interfaces
*/
void clist_init (CList *list, void (*detroy)(void *data));
void clist_destroy (CList *list);

int clist_ins_next (CList *list, CListNode *node, const void *data);
int clist_rem_next (CList *list, CListNode *node, void **data);

/*
    Macros
*/
#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)

#define clist_data(node) ((node)->data)
#define clist_next(node) ((node)->next)

#endif
    