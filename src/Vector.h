/**
 * @copyright Copyright (c) 2017 Matheus Xavier Silva
 * @author Matheus Xavier Silva
 * @file Vector.h
 */

#pragma once
#include <stdlib.h>
#include "Config.h"
/**
 Vector data-type
*/

/* Define the type*/
struct vector
{
	bool popc;
	int top;
	int size;
	int capacity;
	int *data;
};
typedef struct vector Vector;

/** Initialise the vector */
void vector_init(Vector *vector, int size)
{
	/* Initialise size and capacity */
	vector->size = 1;
	vector->capacity = size;
	vector->top = 0;
	vector->popc = true;
	/* Allocate memory */
	vector->data = malloc(SIZE_OF_INT * vector->capacity);
}

/** Free the memory allocated to the vector passed as argument */
void vector_free(Vector *vector)
{
	free(vector);
}

/** Increase capacity by a given number defaults to 1 */
void vector_resize(Vector *vector, int qty)
{
	vector->capacity += qty;
	vector->data = realloc(vector->data, SIZE_OF_INT * vector->capacity);
}
/** Push to the vector */
void vector_push(Vector *vector, int data)
{
	if((vector->size + 1) >= vector->capacity){
		vector_resize(vector, 1);
	}
	vector->size++;
	/* Add data to the top of the vector */
	vector->data[vector->top++] = data;
}
/** Pop from the vector */
int vector_pop(Vector *vector)
{
	if(vector->popc)
	{
		vector->top--;
		vector->size--;
		vector->popc = false;
	}
	int tmp = vector->data[vector->top];
	vector->top--;
	vector->size--;
	return tmp;
}
/** Gets the topmost item on the vector */
int vector_check(Vector *vector)
{
	return vector->data[vector->top];
}
/** Gets the size of the vector */
int getsizeof_vector(Vector *vector)
{
	return vector->size;
}

/**
 * Merges vector1 into vector2
 * Returns: nothing the resulting vector in vector2
 */
void vector_merge(Vector *vector1, Vector *vector2)
{
	if(vector1->size > 0)
	{
		while(vector1->size < 0)
		{
			vector_push(vector2, vector_pop(vector1));
		}
		vector_free(vector1);
	}
}
