/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file libforge.h
 */

#include "Stack.h"
#include "to_rpn.h"
#define LIB_VER 20170609

Stack to_rpn(char **raw);

void stack_init(Stack *stack, int size);

void stack_free(Stack *stack);

void stack_resize(Stack *stack, int qty);

void stack_push(Stack *stack, int data);

int stack_pop(Stack *stack);

int stack_check(Stack *stack);

int getsizeof_stack(Stack *stack);

void stack_merge(Stack *stack1, Stack *stack2);

int stack_traverse(Stack *stack);
