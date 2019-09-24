#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;


//pramp
string getShortestUniqueSubstring(const vector<char>& arr, const string &str){
	int arrSize = arr.size();
	int lengthStr = str.length();
	int min = INT_MIN;
	int uniqueCounter = 0;
	int headIndex = 0;
	unordered_map<char, int> countMap;
	string result = "";

	for (int i = 0; i < arrSize; i++) {
			countMap[arr[i]] = 0;
	}
	int mapSize = countMap.size();
	for (int tailIndex = 0; tailIndex < lengthStr; tailIndex++) {
		char tailChar = str[tailIndex];

		if (countMap.count(tailChar) == 0) continue;

		int tailCount = countMap[tailChar];

		if (tailCount == 0) {
			uniqueCounter = uniqueCounter + 1;
		}

		countMap[tailChar] = tailCount + 1;

		while (uniqueCounter == arrSize) {
			int tempLength = tailIndex - headIndex + 1;
			if (tempLength == arrSize)
				return str.substr(headIndex, tempLength);
			if (result == "" || tempLength < result.length())
				result = str.substr(headIndex, tempLength);

			char headChar = str[headIndex];
			if (countMap.count(headChar) != 0) {
				int headCount = countMap[headChar] - 1;
				if (headCount == 0) {
					uniqueCounter = uniqueCounter - 1;
				}
				countMap[headChar] = headCount;
			}
			headIndex++;
		}
	}
	return result;
}

int main() {
	std::cout << getShortestUniqueSubstring({ 'b' }, "ab") << std::endl;
	std::cout << getShortestUniqueSubstring({ 'a','a' }, "aa") << std::endl;
	std::cout << getShortestUniqueSubstring({ 'x','y','z' }, "xyyzyzyx") << std::endl;
	std::cout << getShortestUniqueSubstring({ 'x','y','z' }, "xayzcf") << std::endl;
	std::cout << getShortestUniqueSubstring({ 'x','y','z' }, "xyyzyyyzx") << std::endl;
	return 0;
}