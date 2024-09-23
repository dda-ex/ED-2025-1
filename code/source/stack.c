/*
    stack.c
*/
#include <stdlib.h>

#include "list.h"
#include "stack.h"

/*
    Stack push
*/
int stack_push (Stack *stack, const void *data) {

    return list_ins_next(stack, NULL, data);
}

/*
    Stack Pop
*/
int stack_pop (Stack *stack, void **data) {
    
    return list_rem_next(stack, NULL, data);
}
