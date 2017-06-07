/**
 * Copyright (c) 2017 Matheus Silva
 */

#pragma once
#include <stdlib.h>
#include "Config.h"
/**
 Stack data-type with the two stack operations push and pop, plus a stack_get_arbitrary operation to get the value at an arbitrary position on the stack
*/

/* Define the type*/
typedef struct
{
	int size;
	int capacity;
	int *data;
}Stack;
/* Initialise the stack */
void stack_init(Stack *stack)
{
	/* Initialise size and capacity */
	stack->size = 0;
	stack->capacity = STACK_INIT_SIZE;

	/* Allocate memory */
	stack->data = malloc(SIZE_OF_INT * stack->capacity);
}
/* Increase capacity by a given number defaults to 1 */
bool stack_resize(Stack *stack, int qty)
{
	stack->capacity += qty;
	if(stack->capacity > 0){
		stack->data = realloc(stack->data, SIZE_OF_INT * stack->capacity);
		return true;
	}
	else
    {
        return false;
    }
}
/** Get a value at an arbitrary index of the stack this is not part of the general concept of a stack and this function will be slower to run than pop */
int stack_get_arbitrary(Stack *stack, int index)
{
	if (index >= stack->size || index < 0)
	{
		return 0xBAD17;
	}
	return stack->data[index];
}
/* Push to the stack */
void stack_push(Stack *stack, int data)
{
	if(stack->size >= stack->capacity){
		stack_resize(stack, 1);
	}
	/* Add data to the top of the stack */
	stack->data[stack->size++] = data;
}
/* Pop from the stack */
int stack_pop(Stack *stack)
{
	int tmp = stack->data[stack->size];
	stack->size--;
	stack_resize(stack, -1);
	return tmp;
}
/* Gets the topmost item on the stack */
int stack_check(Stack *stack)
{
	return stack->data[stack->size];
}
/* Gets the size of the stack */
int getsizeof_stack(Stack *stack)
{
	return stack->size;
}
/* Free the memory allocated to the stack passed as argument */
void stack_free(Stack *stack)
{
	free(stack);
}
