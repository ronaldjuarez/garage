#include "helper.h"
#include <algorithm>

void heapsort(std::vector<int>& arr)
{
    std::make_heap(arr.begin(), arr.end());
    
    for (size_t i = arr.size() - 1 ; i >= 1 ; i++)
    {
        std::swap(arr[0], arr[i]);
        min_heapify(arr, 0, i);
    }
}

int parent(int i)
{
    return (i-1)/2;
}

int left(int i)
{
    return 2*i + 1;
}

int right(int i)
{
    return 2*i + 2;
}

void min_heapify(std::vector<int>& arr, int i, int heap_size)
{
    while (i>0 && arr[i] < arr[parent(i)])
    {
        std::swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }

    while (i < heap_size)
    {
        int l = left(i);
        int r = right(i);
        int smallest =  l < heap_size && arr[l] < arr[i]        ? l : i;
        smallest     =  r < heap_size && arr[r] < arr[smallest] ? r : smallest;

        if (smallest == i)
        {
            break;
        }

        std::swap(arr[smallest], arr[i]);
        i = smallest;
    }
}

int main()
{
    std::vector<int> arr{4,2,9,2,4,1,5,6};
    heapsort(arr);
    Helper::print1D<int>(arr);
}