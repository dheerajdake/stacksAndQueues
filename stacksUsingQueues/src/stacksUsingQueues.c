/*
 ============================================================================
 Name        : stacksUsingQueues.c
 Author      : Dheeraj
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Stacks using queues
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

struct stackUsingQueues{
	struct queue q1;
	struct queue q2;
	int count;
};

void initializeStack(struct stackUsingQueues *s);
void push(int num, struct stackUsingQueues *s);
void pop(struct stackUsingQueues *s);
void printStack(struct stackUsingQueues *s);
bool isStackEmpty(struct stackUsingQueues *s);
bool isStackFull(struct stackUsingQueues *s);

int main(void) {
	struct stackUsingQueues s;
	printf("Stacks using 2 Queues\n");
	initializeStack(&s);

	push(23, &s);
	push(3, &s);
	push(5, &s);
	push(223, &s);
	push(20, &s);
	printStack(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	push(80, &s);
	push(4, &s);
	push(0, &s);
	push(78, &s);
	pop(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	printStack(&s);
	push(98, &s);
	pop(&s);
	push(98, &s);
	pop(&s);
	push(98, &s);
	pop(&s);
	push(98, &s);
	pop(&s);
	push(98, &s);
	push(62, &s);
	push(61, &s);
	push(65, &s);
	pop(&s);
	push(42, &s);
	push(35, &s);
	printStack(&s);

	printf("\nEnd\n");
	return EXIT_SUCCESS;
}

void initializeStack(struct stackUsingQueues *s)
{
	initializeQueue(&(s->q1));
	initializeQueue(&(s->q2));
	s->count = 0;
}

bool isStackEmpty(struct stackUsingQueues *s)
{
	return (s->count == 0);
}

bool isStackFull(struct stackUsingQueues *s)
{
	return (s->count == MAX_SIZE);
}

void push(int num, struct stackUsingQueues *s)
{
	if (!isStackFull(s)) {
		// If both the queues are empty, choose any to start with
		// I'm choosing q1
		if (isEmptyQueue(&s->q1) && isEmptyQueue(&s->q2)) {
			enQueue(num, &s->q1);
			s->count++;
		} else {
			// Push into non-empty queue
			if (!isEmptyQueue(&s->q1)) {
				enQueue(num, &s->q1);
			} else {
				enQueue(num, &s->q2);
			}
			s->count++;
		}
	} else {
		printf("\nStack is full. Can't push %d\n", num);
	}
}

void pop(struct stackUsingQueues *s)
{
	// Remove from non-empty queue and push to empty queue
	// until there is one element. Then delete that last element
	if (!isStackEmpty(s)) {
		if (!isEmptyQueue(&s->q1)) {
			// Transfer elements from q1 to q2
			while(s->q1.count - 1 != 0) {
				int elem = s->q1.array[s->q1.front];
				deQueue(&s->q1);
				enQueue(elem, &s->q2);
			}

			// q1 has one element, pop it finally
			deQueue(&s->q1);
			s->count--;
		} else if(!isEmptyQueue(&s->q2)){
			// Transfer elements from q2 to q1
			while(s->q2.count - 1 != 0) {
				int elem = s->q2.array[s->q2.front];
				deQueue(&s->q2);
				enQueue(elem, &s->q1);
			}

			//q2 has one element, pop it finally
			deQueue(&s->q2);
			s->count--;
		}
	} else {
		printf("Cannot pop an empty stack\n");
	}
}

void printStack(struct stackUsingQueues *s)
{
	// Print from front till rear - Increasing order of stack
	if (!isStackEmpty(s)) {
		if (!isEmptyQueue(&s->q1)) {
			int f = s->q1.front;
			do{
				printf("%d ", s->q1.array[f]);
				f = (f+1)%MAX_SIZE;
			}while (f!= (s->q1.rear+1)%MAX_SIZE);
		} else {
			int f = s->q2.front;
			do{
				printf("%d ", s->q2.array[f]);
				f = (f+1)%MAX_SIZE;
			}while (f!= (s->q2.rear+1)%MAX_SIZE);
		}
	} else {
		printf("Can't print an empty stack\n");
	}
}
