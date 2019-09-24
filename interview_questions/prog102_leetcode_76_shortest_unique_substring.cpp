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
	unordered_map<char, int> countStrMap;
	unordered_map<char, int> mapPat;
	string result = "";

	for (int i = 0; i < arrSize; i++) {
		if (mapPat.count(t[i]) == 0) {
			mapPat[t[i]] = 1;
		}
		else {
			mapPat[t[i]]++;
		}
	}

	for (int i = 0; i < arrSize; i++) {
		countStrMap[t[i]] = 0;
	}

	for (int tailIndex = 0; tailIndex < lengthStr; tailIndex++) {
		char tailChar = s[tailIndex];

		if (countStrMap.count(tailChar) == 0) continue;

		int tailCount = ++countStrMap[tailChar];

		if (mapPat[tailChar] >= tailCount) {
			uniqueCounter = uniqueCounter + 1;
		}

		while (uniqueCounter == arrSize) {
			int tempLength = tailIndex - headIndex + 1;
			if (tempLength == arrSize)
				return s.substr(headIndex, tempLength);
			if (result == "" || tempLength < result.length())
				result = s.substr(headIndex, tempLength);

			char headChar = s[headIndex];
			if (countStrMap.count(headChar) != 0) {
				int headCount = countStrMap[headChar] - 1;
				if (mapPat[headChar] > headCount) {
					uniqueCounter = uniqueCounter - 1;
				}
				countStrMap[headChar] = headCount;
			}
			headIndex++;
		}
	}
	return result;
}
int main() {
	std::cout << minWindow("acbbaca", "aba") << std::endl;
	std::cout << minWindow("this is a test string", "tist") << std::endl;
	std::cout << minWindow("ab", "b") << std::endl;
	std::cout << minWindow("aa", "aa") << std::endl;
	std::cout << minWindow("xyyzyzyx", "xyz") << std::endl;
	std::cout << minWindow("xayzcf", "xyz") << std::endl;
	std::cout << minWindow("xyyzyyyzx", "xyz") << std::endl;
	return 0;
}