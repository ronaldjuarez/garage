#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int LCS(const string& str1, const string& str2, vector<vector<int>>& memo, int i, int j) {
	int size1 = str1.size();
	int size2 = str2.size();
	int ans;

	if (size1 <= i || size2 <= j) return 0;

	if (memo[i][j] != -1) return memo[i][j];

	if (str1[i] == str2[j])
		ans = 1 + LCS(str1, str2, memo, i + 1, j + 1);
	else {
		ans = max(LCS(str1, str2, memo, i + 1, j), LCS(str1, str2, memo, i, j + 1));
	}
	memo[i][j] = ans;
	return ans;

}
int deletionDistance(const string& str1, const string& str2)
{
	// your code goes here
	vector<vector<int>> memo(str1.size(), vector<int>(str2.size(), -1));
	int longest = LCS(str1, str2, memo, 0, 0);

	return str1.size() - longest + str2.size() - longest;
}

int deletionDistance2(const string& str1, const string& str2) {
	vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
	int size1 = str1.size();
	int size2 = str2.size();

	if (size1 == 0) return size2;
	if (size2 == 0) return size1;

	for (int i = 0; i < size1+1; i++) {
		for (int j = 0; j < size2+1; j++) {
			if (i * j == 0) {
				dp[i][j] == 0;
			}
			else if (str1[size1 - i] == str2[size2 - j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return size1 + size2 - 2 * dp[size1][size2];
}
int deletionDistance3(const string& str1, const string& str2) {
	vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, 0));
	int size1 = str1.size();
	int size2 = str2.size();

	if (size1 == 0) return size2;
	if (size2 == 0) return size1;

	for (int i = 0; i < size1+1; i++) {
		for (int j = 0; j < size2+1; j++) {
			if (i * j == 0) {
				dp[i][j] == 0;
			}
			else if (str1[i-1] == str2[j-1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return size1 + size2 - 2 * dp[size1][size2];
}
int main() {
	cout << deletionDistance("", "") << endl;
	cout << deletionDistance2("", "") << endl;
	cout << deletionDistance3("", "") << endl;
    cout << endl;
	cout << deletionDistance("", "hit") << endl;
	cout << deletionDistance2("", "hit") << endl;
	cout << deletionDistance3("", "hit") << endl;
    cout << endl;
	cout << deletionDistance("neat", "") << endl;
	cout << deletionDistance2("neat", "") << endl;
	cout << deletionDistance3("neat", "") << endl;
    cout << endl;
	cout << deletionDistance("heat", "hit") << endl;
	cout << deletionDistance2("heat", "hit") << endl;
	cout << deletionDistance3("heat", "hit") << endl;
    cout << endl;
	cout << deletionDistance("hot", "not") << endl;
	cout << deletionDistance2("hot", "not") << endl;
	cout << deletionDistance3("hot", "not") << endl;
    cout << endl;
	cout << deletionDistance("some", "thing") << endl;
	cout << deletionDistance2("some", "thing") << endl;
	cout << deletionDistance3("some", "thing") << endl;
    cout << endl;
	cout << deletionDistance("ab", "ba") << endl;
	cout << deletionDistance2("ab", "ba") << endl;
	cout << deletionDistance3("ab", "ba") << endl;
    cout << endl;
	return 0;
}