/*
 * stack.h
 *
 *  Created on: Jun 9, 2018
 *      Author: Dheeraj
 */

#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "string.h"

#define MAX_SIZE 5

struct stack{
	int array[MAX_SIZE];
	int top;
};

void initializeStack(struct stack *s);
void push(int num, struct stack *s);
void pop(struct stack *s);
void printStack(struct stack *s);
bool isStackEmpty(struct stack *s);
bool isStackFull(struct stack *s);
void transferStackContents(struct stack *s1, struct stack *s2);

#endif /* STACK_H_ */
