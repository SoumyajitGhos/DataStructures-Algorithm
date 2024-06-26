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

        /*  TC -> O(1)
            SC -> O(1)
        */
        bool isOverflow() {
            if(currentHeapSize >= MaxHeapSize) {
                throw overflow_error("Heap size overflow: Attempt to increase heap size beyond maximum allowed limit");
                return true;
            }
            return false;  
        }

        /*  TC -> O(value)
            SC -> O(value)
        */
        void increaseHeapSize(int value) {
            if(currentHeapSize + value > MaxHeapSize) {
                throw overflow_error("Heap size overflow: Attempt to increase heap size beyond maximum allowed limit");
            }
            currentHeapSize += value;
            heap.resize(currentHeapSize);
            cout << "Heap size increased to " << currentHeapSize << endl;
        }

        /* Percolate-up algorithm 
            TC -> O(log N)
            SC -> O(1)
        */
        void percolateUp(int index) {
            while (index > 0 && heap[index] > heap[(index - 1)/2]) {
                swap(heap[index], heap[(index - 1)/2]);
                index = (index - 1)/2; // Current pointer moves to parent;
            }  
        }

        /* This function could also be called insertKey function 
            TC -> O(log N)
            SC -> O(1)
        */
        void push(int val) {
            if (isOverflow()) return;
            int currIndex = currentHeapSize;
            /* Inserting the value in the last node or the last position in array representation */
            heap[currIndex] = val;
            percolateUp(currIndex);
            currentHeapSize++;
        }

        /* For Heap, poping means poping the root node 
           This function could also be called extractMax function
            TC -> O(log N)
            SC -> O(log N)
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

        /*  TC -> O(N)
            SC -> O(1)
        */
        void show() {
            for(int i = 0; i < currentHeapSize; i++) cout<<heap[i] << " ";
            cout<<endl;
        }

        /*  TC -> O(log N)
            SC -> O(1)
        */
        void increaseKey(int index, int value) {
            if(heap[index] > value) {
                throw invalid_argument("Attempt to increase the value of a node while providing smaller value");
            }
            heap[index] = value;
            /*Since the node's value increased it might get upwards in the heap level*/
            percolateUp(index);
        }

        /*  TC -> O(log N)
            SC -> O(log N)
        */
        void decreaseKey(int index, int value) {
            if(heap[index] < value) {
                 throw invalid_argument("Attempt to decrease the value of a node while providing bigger value");
            }
            heap[index] = value;
            /*Since the node's value decrease it might get downwards in the heap level*/
            maxHeapify(heap, index, currentHeapSize);
        }

        /*  TC -> O(1)
            SC -> O(1)
        */
        int getMax() {
            if(currentHeapSize > 0) return heap[0];
            return NULL;
        }
};