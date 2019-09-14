#include <iostream>
#include <vector>
#include <limits>

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
	if (arr.size() == 0) return INT_MIN;
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