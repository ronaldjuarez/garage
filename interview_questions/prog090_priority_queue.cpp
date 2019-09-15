#include <iostream>
#include "helper.h"

class PriorityQueue{
public:
    void insert(int value);
    int minimum(); // top
    int extract_min(); // pop
    int increase_key(); 
private:
    HeapCormen h;
};

int PriorityQueue::minimum(){
    return h.arr[0];
}

int PriorityQueue::extract_min(){
    int size = h.arr.size();
    if (size == 0) return -99999;
    int min = h.arr[0];
    h.arr.pop_back();
    h.min_heapify(0);
    return min;
}

int 
int main(){

    return 0;
}