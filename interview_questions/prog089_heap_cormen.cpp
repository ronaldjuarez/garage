#include <iostream>
#include <vector>

class Heap_Cormen {
public:
	void build_min_heap(std::vector<int> vector);
private:
	std::vector<int> arr;
	int parent(int i);
	int left(int i);
	int right(int);
	void min_heapify(int i);
};

void Heap_Cormen::build_min_heap(std::vector<int> vector)
{
	
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

int main() {
	return 0;
}