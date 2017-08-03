/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file Stack.h
 */

#include "Config.h"

/**
 * @brief Standard FILO stack_t with a traverse function to get any specific index.
 * @attention stack_traverse is a bit slower than stack_pop
 */

/**
 *	@struct __stack
 */
#ifndef __STACK_LIB__
struct __stack
{
  /**
   * To determine if it will be the first pop on the stack_t, only mess with if you know what you are doing
   * @memberof stack_t
   */
  bool popc;
  /**
   * Top of the stack_t index use with @code stack_t.data[stack_t.top] @endcode
   * to get what's at the top of the stack_t
   * @memberof stack_t
   */
  int top;
  /**
   * The size of the stack_t
   * @memberof stack_t
   */
  unsigned int size;
  /**
   * The capacity of the stack_t
   * @memberof stack_t
   */
  unsigned int capacity;
  /**
   *The actual data held in the stack_t
   * @memberof stack_t
   */
  int *data;
};

/**
 * @memberof stack_t
 */
typedef struct __stack stack_t;

/**
 * @brief Initialises the stack_t with a given size
 * @param[in] stack_t the stack_t to initialise
 * @param[in] size size to initialise the stack_t with
 * @memberof stack_t
 */
extern void stack_init(stack_t *in, int size);

/**
 * @brief Frees the memory allocated to the given stack_t
 * @param[in] stack_t
 * @memberof stack_t
 */
extern void stack_free(stack_t *in);

/**
 * @brief Sanitises the the memory previously occupied by the stack_t
 * @param stack_t to sanitise
 */
extern void stack_sanitised_free(stack_t *in);

/**
 * @brief Resizes the stack_t
 * @warning Only mess about with this function if you know what you are doing!
 * @param[in] stack_t the stack_t to resize
 * @param[in] size the size to go with the stack_t
 * @memberof stack_t
 */
#ifndef __NO_DYN_SIZE__
extern void __stack_resize(stack_t *in, unsigned int size);
#endif
/**
 * @brief Pushes a value into the stack_t
 * @param[in] stack_t a stack_t to push the value into
 * @param[in] data	any value that can be casted into an integer
 * @memberof stack_t
 */
extern void stack_push(stack_t *in, int data);

/**
 * @brief Pops a value from the stack_t
 * @memberof stack_t
 * @param[in] stack_t the stack_t to pop a value from
 * @return the topmost data on the stack_t
 */
extern int stack_pop(stack_t *in);

/**
 * @deprecated
 * @memberof stack_t
 * @param[in] stack_t
 * @return
 */
extern int stack_check(stack_t *in);

/**
 * @deprecated Will be removed on next major, use:
 * @code
 * stack_t.size
 * @endcode
 * instead
 * @param stack_t
 * @return stack_t size
 * @memberof stack_t
 */
extern int getsizeof_stack(stack_t *in);

/**
 * @brief Merges two stacks together
 * @attention puts the output in the second stack_t
 * @memberof stack_t
 * @param[in] stack1 Stack to be merged onto
 * @param[out] stack2 Stack to be merged into
 */
extern void stack_merge(stack_t *stack1, stack_t *stack2);

/**
 * @brief Traverse the stack_t to the desired index
 * @param[in] stack_t a stack_t to traverse
 * @param[in] index index to traverse to
 * @return traversed index contents in case of error returns 0xBADBEEF
 */
extern int stack_traverse(stack_t *in, int index);
#define __STACK_LIB__
#endif
