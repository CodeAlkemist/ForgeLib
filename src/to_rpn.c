/**
 * Shunting yard algorithm Copyright (c) 2017 Matheus Silva
 * Algorithm to convert from infix notation to RPN (Postfix)
 * Takes 2 times the size of the input in ram to work
 */

#include "stack.h"
/**
 * Return the operator precedence
 */
int op_precedence(char op)
{
	if(op == 0x5E)
	{
		return 4;
	}
	else if(op == 0x2A || op == 0x2F)
	{
		return 3;
	}
	else if(op == 0x2B || op == 0x2D)
	{
		return 2;
	}
	return 0;
}

stack to_rpn(char **raw)
{
	stack out;
	stack_init(&out, (int)sizeof(raw));
	stack ops;
	stack_init(&ops, 10);
	/* Create error stack just in case but left it uninitialised */
	stack err;
	int pc = 0x0000;
	while (pc <= (int)sizeof(raw) - 1)
	{
		/* Get next char from the input */
		char cc = (int)raw[pc];
		/* Check for null */
		if (cc == 0x00) {

		}
		/* If it is a number push it to the output stack */
		if (cc >= 0x30 && cc <= 0x39)
		{
			stack_push(&out, cc);
		}
		/* If not check if it is an operator*/
		else if (cc >= 0x2A && cc <=0x2F)
		{
			if(ops.size > 0)
			{
				char tsop = stack_check(&ops);
				op_precedence(cc) > op_precedence(tsop) ? stack_push(&ops, cc) : stack_push(&out,stack_pop(&ops));
			}
			else
			{
				stack_push(&ops, cc);
			}
		}
		/* Check if it is left parenthesis*/
		else if(cc == 0x28)
		{
			/* While there are operators and they are not a right parenthesis keep popping operators */
			while(ops.size >= 0 && stack_check(&ops) != 0x29)
			{
				stack_push(&out, stack_pop(&ops));
			}
			if(ops.size == 0)
			{
				stack_init(&err, 10);
				stack_push(&err, 0xBAD1);
				return err;
			}
		}
		/* If it is the last character check if there are still any operators left in the stack and pop all of them */
		else if(pc == (int)sizeof(raw) - 1)
		{
			while(ops.size > 0)
			{
				stack_push(&out, stack_pop(&ops));
			}
		}
		/* Finally increment the counter */
		pc++;
	}
	return out;
}
