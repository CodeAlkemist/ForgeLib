/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file String.h
 * @brief String data-type to ease text handling
 * Documentation on the functions and supplemental details can be found in the corresponding header file
 */

#include "string.h"
#include <stdlib.h>

/*
 * internal function to the string
 * Defined here are the prototypes
 */



void string_init(string *in, bool nullterm, int size)
{
  in->size = 0;
  in->cpos = 0;
  in->capacity = 0;
  if(nullterm)
  {
      in->capacity++;
      in->size++;
      stack_init(&in->data, in->size);
      stack_push(&in->data, (int)"\00");
  }
  stack_init(&in->data, in->size);
}

void string_free(string *in)
{
  free(in);
}

void string_sanitised_free(string *in)
{
  stack_sanitised_free(&in->data);
  free(in);
}

void __string_resize(string *in, unsigned int nsize)
{
  in->capacity += nsize;
  __stack_resize(&in->data, nsize);
}
