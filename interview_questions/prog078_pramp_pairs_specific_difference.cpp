#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::map<int, int> m;
	std::vector<int> result;
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		m[nums[i]] = i;
	}

	for (int i = 0; i < size; i++) {
		int complement = target - nums[i];
		if (m.count(complement) && m[complement] != i) {
			result.push_back(i);
			result.push_back(m[complement]);
			break;
		}
	}
	return result;
}

void print(const std::vector<std::vector<int> > &arr){
    int rowSize = arr.size();
    int colSize = arr[0].size();

    for (int i = 0; i < rowSize; i++){
        for (int j = 0; j < colSize; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector<int> v{0,-1,-2,2,1};
    int k = 1;
    auto result = findPairsWithGivenDifference(v,k);
    print(result);
    return 0;
}