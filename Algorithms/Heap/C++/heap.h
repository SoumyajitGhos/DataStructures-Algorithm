#ifndef HEAP_H
#define HEAP_H
#include <vector>

// Function declaration
void maxHeapify(std::vector<int> &heap, int currIndex, int heapSize);
void minHeapify(std::vector<int> &heap, int currIndex, int heapSize);

void heapSortA(std::vector<int> &heap); // Sorting Ascendingly
void heapSortB(std::vector<int> &heap); // Sorting Descendingly

void buildMaxHeap(std::vector<int> array);
void buildMinHeap(std::vector<int> array);

#endif // HEAP_H
