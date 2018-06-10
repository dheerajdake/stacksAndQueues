/*
 ============================================================================
 Name        : queuesUsingStacks.c
 Author      : Dheeraj
 Version     : 1.0.0
 Description : Queues using stacks
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct queue{
	struct stack s1;
	struct stack s2;
	int count;
};

void initializeQueue(struct queue *q);
void enQueue(int num, struct queue *q);
void deQueue(struct queue *q);
bool isQueueFull(struct queue *q);
bool isQueueEmpty(struct queue *q);
void printQueue(struct queue *q);

int main(void) {
	printf("Queues using stacks\n");

	struct queue q;
	initializeQueue((&q));

	enQueue(12, &q);
	enQueue(2, &q);
	enQueue(6, &q);
	enQueue(8, &q);
	enQueue(96, &q);
	printQueue(&q);

	deQueue(&q);
	deQueue(&q);
	deQueue(&q);
	deQueue(&q);
	deQueue(&q);
	printQueue(&q);
	deQueue(&q);

	enQueue(12, &q);
	enQueue(2, &q);
	deQueue(&q);
	enQueue(12, &q);
	enQueue(2, &q);
	deQueue(&q);
	enQueue(12, &q);
	enQueue(2, &q);
	deQueue(&q);
	printQueue(&q);

	printf("END\n");
	return EXIT_SUCCESS;
}

void initializeQueue(struct queue *q)
{
	initializeStack(&q->s1);
	initializeStack(&q->s2);
}

bool isQueueFull(struct queue *q)
{
	return (q->count == MAX_SIZE);
}

bool isQueueEmpty(struct queue *q)
{
	return (q->count == 0);
}

void printQueue(struct queue *q)
{
	// Print non-empty stack from bottom to top
	if (!isQueueEmpty(q)) {
		if (!isStackEmpty(&q->s1)) {
			printStack(&q->s1);
		} else {
			printStack(&q->s2);
		}
		printf("\n");
	} else {
		printf("Cannot print an empty queue\n");
	}
}

void enQueue(int num, struct queue *q)
{
	// Add to non-empty stack. If both are empty choose one.
	// I'm choosing s1
	if (!isQueueFull(q)) {
		if (isStackEmpty(&q->s1) && isStackEmpty(&q->s2)) {
			push(num, &q->s1);
		} else if (!isStackEmpty(&q->s1)) {
			push(num, &q->s1);
		} else {
			push(num, &q->s2);
		}
		q->count++;
	} else {
		printf("Queue full. Can't add %d to queue.\n", num);
	}
}

void deQueue(struct queue *q)
{
	// Transfer the contents of non-empty stack into the empty stack
	// Pop the non-empty stack
	// Transfer the contents of non-empty stack into the empty stack
	if (!isQueueEmpty(q)) {
		if (!isStackEmpty(&q->s1)) {
			transferStackContents(&q->s1, &q->s2);
			pop(&q->s2);
			transferStackContents(&q->s2, &q->s1);
		} else {
			transferStackContents(&q->s2, &q->s1);
			pop(&q->s1);
			transferStackContents(&q->s1, &q->s2);
		}
		q->count--;
	} else {
		printf("Queue empty. Can't delete elements from queue\n");
	}
}
