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

#include "Config.h"

#ifndef __ARRAY_LIB__
struct __e_array_t
{
  bool_t popc;
  int top;
  unsigned int size;
  unsigned int capacity;
  int *data;
};

typedef struct __e_array_t e_array_t;

extern void e_array_init(e_array_t *in, int size);

extern void e_array_free(e_array_t *in);

extern void e_array_sanitised_free(e_array_t *in);

#ifndef __NO_DYN_SIZE__
extern void __e_array_resize(e_array_t *in, unsigned int size);
#endif

extern void e_array_push(e_array_t *in, int data);

extern int e_array_pop(e_array_t *in);

extern int e_array_check(e_array_t *in);

extern void e_array_merge(e_array_t *stack1, e_array_t *stack2);

extern int e_array_traverse(e_array_t *in, int index);
#define __ARRAY_LIB__
#endif
