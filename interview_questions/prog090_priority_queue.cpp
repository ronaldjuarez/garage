#include <iostream>
#include "helper.h"
#include <climits>

class PriorityQueue{
public:
    void insert(int value);
    int minimum(); // top
    int extract_min(); // pop
    void print();
private:
    void decrease_key(int i,int key); 
    Helper::Heap_Cormen h;
    int parent(int i);
};

void PriorityQueue::print(){
    h.print();
}

int PriorityQueue::parent(int i){
    return (i - 1) / 2;
}

int PriorityQueue::minimum(){
    return h.arr[0];
}

int PriorityQueue::extract_min(){
    int size = h.arr.size();
    if (size == 0) return -99999;
    int min = h.arr[0];
    h.arr[0] = h.arr[h.arr.size()-1];
    h.arr.pop_back();
    h.min_heapify(0);
    return min;
}

void PriorityQueue::decrease_key(int i,int key){
    if (key > h.arr[i])
        return;
    h.arr[i] = key;
    while (i > 0 && h.arr[parent(i)] > h.arr[i]){
        std::swap(h.arr[parent(i)], h.arr[i]);
        i = parent(i);
    }
}

void PriorityQueue::insert(int key){
    int newValue = INT_MAX;
    h.arr.push_back(newValue);
    decrease_key(h.arr.size()-1, key);
}
int main(){
    PriorityQueue h;
    h.insert(44);
    h.insert(33);
    h.insert(77);
    h.insert(11);
    h.insert(55);
    h.insert(88);
    h.insert(66);
    h.print();
    std::cout << h.extract_min() << std::endl;
    h.print();
    std::cout << h.extract_min() << std::endl;
    h.print();
    std::cout << h.extract_min() << std::endl;
    h.print();
    std::cout << h.extract_min() << std::endl;
    return 0;
}