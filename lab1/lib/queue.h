#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>


template <class T>
struct item
{
    T* data;
    item* next;
};


template <class T>
class queue
{
    item<T>* tail;
    item<T>* head;
public:
    queue()
    {
        head = tail = NULL;
    }

    void push(T* item)
    {

    }

    T* pop()
    {
        return head;
    }

    bool empty()
    {
        return true;
    }



};

#endif // QUEUE_H
