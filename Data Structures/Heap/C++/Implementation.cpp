#include "../Algorithms/Heap/C++/heap.h"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

class Heap {
    private:
        int MaxHeapSize  = 1024;
        int currentHeapSize = 0;
        vector<int> heap;

    public:
        /* Constructor */
        Heap() : heap(currentHeapSize) {}

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

        /*Percolate-up algorithm*/
        void percolateUp(int index) {
            while (index > 0 && heap[index] > heap[(index - 1)/2]) {
                swap(heap[index], heap[(index - 1)/2]);
                index = (index - 1)/2; // Current pointer moves to parent;
            }  
        }

        void push(int val) {
            if (isOverflow()) return;
            int currIndex = currentHeapSize;
            /* Inserting the value in the last node or the last position in array representation */
            heap[currIndex] = val;
            percolateUp(currIndex);
            currentHeapSize++;
        }
};