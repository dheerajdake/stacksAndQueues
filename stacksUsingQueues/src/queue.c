#include "queue.h"

void initializeQueue(struct queue *q)
{
	q->front = -1;
	q->rear = -1;
	q->count = 0;
	memset(q->array, 0, MAX_SIZE*sizeof(q->array[0]));
}

void printQueue(struct queue *q)
{
	for(int i=0; i<MAX_SIZE; i++){
		printf("%d ", q->array[i]);
	}
	printf("\n");
}

bool isFullQueue(struct queue *q)
{
	return (q->count == MAX_SIZE);
}

bool isEmptyQueue(struct queue *q)
{
	return (q->count == 0);
}

void enQueue(int num, struct queue *q)
{
	if (!isFullQueue(q)) {
		if (q->front == -1 && q->rear == -1) {
			q->front = 0;
			q->rear = MAX_SIZE - 1;
		}
		q->rear = (q->rear + 1)%MAX_SIZE;
		q->array[q->rear] = num;
		q->count++;
	} else {
		printf("Full queue. Cannot add %d\n", num);
	}
}

void deQueue(struct queue *q)
{
	if (!isEmptyQueue(q)) {
		q->array[q->front] = 0;
		q->front = (q->front + 1) % MAX_SIZE;
		q->count--;
	} else {
		q->front = -1;
		q->rear = -1;
		printf("Queue empty already\n");
	}
}

int getQueueSize(struct queue *q)
{
	int count = 0;
	if (q->front < q->rear) {
		count = q->rear - q->front + 1;
	} else if(q->front > q->rear) {
		count = MAX_SIZE + q->rear - q->front + 1;
	}
	return count;
}
