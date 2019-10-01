#include <vector>
#include <iostream>
#include <climits>
#include <string>

void print1D(const std::vector<int> &v){
    int n = v.size();
    for (int e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void print2D(const std::vector<std::vector<std::string> >& m) {
	int nr = m.size();
	if (nr == 0) return ;
	int nc = m[0].size();

	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++) {
			std::cout << m[r][c] << "\t";
		}
		std::cout << std::endl;
	}
}
void print2D(const std::vector<std::vector<int> > &m){
    int nr = m.size();
    int nc = m[0].size();

    for (int r = 0; r < nr ; r++){
        for(int c = 0; c < nc; c++){
            std::cout << m[r][c] << "\t";
        }
        std::cout << std::endl;
    }
}

void print2DChar(const std::vector<std::vector<char> > &m) {
	int nr = m.size();
	int nc = m[0].size();

	for (int r = 0; r < nr; r++) {
		for (int c = 0; c < nc; c++) {
			std::cout << m[r][c] << "\t";
		}
		std::cout << std::endl;
	}
}

class Heap {
public:
	void insert(int value);
	void print();
	int top();
	int pop();
private:
	std::vector<int> arr;
	void heapify(int i);
	int parent(int i);
	int left(int i);
	int right(int i);
	void swap(int& a, int& b);
	void remove(int k);
};

int Heap::top() {
	return arr[0];
}
int Heap::pop() {
	if (arr.size() == 0) return -999999;
	int r = arr[0];
	remove(0);
	return r;
}

void Heap::remove(int k) {
	swap(arr[k], arr[arr.size() - 1]);
	arr.pop_back();
	while (k > 0 && arr[k] < arr[parent(k)]) {
		swap(arr[k], arr[parent(k)]);
		k = parent(k);
	}
	while (k < arr.size()) {
		int l = left(k);
		int r = right(k);
		int smallest;
		if (l < arr.size() && arr[k] > arr[l])
			smallest = l;
		else 
			smallest = k;
		if (r < arr.size() && arr[smallest] > arr[r])
			smallest = r;
		if (smallest != k)
			swap(arr[k], arr[smallest]);
		else
			break;
		k = smallest;
	}
}

void Heap::print() {
	int size = arr.size();
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int Heap::parent(int i) {
	return (i - 1) / 2;
}

int Heap::left(int i) {
	return 2 * i + 1;
}

int Heap::right(int i) {
	return 2 * i + 2;
}

void Heap::swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Heap::heapify(int i) {
	while (i > 0 && arr[i] < arr[parent(i)]) {
		swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}
}

void Heap::insert(int value) {
	arr.push_back(value);
	heapify(arr.size()-1);
}


class Heap_Cormen {
public:
	void build_min_heap(std::vector<int> vector);
	void print();
	std::vector<int> arr;
	void min_heapify(int i);
private:
	int parent(int i);
	int left(int i);
	int right(int);
};

void Heap_Cormen::build_min_heap(std::vector<int> v)
{
	arr.resize(v.size());
	for (int i = 0 ; i < v.size(); i++){
		arr[i] = v[i];
	}
	int size = arr.size();
	for (int i = size/2; i >= 0; i--){
		min_heapify(i);
	}	
}

int Heap_Cormen::parent(int i) {
	return (i - 1) / 2;
}

int Heap_Cormen::left(int i) {
	return 2 * i + 1;
}

int Heap_Cormen::right(int i) {
	return 2 * i + 2;
}

void Heap_Cormen::min_heapify(int i) {

	while (i > 0 && arr[i] < arr[parent(i)]) {
		std::swap(arr[i], arr[parent(i)]);
		i = parent(i);
	}

	while (i < arr.size()) {
		int l = left(i);
		int r = right(i);
		int smallest;
		if (l < arr.size() && arr[i] > arr[l]) {
			smallest = l;
		}
		else {
			smallest = i;
		}
		
		if (r < arr.size() && arr[r] < arr[smallest]) {
			smallest = r;
		}

		if (smallest != i) {
			std::swap(arr[i], arr[smallest]);
		}
		else {
			break;
		}
		i = smallest;
	}
}

void Heap_Cormen::print(){
	int size = arr.size();
	for (int i = 0; i < size; i++){
		std::cout << arr[i] << " " ;	
	}
	std::cout << std::endl;
}

class PriorityQueue{
public:
    void insert(int value);
    int minimum(); // top
    int extract_min(); // pop
    void print();
private:
    void decrease_key(int i,int key); 
    Heap_Cormen h;
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