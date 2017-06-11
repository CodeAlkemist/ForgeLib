/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file Stack.h
 */

#pragma once
#include <stdlib.h>
#include "Config.h"

/**
 * @brief Standard FILO stack with a traverse function to get any specific index.
 * @attention stack_traverse is a bit slower than stack_pop
 */

/**
 *	@struct stack
 */
struct stack
{
	/**
	 * To determine if it will be the first pop on the stack, only mess with if you know what you are doing
	 * @memberof stack
	 */
	bool popc;
	/**
	 * Top of the stack index use with @code stack.data[stack.top] @endcode
	 * to get what's at the top of the stack
	 * @memberof stack
	 */
	int top;
	/**
	 * The size of the stack
	 * @memberof stack
	 */
	int size;
	/**
	 * The capacity of the stack
	 * @memberof stack
	 */
	int capacity;
	/**
	 *The actual data held in the stack
	 * @memberof stack
	 */
	int *data;
};
/**
 * @memberof stack
 */
typedef struct stack Stack;

/**
 * @brief Initialises the stack with a given size
 * @param[in] stack the stack to initialise
 * @param[in] size size to initialise the stack with
 * @memberof stack
 */
void stack_init(Stack *stack, int size)
{
	/* Initialise size and capacity */
	stack->size = 1;
	stack->capacity = size;
	stack->top = 0;
	stack->popc = true;
	/* Allocate memory */
	stack->data = malloc(SIZE_OF_INT * stack->capacity);
}

/**
 * @brief Frees the memory allocated to the given stack
 * @param[in] stack
 * @memberof stack
 */
void stack_free(Stack *stack)
{
	free(stack);
}

/**
 * @brief Resizes the stack
 * @warning Only mess about with this function if you know what you are doing!
 * @param[in] stack the stack to resize
 * @param[in] size the size to go with the stack
 * @memberof stack
 */
void stack_resize(Stack *stack, int size)
{
	if(size < 1) return;
	stack->capacity += size;
	stack->data = realloc(stack->data, SIZE_OF_INT * stack->capacity);
}

/**
 * @brief Pushes a value into the stack
 * @param[in] stack a stack to push the value into
 * @param[in] data	any value that can be casted into an integer
 * @memberof stack
 */
void stack_push(Stack *stack, int data)
{
	if((stack->size + 1) >= stack->capacity){
		stack_resize(stack, 1);
	}
	stack->size++;
	/* Add data to the top of the stack */
	stack->data[stack->top++] = data;
}

/**
 * @brief Pops a value from the stack
 * @memberof stack
 * @param[in] stack the stack to pop a value from
 * @return the topmost data on the stack
 */
int stack_pop(Stack *stack)
{
	if(stack->popc)
	{
		stack->top--;
		stack->size--;
		stack->popc = false;
	}
	int tmp = stack->data[stack->top];
	stack->top--;
	stack->size--;
	return tmp;
}

/**
 * @deprecated
 * @memberof stack
 * @param[in] stack
 * @return
 */
int stack_check(Stack *stack)
{
	return stack->data[stack->top];
}

/**
 * @deprecated Will be removed on next major, use:
 * @code
 * stack.size
 * @endcode
 * instead
 * @param stack
 * @return stack size
 * @memberof stack
 */
int getsizeof_stack(Stack *stack)
{
	return stack->size;
}

/**
 * @brief Merges two stacks together
 * @attention puts the output in the second stack
 * @memberof stack
 * @param[in] stack1 Stack to be merged onto
 * @param[out] stack2 Stack to be merged into
 */
void stack_merge(Stack *stack1, Stack *stack2)
{
	if(stack1->size > 0)
	{
		while(stack1->size < 0)
		{
			stack_push(stack2, stack_pop(stack1));
		}
		stack_free(stack1);
	}
}

/**
 * @brief Traverse the stack to the desired index
 * @param[in] stack a stack to traverse
 * @param[in] index index to traverse to
 * @return traversed index contents in case of error returns 0xBADBEEF
 */
int stack_traverse(Stack *stack, int index, bool uso)
{
	if(index > stack->size || index < 0)
	{
		return 0xBADBEEF;
	}
	return stack->data[index];
}
