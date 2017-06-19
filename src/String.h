/**
 * Copyright (c) 2017 Matheus Silva
 */

#include <stdlib.h>
#include "Config.h"

struct string
{
	int top;
	int size;
	int capacity;
	char *data;
};

typedef struct string String;

void string_init(String *str, bool appendnull)
{
	str->size = 0;
	str->capacity = STRING_INIT_SIZE;

	/* Allocate memory to the string */
	if(appendnull == true)
	{
		malloc();
	}
}
