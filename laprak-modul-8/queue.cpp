#include "queue.h"

void createQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q)
{
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q)
{
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, infotype x)
{
    if (isFullQueue(Q))
    {
        cout << "Queue Penuh" << endl;
    }
    else
    {
        if (isEmptyQueue(Q))
        {
            Q.head = 0;
            Q.tail = 0;
        }
        else
        {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q)
{
    infotype elemen = -999;
    if (isEmptyQueue(Q))
    {
        cout << "Queue Kosong" << endl;
    }
    else
    {
        elemen = Q.info[Q.head];
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            for (int i = Q.head; i < Q.tail; i++)
            {
                Q.info[i] = Q.info[i + 1];
            }
            Q.tail--;
        }
    }
    return elemen;
}

void printInfo(Queue Q)
{
    if (isEmptyQueue(Q))
    {
        cout << "-1 - -1 \t | empty queue" << endl;
    }
    else
    {
        cout << " " << Q.head << " -  " << Q.tail << " \t | ";
        for (int i = Q.head; i <= Q.tail; i++)
        {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}