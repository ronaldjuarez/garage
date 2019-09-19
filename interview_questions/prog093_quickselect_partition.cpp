#include <iostream>
#include <vector>
#include "helper.h"

int quickSelectPartition(std::vector<int> &v,int l, int r){
    int size = v.size();
    if (size == 0) return;

    int i = l, pivot = r;

    for (int j = l; j < pivot;j++){
        if(v[j] < v[pivot]) {
            std::swap(v[i],v[j]);
            i++;
        }
    }
    std::swap(v[i], v[pivot]);
    return i;
}

int main(){
    std::vector<int> v{7,2,1,8,6,3,5,4};
    quickSelectPartition(v,0,v.size()-1);
    print1D(v);
    return 0;    
}