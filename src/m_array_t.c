/**
    Copyright 2017 Matheus Xavier Silva

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "m_array_t.h"
#include <stdlib.h>

#ifndef __ARRAY_LIB__
void m_array_init(m_array_t *in, int size)
{
  /* Initialise size and capacity */
  in->size = size;
  in->capacity = size;
  in->top = 0;
  in->popc = true;
  /* Allocate memory */
  in->data = malloc(SIZE_OF_INT * in->capacity);
}

void m_array_free(m_array_t *in)
{
  free(in);
}

void m_array_sanitised_free(m_array_t *in)
{
  while(in->top >= 0)
  {
    in->data[in->top] = 0xC1EA8;
    in->top--;
  }
  free(in);
}

#ifndef __NO_DYN_SIZE__
void __m_array_resize(m_array_t *in, unsigned int size)
{
  in->capacity += size;
  in->data = realloc(in->data, SIZE_OF_INT * in->capacity);
}
#endif

void m_array_push(m_array_t *in, int data)
{
  if((in->size + 1) >= in->capacity){
#ifndef __NO_DYN_ALOC__
      __m_array_resize(in, 1);
#else
      return 0x1AC0F;
#endif
  }
  in->size++;
  /* Add data to the top of the m_array_t */
  in->data[in->top++] = data;
}

int m_array_pop(m_array_t *in)
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

int m_array_check(m_array_t *in)
{
  return in->data[in->top];
}

int getsizeof_stack(m_array_t *in)
{
  return in->size;
}

void m_array_merge(m_array_t *stack1, m_array_t *stack2)
{
  if(stack1->size != 0)
  {
      m_array_push(stack2, m_array_pop(stack1));
      m_array_merge(stack1, stack2);
  }
  else
  {
      m_array_free(stack1);
  }
}

int m_array_traverse(m_array_t *in, int index)
{
  if(index > in->size || index < 0)
  {
    return 0xBADBEEF;
  }
  return in->data[index];
}
#define __STACK_LIB__
#endif