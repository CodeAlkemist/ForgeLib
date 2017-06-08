/**
 * Copyright (c) 2017 Matheus Silva
 */

#include <stdlib.h>
#include "Config.h"

typedef struct
{
	int size;
	int capacity;
	char *data;
} String;

void string_init(String *str, bool appendnull)
{
	str->size = 0;
	str->capacity = STRING_INIT_SIZE;

	/* Allocate memory to the string */
	if(appendnull == true)
	{

	}
}
