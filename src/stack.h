/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file Stack.h
 */

#include "Config.h"

/**
 * @brief Standard FILO stack with a traverse function to get any specific index.
 * @attention stack_traverse is a bit slower than stack_pop
 */

/**
 *	@struct __stack
 */
#ifndef __STACK_LIB__
struct __stack
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
  unsigned int size;
  /**
   * The capacity of the stack
   * @memberof stack
   */
  unsigned int capacity;
  /**
   *The actual data held in the stack
   * @memberof stack
   */
  int *data;
};

/**
 * @memberof stack
 */
typedef struct __stack stack;

/**
 * @brief Initialises the stack with a given size
 * @param[in] stack the stack to initialise
 * @param[in] size size to initialise the stack with
 * @memberof stack
 */
extern void stack_init(stack *in, int size);

/**
 * @brief Frees the memory allocated to the given stack
 * @param[in] stack
 * @memberof stack
 */
extern void stack_free(stack *in);

/**
 * @brief Sanitises the the memory previously occupied by the stack
 * @param stack to sanitise
 */
extern void stack_sanitised_free(stack *in);

/**
 * @brief Resizes the stack
 * @warning Only mess about with this function if you know what you are doing!
 * @param[in] stack the stack to resize
 * @param[in] size the size to go with the stack
 * @memberof stack
 */
#ifndef __NO_DYN_SIZE__
extern void __stack_resize(stack *in, unsigned int size);
#endif
/**
 * @brief Pushes a value into the stack
 * @param[in] stack a stack to push the value into
 * @param[in] data	any value that can be casted into an integer
 * @memberof stack
 */
extern void stack_push(stack *in, int data);

/**
 * @brief Pops a value from the stack
 * @memberof stack
 * @param[in] stack the stack to pop a value from
 * @return the topmost data on the stack
 */
extern int stack_pop(stack *in);

/**
 * @deprecated
 * @memberof stack
 * @param[in] stack
 * @return
 */
extern int stack_check(stack *in);

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
extern int getsizeof_stack(stack *in);

/**
 * @brief Merges two stacks together
 * @attention puts the output in the second stack
 * @memberof stack
 * @param[in] stack1 Stack to be merged onto
 * @param[out] stack2 Stack to be merged into
 */
extern void stack_merge(stack *stack1, stack *stack2);

/**
 * @brief Traverse the stack to the desired index
 * @param[in] stack a stack to traverse
 * @param[in] index index to traverse to
 * @return traversed index contents in case of error returns 0xBADBEEF
 */
extern int stack_traverse(stack *in, int index);
#define __STACK_LIB__
#endif
