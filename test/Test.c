#include "../src/all.h"
#include "stdlib.h"
#include "stdio.h"

int main(int argc, char **argv) {
	printf("ForgeLib Test Tool (c) 2017 Matheus Xavier Silva All Rights Reserved\nInitialising testing\nProcceed?");
	getchar();
	stack test;
	stack_init(&test, 255);
	int a = 1;
	int lc = 0;
	for (int i = 0; i < 255; ++i) {
		stack_push(&test, a);
		printf("%04i    0x%08X : 0x%08X    \n", lc, i, a);
		lc++;
		a++;
	}
	printf("\n=============================================\n");
	printf("finished pushing stack top : %i | size: %i | capacity: %i | version: %s", test.top, test.size, test.capacity, LIB_VER);
	printf("\n---------------------------------------------\n");
	printf("started popping stack top : %i | size: %i | capacity: %i | version: %s | data at top: %i", test.top, test.size, test.capacity, LIB_VER, test.data[test.top]);
	printf("\n*********************************************\n");
	getchar();
	int i2 = 0;
	int b[test.size];
	lc = 0;
	while(test.size > 0)
	{
		b[i2] = stack_pop(&test);
		printf("%04i    0x%08X : 0x%08X    \n", lc, i2, b[i2]);
		++i2;
		lc++;
	}
	printf("finished popping stack top : %i | size: %i | capacity: %i | version: %s | data at top(expect garbage): %i", test.top, test.size, test.capacity, LIB_VER, test.data[test.top]);
	return 1;
}
