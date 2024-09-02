/*
    list.c
*/
#include <stdlib.h>
#include <string.h>

#include "list.h"

/*
    Initialize the list
*/
void list_init (List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;

    return;    
}

/*
    Destroying the list
*/
void list_destroy (List *list) {
    void *data;

    while (list_size(list) > 0) {
        if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL) {
            list->destroy(data);
        }
    }    
    memset(list, 0, sizeof(List));
    return;
}

/*
    Insert next node at the List
*/
int list_ins_next (List *list, ListNode *node, const void *data ) {
    ListNode    *new_node;

    if ((new_node = (ListNode *)malloc(sizeof(ListNode))) == NULL)
        return -1;

    new_node->data = (void *)data;

    // Handle insertion at head of the list
    if (node == NULL) {
        
        // Is empty the list?
        if (list_size(list) == 0)
            list->tail = new_node;

        // There are other nodes in the list
        // do an adjust of other nodes
        new_node->next = list->head;
        list->head = new_node;
        
    } else {
        // Handle insertion from somewhere other than at the head

        // If the node is insert in the 
        if (node->next == NULL)
            list->tail = new_node;

        // Between two nodes at the list
        // do an adjust of the other nodes
        new_node->next = node->next;
        node->next = new_node;
    }

    list->size++;

    return 0;
}

/*
    Remove Next node at the List
*/
int list_rem_next (List *list, ListNode *node, void **data) {
    ListNode *old_node;

    // Check if is not empty the list
    if (list_size(list) == 0)
        return -1;
    
    // Handle removal from head of the list 
    if (node == NULL) {
    
        *data = list->head->data;
        old_node = list->head;
        list->head = list->head->next;

        // Is the last node at the list?
        if (list_size(list) == 1)
            list->tail = NULL;

    } else {
        // Handle removal from somewhere other than at the 

        // Can not remove at the end of the list
        if (node->next == NULL)
            return -1;

        *data = node->next->data;
        old_node = node->next;
        node->next = node->next->next;

        // After remove the node, check if the next element is the tail and update it
        if (node->next == NULL)
            list->tail = node;
    }

    free(old_node);
    list->size--;

    return 0;
}
