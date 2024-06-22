#ifndef HEAP_H
#define HEAP_H
#include <vector>

// Function declaration
void maxHeapify(std::vector<int> &heap, int currIndex, int heapSize);
void minHeapify(std::vector<int> &heap, int currIndex, int heapSize);
#endif // HEAP_H
