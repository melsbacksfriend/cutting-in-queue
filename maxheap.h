#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <stdexcept>

template <class T>
class MaxHeap {

public:
    MaxHeap();
    void push(const T& key);
    T peek();
    T pop();
    std::size_t size();
    bool empty();

private:
    std::vector<T> heap;
    std::size_t parent(std::size_t i);
    std::size_t left(std::size_t i);
    std::size_t right(std::size_t i);
    void bubbleUp(std::size_t i);
    void bubbleDown(std::size_t i);

};

template <class T>
MaxHeap<T>::MaxHeap()
{
    heap = std::vector<T>();
}

template <class T>
std::size_t MaxHeap<T>::parent(std::size_t i)
{
    return (i - 1) / 2;
}

template <class T>
std::size_t MaxHeap<T>::left(std::size_t i)
{
    return (2 * i) + 1;
}

template <class T>
std::size_t MaxHeap<T>::right(std::size_t i)
{
    return (2 * i) + 2;
}

template <class T>
void MaxHeap<T>::bubbleUp(std::size_t i)
{
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        std::swap(heap[parent(i)], heap[i]);
        i = parent(i);
    }
}

template <class T>
void MaxHeap<T>::bubbleDown(std::size_t i)
{
    std::size_t maxIndex = i;
    std::size_t l = left(i);
    std::size_t r = right(i);
    if (l < heap.size() && heap[l] > heap[maxIndex])
    {
        maxIndex = l;
    }
    if (r < heap.size() && heap[r] > heap[maxIndex])
    {
        maxIndex = r;
    }
    if (i != maxIndex)
    {
        std::swap(heap[i], heap[maxIndex]);
        bubbleDown(maxIndex);
    }
}

template <class T>
void MaxHeap<T>::push(const T& key)
{
    heap.push_back(key);
    bubbleUp(heap.size() - 1);
}

template <class T>
T MaxHeap<T>::peek()
{
    if (heap.empty()) throw std::underflow_error("Heap is empty");
    return heap[0];
}

template <class T>
T MaxHeap<T>::pop()
{
    if (heap.empty()) throw std::underflow_error("Heap is empty");
    T maxVal = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) bubbleDown(0);
    return maxVal;
}

template <class T>
std::size_t MaxHeap<T>::size()
{
    return heap.size();
}

template <class T>
bool MaxHeap<T>::empty()
{
    return heap.empty();
}

#endif // MAXHEAP_H
