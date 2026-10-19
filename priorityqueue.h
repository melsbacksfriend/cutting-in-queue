#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "maxheap.h"

template <class T>
class PriorityQueue {
public:
    PriorityQueue();
    void push(const T& key);
    T peek();
    T pop();
    std::size_t size();
    bool empty();

private:
    MaxHeap<T> heap;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
    heap = MaxHeap<T>();
}

template <class T>
void PriorityQueue<T>::push(const T& key)
{
    heap.push(key);
}

template <class T>
T PriorityQueue<T>::peek()
{
    return heap.peek();
}

template <class T>
T PriorityQueue<T>::pop()
{
    return heap.pop();
}

template <class T>
std::size_t PriorityQueue<T>::size()
{
    return heap.size();
}

template <class T>
bool PriorityQueue<T>::empty()
{
    return heap.empty();
}

#endif // PRIORITYQUEUE_H
