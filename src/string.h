/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file String.h
 * @brief String data-type to ease text handling
 */

#include "Config.h"
#include "stack.h"

/**
 * @struct __string
 * @brief Underlying data-type for the string library
 */
#ifndef __STRING_LIB__
struct __string
{
  stack data;
  unsigned int size;
  unsigned int capacity;
  int cpos;
};

typedef struct __string string;

/**
 *
 * @param in
 * @param nullterm
 * @param size
 */
extern void string_init(string *in, bool nullterm, int size);
/**
 *
 * @param in
 */
extern void string_free(string *in);
/**
 *
 * @param in
 */
extern void string_sanitised_free(string *in);
/**
 *
 * @param in
 * @param nsize
 */
extern void __string_resize(string *in, unsigned int nsize);
/**
 *
 * @param
 * @return
 */
extern string string_merge(string *a, string *b);
/**
 *
 * @param in
 * @param pos
 */
extern void string_set_cpos(string *in, int pos);
/**
 *
 * @param in
 * @param inc
 */
extern void __string_push(string *in, char **inc);

#ifndef flsp
#define flsp(X, Y) __string_push(X, Y)
#endif

#define __STRING_LIB__
#endif
