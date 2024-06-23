#include "../Algorithms/Heap/C++/heap.h"
#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

class Heap {
    private:
        int MaxHeapSize  = 1024;
        int currentHeapSize = 100;
        vector<int> heap;

    public:
        /* Constructor */
        Heap() : heap(currentHeapSize, -1) {}

        void increaseHeapSize(int value) {
            if(currentHeapSize + value > MaxHeapSize) {
                throw overflow_error("Heap size overflow: Attempt to increase heap size beyond maximum allowed limit");
            }
            currentHeapSize += value;
            heap.resize(currentHeapSize, -1);
            cout << "Heap size increased to " << currentHeapSize << endl;
        }
};