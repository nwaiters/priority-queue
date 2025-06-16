/*
 * Purpose: This program inserts various values into a priority queue and performs insertion/extraction functions and returns the minimum value.
 */

#include <iostream>
#include "priorityQueue.h"
using namespace std;

//returns the parent of the index given
int priorityQueue::getParent(int index)
{
    return (index - 1) / 2;
}

//returns left child of the index given
int priorityQueue::getLeftChild(int index)
{
    return 2 * index + 1;
}

//returns right child of the index given
int priorityQueue::getRightChild(int index)
{
    return 2 * index + 2;
}

//swaps the given items
void priorityQueue::swap(int& item1, int& item2)
{
    int temp = item1;
    item1 = item2;
    item2 = temp;
}

//heapifies the given index
void priorityQueue::heapify(int index)
{
    int smallest = index;
    int left = getLeftChild(index);
    int right = getRightChild(index);
    
    if (left < size && data[left] < data[smallest])
    {
        smallest = left;
    }
    else
    {
        smallest = index;
    }
    
    if (right < size && data[right] < data[smallest])
    {
        smallest = right;
    }
    
    if (smallest != index)
    {
        swap(data[index], data[smallest]);
        heapify(smallest);
    }
}

//insert the given item into the queue
void priorityQueue::insert(int item)
{
    data[size] = item;
    int i = size;
    size ++;
    
    while (i > 0 && data[getParent(i)] > data[i])
    {
        swap(data[i], data[getParent(i)]);
        i = getParent(i);
    }
   
    cout << "After inserting " << item << " Priority Queue has" << endl;
    printArray(data);
}

//checks if the queue is empty or not
bool priorityQueue::empty() const
{
    if (size == 0)
    {
        return true;
    }
    
    return false;
}

//extracts and returns min value
int priorityQueue::extractMin()
{
    if (size == 0)
    {
        return -1;
    }
    //saves the root value
    int min = data[0];
    
    //exchanges root value with last item in the heap
    data[0] = data[size-1];
    size--;
    heapify(0);
    
    cout << "After extracting the minimum value Priority Queue has" << endl;
    printArray(data);
    
    return min;
}

//returns min value
int priorityQueue::min() const
{
    return data[0];
}

//prints data in the queue
void priorityQueue::printArray(int[])
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ", ";
    }
    cout << endl << endl;
}


priorityQueue::priorityQueue()
{
    data = new int [CAPACITY];
    size = 0;
}

priorityQueue::~priorityQueue()
{
    delete[] data;
}
