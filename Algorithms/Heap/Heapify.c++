#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
