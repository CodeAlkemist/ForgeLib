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

/**
 * @brief Standard FILO m_array_t with a traverse function to get any specific index.
 * @attention m_array_traverse is a bit slower than m_array_pop
 */

/**
 *	@struct __stack
 */
#ifndef __STACK_LIB__
struct __stack
{
  /**
   * To determine if it will be the first pop on the m_array_t, only mess with if you know what you are doing
   * @memberof m_array_t
   */
  bool_t popc;
  /**
   * Top of the m_array_t index use with @code m_array_t.data[m_array_t.top] @endcode
   * to get what's at the top of the m_array_t
   * @memberof m_array_t
   */
  int top;
  /**
   * The size of the m_array_t
   * @memberof m_array_t
   */
  unsigned int size;
  /**
   * The capacity of the m_array_t
   * @memberof m_array_t
   */
  unsigned int capacity;
  /**
   *The actual data held in the m_array_t
   * @memberof m_array_t
   */
  int *data;
};

/**
 * @memberof m_array_t
 */
typedef struct __stack m_array_t;

/**
 * @brief Initialises the m_array_t with a given size
 * @param[in] m_array_t the m_array_t to initialise
 * @param[in] size size to initialise the m_array_t with
 * @memberof m_array_t
 */
extern void m_array_init(m_array_t *in, int size);

/**
 * @brief Frees the memory allocated to the given m_array_t
 * @param[in] m_array_t
 * @memberof m_array_t
 */
extern void m_array_free(m_array_t *in);

/**
 * @brief Sanitises the the memory previously occupied by the m_array_t
 * @param m_array_t to sanitise
 */
extern void m_array_sanitised_free(m_array_t *in);

/**
 * @brief Resizes the m_array_t
 * @warning Only mess about with this function if you know what you are doing!
 * @param[in] m_array_t the m_array_t to resize
 * @param[in] size the size to go with the m_array_t
 * @memberof m_array_t
 */
#ifndef __NO_DYN_SIZE__
extern void __m_array_resize(m_array_t *in, unsigned int size);
#endif
/**
 * @brief Pushes a value into the m_array_t
 * @param[in] m_array_t a m_array_t to push the value into
 * @param[in] data	any value that can be casted into an integer
 * @memberof m_array_t
 */
extern void m_array_push(m_array_t *in, int data);

/**
 * @brief Pops a value from the m_array_t
 * @memberof m_array_t
 * @param[in] m_array_t the m_array_t to pop a value from
 * @return the topmost data on the m_array_t
 */
extern int m_array_pop(m_array_t *in);

/**
 * @deprecated
 * @memberof m_array_t
 * @param[in] m_array_t
 * @return
 */
extern int m_array_check(m_array_t *in);

/**
 * @deprecated Will be removed on next major, use:
 * @code
 * m_array_t.size
 * @endcode
 * instead
 * @param m_array_t
 * @return m_array_t size
 * @memberof m_array_t
 */
extern int getsizeof_stack(m_array_t *in);

/**
 * @brief Merges two stacks together
 * @attention puts the output in the second m_array_t
 * @memberof m_array_t
 * @param[in] stack1 Stack to be merged onto
 * @param[out] stack2 Stack to be merged into
 */
extern void m_array_merge(m_array_t *stack1, m_array_t *stack2);

/**
 * @brief Traverse the m_array_t to the desired index
 * @param[in] m_array_t a m_array_t to traverse
 * @param[in] index index to traverse to
 * @return traversed index contents in case of error returns 0xBADBEEF
 */
extern int m_array_traverse(m_array_t *in, int index);
#define __STACK_LIB__
#endif
