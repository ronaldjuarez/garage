#include <iostream>
#include <vector>
#include <algorithm>
#include <stack> 
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

int trap2(std::vector<int>& arr){
    if (arr.size() == 0) return 0;
    int size = arr.size();
    int ans = 0;
    std::vector<int> left_max(size);
    std::vector<int> right_max(size);
    
    left_max[0] = arr[0];
    for(int i = 1; i < size; i++){
        left_max[i] = std::max(arr[i], left_max[i-1]);
    }
    
    right_max[size-1] = arr[size-1];
    for(int i = size-2; i >=0; i--){
        right_max[i] = std::max(arr[i], right_max[i+1]);
    }

    for(int i = 1; i < size - 1 ; i++){
        ans += std::min(left_max[i], right_max[i]) - arr[i];
    }
    return ans;
}

int trap3(std::vector<int>& arr){
    std::stack<int> st;
    int size = arr.size();
    int ans = 0;
    for (int i = 0; i < size; i++){
        while (!st.empty() && arr[i] > arr[st.top()]){
            int top = st.top();
            st.pop();
            if (st.empty()) break;
            int dist = i - st.top() - 1;
            ans += dist * (std::min(arr[i], arr[st.top()]) - arr[top]);
        }
        st.push(i);
    }
    return ans;
}

int trap4(const std::vector<int> & arr){
    int size = arr.size();
    int left = 0, right = size - 1;
    int left_max = 0, right_max = 0;
    int ans = 0;
    while (left < right){
        if (arr[left] < arr[right]){
            if (arr[left] >= left_max){
                left_max = arr[left];
            }
            else{
                ans += left_max - arr[left];
            }
            left++;
        }
        else{
            if (arr[right] >= right_max){
                right_max = arr[right];
            }
            else{
                ans += right_max - arr[right];
            }
            right--;
        }
    }
    return ans;
}

int main(){
    std::vector<int> v1({0,1,0,2,1,0,1,3,2,1,2,1});
    std::vector<int> v2({4,3,2,1,2,3,2,1,3,4});
    std::cout << trap4(v1) << std::endl;
    std::cout << trap4(v2) << std::endl;
}