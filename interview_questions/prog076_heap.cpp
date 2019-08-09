#include <iostream>
#include <vector>

class Heap{
    public: 
        void insert(int value);
        void remove(int value);
        void print();
    private:
        std::vector<int> arr;
        int parent(int i);
        void swap(int &a, int &b);
        int find(int value);
};

int Heap::parent(int i){
    return (i-1)/2;
}

void Heap::swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

void Heap::insert(int value){
    arr.push_back(value);
    int i = arr.size() - 1;
    while (i != 0 && arr[parent(i)] < arr[i]){
        swap(arr[parent(i)], arr[i]);
        i = parent(i);
    }
}

void Heap::print(){
    int size = arr.size();
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::remove(int value){
    
}

void Heap::remove(int value){
    int i = find(value);

}

int main(){
    Heap h;
    h.insert(44);
    h.insert(33);
    h.insert(77);
    h.insert(11);
    h.insert(55);
    h.insert(88);
    h.insert(66);
    h.print();  
    return 0;
}