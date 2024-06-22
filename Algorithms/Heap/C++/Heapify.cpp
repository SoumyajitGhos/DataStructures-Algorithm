#include "heap.h"
#include <vector>
#include <iostream>
using namespace std;

/* We can heapify a node only if all elements in left and right subtrees are following heap property(maxHeap or meanHeap)
*/
void maxHeapify(vector<int> &heap, int currIndex, int heapSize) {
    int largestValue = currIndex;
    int leftChildIndex = 2*currIndex + 1;
    int rightChildIndex = 2*currIndex + 2;

    if(leftChildIndex < heapSize && heap[leftChildIndex] > heap[largestValue]) {
        largestValue = leftChildIndex;
    }
    if(rightChildIndex < heapSize && heap[rightChildIndex] > heap[largestValue]) {
        largestValue = rightChildIndex;
    }
    if(largestValue != currIndex) {
        // swapping the largest value with the parent's value
        swap(heap[currIndex], heap[largestValue]);

        // heapifying the changed value node
        maxHeapify(heap, largestValue, heapSize);
    }
}

void minHeapify(vector<int> &heap, int currIndex, int heapSize) {
    int leastValue = currIndex;
    int leftChildIndex = 2*currIndex + 1;
    int rightchildIndex = 2*currIndex + 2;

    if(leftChildIndex < heapSize && heap[leftChildIndex] < heap[leastValue]) {
        leastValue = leftChildIndex;
    }
    if(rightchildIndex < heapSize && heap[rightchildIndex] < heap[leastValue]) {
        leastValue = rightchildIndex;
    }
     // swapping the least value with the parent's value
    if(leastValue != currIndex) {
        swap(heap[currIndex], heap[leastValue]);

        // heapifying the changed value node
        minHeapify(heap, leastValue, heapSize);
    }
}
