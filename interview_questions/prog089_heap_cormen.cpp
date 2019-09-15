#include <iostream>
#include <vector>

class Heap_Cormen {
public:
	void build_min_heap(std::vector<int> vector);
	void print();
private:
	std::vector<int> arr;
	int parent(int i);
	int left(int i);
	int right(int);
	void min_heapify(int i);
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

int main() {
	std::vector<int> v{44,33,77,11,88,66,55};
	Heap_Cormen h;
	h.build_min_heap(v);
	h.print();
	return 0;
}