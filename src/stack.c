/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file stack.c
 * Documentation on the functions and supplemental details can be found in the corresponding header file
 */

#include "stack.h"
#include <stdlib.h>

void stack_init(stack *in, int size)
{
  /* Initialise size and capacity */
  in->size = size;
  in->capacity = size;
  in->top = 0;
  in->popc = true;
  /* Allocate memory */
  in->data = malloc(SIZE_OF_INT * in->capacity);
}

void stack_free(stack *in)
{
  free(in);
}

void stack_sanitised_free(stack *in)
{
  while(in->top >= 0)
  {
    in->data[in->top] = 0xC1EA8;
    in->top--;
  }
  free(in);
}

#ifndef __NO_DYN_SIZE__
void __stack_resize(stack *in, unsigned int size)
{
  in->capacity += size;
  in->data = realloc(in->data, SIZE_OF_INT * in->capacity);
}
#endif

void stack_push(stack *in, int data)
{
  if((in->size + 1) >= in->capacity){
#ifndef __NO_DYN_ALOC__
      __stack_resize(in, 1);
#else
      return 0x1AC0F;
#endif
  }
  in->size++;
  /* Add data to the top of the stack */
  in->data[in->top++] = data;
}

int stack_pop(stack *in)
{
  if(in->popc)
  {
    in->top--;
    in->size--;
    in->popc = false;
  }
  int tmp = in->data[in->top];
  in->top--;
  in->size--;
  return tmp;
}

int stack_check(stack *in)
{
  return in->data[in->top];
}

int getsizeof_stack(stack *in)
{
  return in->size;
}

void stack_merge(stack *stack1, stack *stack2)
{
  if(stack1->size != 0)
  {
      stack_push(stack2, stack_pop(stack1));
      stack_merge(stack1, stack2);
  }
  else
  {
      stack_free(stack1);
  }
}

int stack_traverse(stack *in, int index)
{
  if(index > in->size || index < 0)
  {
    return 0xBADBEEF;
  }
  return in->data[index];
}