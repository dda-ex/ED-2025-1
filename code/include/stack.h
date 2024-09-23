/*
    stack.h
*/
#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

#include <list.h>

/*
    stack node
*/
typedef List Stack;

/*
    Public Interfaces
*/
#define stack_init list_init
#define stack_destroy list_destroy

int stack_push (Stack *stack, const void *data);
int stack_pop (Stack *stack, void **data);

/*
    Macros
*/
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define stack_size list_size

#endif
    