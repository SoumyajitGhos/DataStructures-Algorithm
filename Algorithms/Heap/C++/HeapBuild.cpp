#include <bits/stdc++.h>
#include <iostream>
#include "heap.h"
using namespace std;

/*
1) We know that in a Heap all the leaf node always follows Heap property
2) So to start building a heap we have to start heapifying nodes near to leaft
   nodes since their left and right subtree(leaf nodes) are following the heap property and then heapifying internal nodes.
3) As this approach says in terms of an array we will heapifying from right to left
   and in terms of tree level, we will start from the bottom to the top of the Tree i.e Bottom-Up approach.
4) We know that in a heap the leaf node is from floor(n/2) to n-1 and the internal
   nodes is from 0 to floor(n/2)-1 for an heap of size 'n'
*/

void buildMaxHeap(vector<int> array) {
   for(int i = floor(array.size() / 2) - 1; i >= 0; i--) {
      maxHeapify(array, i, array.size());
   }
}

void buildMinHeap(vector<int> array) {
   for(int i = floor(array.size() / 2) - 1; i >= 0; i--) {
      maxHeapify(array, i, array.size());
   }
}