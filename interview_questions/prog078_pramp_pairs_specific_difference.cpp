#include <iostream>
#include <vector>
#include <map>

std::vector<std::vector< int> > findPairsWithGivenDifference(const std::vector<int> &arr, int k) {
	std::map<int, int> m;
	std::vector<std::vector<int> > result;
	int size = arr.size();

	for (int i = 0; i < size; i++) {
		m[arr[i] - k] = arr[i];
	}

	for (int i = 0; i < size; i++) {
		if (m.count(arr[i])) {
			std::vector<int> item;
			item.push_back(m[arr[i]]);
			item.push_back(arr[i]);
			result.push_back(item);
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