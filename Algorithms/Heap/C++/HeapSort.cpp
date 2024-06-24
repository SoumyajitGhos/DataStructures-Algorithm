#include "heap.h"
#include <vector>
#include <iostream>
using namespace std;

/*
    ## Assuming the heap is a valid maxHeap
    ## From maxHeap we can sort the array Ascendingly
    TC -> O(N log N)
    SC -> O(log N)
*/
void heapSortA(vector<int> &heap) {
    for(int i = heap.size() - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        // Every time the root node is heapifying but the size is changing.
        maxHeapify(heap, 0, i);
    }
}

/*
    ## Assuming the heap is a valid minHeap
    ## From minHeap we can sort the array Descendingly
    TC -> O(N log N)
    SC -> O(log N)
*/
void heapSortB(vector<int> &heap) {
    for(int i = heap.size() - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        // Every time the root node is heapifying but the size is changing.
        minHeapify(heap, 0, i);
    }
}