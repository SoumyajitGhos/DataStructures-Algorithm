#include "../Algorithms/Heap/C++/heap.h"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

/****** MaxHeap Implementation ******/
class MaxHeap {
    private:
        int MaxHeapSize  = 1024;
        int currentHeapSize = 0;
        vector<int> heap;

    public:
        /* Constructor */
        MaxHeap() : heap(currentHeapSize) {}

        bool isOverflow() {
            if(currentHeapSize >= MaxHeapSize) {
                throw overflow_error("Heap size overflow: Attempt to increase heap size beyond maximum allowed limit");
                return true;
            }
            return false;  
        }

        void increaseHeapSize(int value) {
            if(currentHeapSize + value > MaxHeapSize) {
                throw overflow_error("Heap size overflow: Attempt to increase heap size beyond maximum allowed limit");
            }
            currentHeapSize += value;
            heap.resize(currentHeapSize);
            cout << "Heap size increased to " << currentHeapSize << endl;
        }

        /* Percolate-up algorithm */
        void percolateUp(int index) {
            while (index > 0 && heap[index] > heap[(index - 1)/2]) {
                swap(heap[index], heap[(index - 1)/2]);
                index = (index - 1)/2; // Current pointer moves to parent;
            }  
        }

        /* This function could also be called insertKey function */
        void push(int val) {
            if (isOverflow()) return;
            int currIndex = currentHeapSize;
            /* Inserting the value in the last node or the last position in array representation */
            heap[currIndex] = val;
            percolateUp(currIndex);
            currentHeapSize++;
        }

        /* For Heap, poping means poping the root node 
           This function could also be called extractMax/extractMin function
        */
        int pop() {
            if(currentHeapSize < 0) {
                throw underflow_error("Heap size underflow: Attempt to pop element while no element is persent inside the Heap");
                return -1;
            }
            int curr = 0; // The root node index
            int popped = heap[curr];
            heap[curr] = heap[currentHeapSize - 1]; // Copy last element to the root node
            currentHeapSize--;
            maxHeapify(heap, curr, currentHeapSize);
            return popped;
        }

        void show() {
            for(int i = 0; i < currentHeapSize; i++) cout<<heap[i] << " ";
            cout<<endl;
        }
};