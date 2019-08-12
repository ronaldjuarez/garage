#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

int trap(std::vector<int>& arr){
    int ans = 0;
    int size = arr.size();

    for(int i = 0; i < size; i++){
        int max_left = 0, max_right = 0;
        for(int j = 0; j < i; j++){ 
            max_left = std::max(max_left, arr[j]);
        }
        
        for(int j = i + 1 ; j < size; j++){
            max_right = std::max(max_right, arr[j]);
        }
        ans += std::max(std::min(max_left, max_right) - arr[i],0);
    }
    return ans;
}

int main(){
    std::vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    print1D(v);
    int ans = trap(v);
    std::cout << ans << std::endl;
}