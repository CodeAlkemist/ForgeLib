/**
 * Copyright (c) 2017 Matheus Silva
 */

#ifndef NULL
/**
 * The standard NULL macro definition
 */
#define NULL ((void *) 0)
#endif

#ifndef __FLBOOL
typedef enum{
    true = 1,
    false = 0
}bool;
#define __FLBOOL
#endif
