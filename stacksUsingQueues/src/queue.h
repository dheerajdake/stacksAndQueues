#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5

struct queue{
	int array[MAX_SIZE];
	int front;
	int rear;
	int count;
};

void initializeQueue(struct queue *q);
void enQueue(int num, struct queue *q);
void deQueue(struct queue *q);
bool isFullQueue(struct queue *q);
bool isEmptyQueue(struct queue *q);
void printQueue(struct queue *q);
int getQueueSize(struct queue *q);

#endif
