#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minimumDeleteSum(string s1, string s2) {
	int s1Len = s1.length();
	int s2Len = s2.length();

	vector<vector<int> > minSumMemo(s1Len + 1, vector<int>(s2Len + 1, 0));

    for (int i = 1 ; i <= s1Len; i++){
        minSumMemo[i][0] = minSumMemo[i-1][0] + s1[i-1];
    }

    for ( int j = 1; j <= s2Len; j++){
        minSumMemo[0][j] =  minSumMemo[0][j-1] + s2[j-1];
    }

	for (int i = 1; i <= s1Len; i++) {
		for (int j = 1; j <= s2Len; j++) { 
            if (s1[i - 1] == s2[j - 1]) {
				minSumMemo[i][j] = minSumMemo[i - 1][j - 1];
			}
			else {
				minSumMemo[i][j] = std::min(s1[i-1] + minSumMemo[i - 1][j], s2[j-1] + minSumMemo[i][j - 1]);
			}
		}
	}
	return minSumMemo[s1Len][s2Len];
}


int main() {
	cout << minimumDeleteSum("sea", "eat") << endl;
	cout << minimumDeleteSum("delete", "leet") << endl;
    
	cout << minimumDeleteSum2("sea", "eat") << endl;
	cout << minimumDeleteSum2("delete", "leet") << endl;
	return 0;
}