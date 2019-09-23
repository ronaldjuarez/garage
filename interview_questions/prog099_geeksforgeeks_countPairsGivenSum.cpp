#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int countPairsGivenSum(const vector<int> &nums, int k) {
	int ans = 0;
	unordered_map<int, int> freqMap;

	int size = nums.size();

	for (int i = 0; i < size; i++) {
        if (freqMap.count(nums[i]) == 0){
            freqMap[nums[i]] = 1;
        }
        else{
            freqMap[nums[i]]++;
        }
	}

    for (auto num:nums){
        int comp = k - num;
        if (freqMap[comp] != 0){
            ans += freqMap[comp];
        }
        if (comp == num){
            ans--;
        }
    }
	return ans/2;
}

int getPairsCount(int arr[], int n, int sum) 
{ 
    unordered_map<int, int> m; 
  
    // Store counts of all elements in map m 
    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int twice_count = 0; 
  
    // iterate through each element and increment the 
    // count (Notice that every pair is counted twice) 
    for (int i=0; i<n; i++) 
    { 
        twice_count += m[sum-arr[i]]; 
  
        // if (arr[i], arr[i]) pair satisfies the condition, 
        // then we need to ensure that the count is 
        // decreased by one such that the (arr[i], arr[i]) 
        // pair is not considered 
        if (sum-arr[i] == arr[i]) 
            twice_count--; 
    } 
  
    // return the half of twice_count 
    return twice_count/2; 
} 
int main() {
    int arr[4] = { 2,2,2,7 };
	cout << countPairsGivenSum({ 1,5,7,-1 }, 6) << endl;
	cout << countPairsGivenSum({ 2,2,2,7 }, 4) << endl;
	cout << getPairsCount(arr, 4, 4) << endl;
	return 0;
}