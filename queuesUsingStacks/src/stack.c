/*
 * stack.c
 *
 *  Created on: Jun 9, 2018
 *      Author: Dheeraj
 */

#include "stack.h"

void initializeStack(struct stack *s)
{
	memset(s->array, 0, sizeof(s->array[0])*MAX_SIZE);
	s->top = 0;
}

void push(int num, struct stack *s)
{
	if (!isStackFull(s)) {
		s->array[s->top] = num;
		s->top++;
	} else {
		printf("Stack already full. Cannot push %d\n", num);
	}
}

void pop(struct stack *s)
{
	if (!isStackEmpty(s)) {
		s->top--;
		s->array[s->top] = 0;
	} else {
		printf("Cannot pop an empty stack\n");
	}
}

void printStack(struct stack *s)
{
	if (!isStackEmpty(s)) {
		for(int i=0; i<MAX_SIZE; i++){
			printf("%d ", s->array[i]);
		}
	} else {
		printf("Cannot print an empty stack\n");
	}
}

bool isStackEmpty(struct stack *s)
{
	return (s->top == 0);
}

bool isStackFull(struct stack *s)
{
	return (s->top == MAX_SIZE);
}

void transferStackContents(struct stack *s1, struct stack *s2)
{
	// copy s1 into s2 and free s1
	if (isStackEmpty(s2)) {
		while(!isStackEmpty(s1)){
			s1->top--;
			push(s1->array[s1->top], s2);
		}
	}
	initializeStack(s1);
}
