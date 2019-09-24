#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

//leetcode
string minWindow(string s, string t) {
	int arrSize = t.size();
	int lengthStr = s.length();
	int min = INT_MIN;
	int uniqueCounter = 0;
	int headIndex = 0;
	unordered_map<char, int> countMap;
	string result = "";

	for (int i = 0; i < arrSize; i++) {
			countMap[t[i]] = 0;
	}

	for (int tailIndex = 0; tailIndex < lengthStr; tailIndex++) {
		char tailChar = s[tailIndex];

		if (countMap.count(tailChar) == 0) continue;

		int tailCount = countMap[tailChar];

		if (tailCount == 0) {
			uniqueCounter = uniqueCounter + 1;
		}

		countMap[tailChar] = tailCount + 1;

		while (uniqueCounter == arrSize) {
			int tempLength = tailIndex - headIndex + 1;
			if (tempLength == arrSize)
				return s.substr(headIndex, tempLength);
			if (result == "" || tempLength < result.length())
				result = s.substr(headIndex, tempLength);

			char headChar = s[headIndex];
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
	std::cout << minWindow("ab", "b") << std::endl;
	std::cout << minWindow("aa", "aa") << std::endl;
	std::cout << minWindow("xyyzyzyx", "xyz") << std::endl;
	std::cout << minWindow("xayzcf", "xyz") << std::endl;
	std::cout << minWindow("xyyzyyyzx", "xyz") << std::endl;
	return 0;
}