#include <vector>
#include <iostream>

void insertionSort(std::vector<int> &v){
    int size = v.size();
    for (int i = 0; i < size ; i ++){
        int j = i-1;  
        int key = v[i];
        while ( j>=0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

void print(const std::vector<int> &v){
    int size = v.size();
    for(int i = 0; i < size ; i++){
        std::cout << v[i] << " " ;
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v = {7,8,5,2,4,6,3};
    insertionSort(v);
    print(v);
}