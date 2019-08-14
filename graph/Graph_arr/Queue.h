#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;
#define MAXVEX 100
#define TRUE 1
#define FALSE 0

typedef struct
{
    VertexType data;

}Node, *pNode;

/*循环队列,存放顶点下标*/
typedef struct
{
    int data[MAXVEX + 1];  //循环队列留一个空，标记队空队满
    int head;
    int tail;
}Queue, *pQueue;


void initQueue(pQueue pq);
Boolean isQueueEmpty(Queue q);
Boolean isQueueFull(Queue q);
Boolean enQueue(pQueue pq, int val);
Boolean deQueue(pQueue pq, int *pval);


Boolean isQueueEmpty(Queue q)
{
    return q.head == q.tail;
}

Boolean isQueueFull(Queue q)
{
    return (q.tail + 1) % MAXVEX == q.head;
}

Boolean enQueue(pQueue pq,int  val)
{
    if(isQueueFull(*pq))
    {
        printf("queue is full\n");
        return FALSE;
    }

    pq->data[pq->tail] = val;
    pq->tail = (pq->tail + 1) % MAXVEX;
    return TRUE;
}

Boolean deQueue(pQueue pq, int* val)
{
    if(isQueueEmpty(*pq))
    {
        printf("queue is empty\n");
        return FALSE;
    }
    *val = pq->data[pq->head];
    pq->head = (pq->head + 1) % MAXVEX;
    return TRUE;
}

void initQueue(pQueue pq)
{
    bzero(pq->data, MAXVEX * sizeof(int));
    pq->head = 0;
    pq->tail = 0;
}





#endif
