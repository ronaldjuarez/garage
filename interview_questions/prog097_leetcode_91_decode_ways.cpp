#include <iostream>
#include <string>
#include <vector>

using namespace std;


int numDecodingsRec(string& s, int pos, const int& size, vector<int>& memo, bool& stopFlag) {
	int n = 0;
	if (stopFlag == true) return 0;
	if (pos < size - 1) {
		int a = s[pos] - '0', b = s[pos + 1] - '0';
		n = 10 * a + b;
		if (a >= 3 && b == 0) {
			stopFlag = 0;
			return 0;
		}
	}
	if (pos >= size || pos < 0 || s[pos] == '0') return 0;
	if (memo[pos] != -1) return memo[pos];
	if (pos == size - 1) {
		if (s[pos] != '0') return 1;
		else return 0;
	}
	if (pos == size - 2) {
		int a = s[pos] - '0';
		int b = s[pos + 1] - '0';
		if (10 * a + b > 26 || a == 0 || b == 0) {
			return 1;
		}
		else {
			return 2;
		}
	}
	int ans = numDecodingsRec(s, pos + 1, size, memo, stopFlag);
	if (stopFlag == false ) {
		if (n <= 26 && n >= 10){
			ans += numDecodingsRec(s, pos + 2, size, memo, stopFlag);
		}
	}
	else {
		return 0;
	}
	memo[pos] = ans;
	return ans;
}
int numDecodings(string s) {
	int size = s.size();
	vector<int> memo(size, -1);
	bool stopFlag = false;
	return numDecodingsRec(s, 0, s.size(), memo, stopFlag);
}

int numDecodingsRec2(string& s, int pos, const int& size, vector<int>& memo) {
	int n = 0;
	if (pos == size) return 1;
	if (s[pos] == '0') return 0;
	if (memo[pos] != -1) return memo[pos];

	int ans = numDecodingsRec2(s, pos + 1, size, memo);

	if (pos < size - 1){
		int a = s[pos], b = s[pos+1];
		int n = 10 * a + b;
		if (n <= 26 && n >= 10){
			ans += numDecodingsRec2(s, pos + 2, size, memo);
		}
	}
	memo[pos] = ans;
	return ans;
}
int numDecodings2(string s) {
	int size = s.size();
	if (size == 0) return 0;
	vector<int> memo(size, -1);
	return numDecodingsRec2(s, 0, s.size(), memo);
}


int numDecodings3(string s) {
	int size = s.size();
	if (size == 0) return 0;
	if (s[0] == '0') return 0;
	vector<int> dp(size + 1, 0);
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= size; i++) {
		int n = s[i - 1] - '0';
		int m = stoi(s.substr(i - 2, 2));

		if (n >= 1) {
			dp[i] += dp[i - 1];
		}
		if (m >= 10 && m <= 26) {
			dp[i] += dp[i - 2];
		}
	}
	return dp[size];
}

int numDecodings4(string s) {
	int size = s.size();
	if (size == 0) return 0;
	if (s[0] == '0') return 0;
	if (size == 1) return 1;

	int p = 1;
	int q = 1;
	int ans = 0;

	for (int i = 2; i <= size; i++) {
		int n = s[i - 1] - '0';
		int m = stoi(s.substr(i - 2, 2));
		ans = 0;
		if (n >= 1) {
			ans = q;
		}
		if (m >= 10 && m <= 26) {
			ans += p;
		}
		p = q;
		q = ans;
	}
	return ans;
}

int numDecodingsRec5(string& s, int pos, vector<int>& memo) {
    if (memo[pos] != -1) return memo[pos];
    if (pos == 0) return memo[pos] = 1;
    if (pos == 1 && s[s.size()-pos] != '0') return memo[pos] = 1;

    int one = s[s.size() - pos] - '0';
    int two = stoi(s.substr(s.size() - pos, 2));
    int ans = 0;

    if (one >= 1) {
        ans += numDecodingsRec5(s, pos - 1, memo);
    }

    if (two >= 10 && two <= 26) {
        ans += numDecodingsRec5(s, pos - 2, memo);
    }
    memo[pos] = ans;
    return ans;
}
int numDecodings5(string s) {
	int size = s.size();
	if (size == 0) return 0;
	vector<int> memo(size+1, -1);
	return numDecodingsRec5(s, s.size(), memo);
}

int main() {
	string s = "611";
	std::cout << numDecodings(s) << std::endl;
	std::cout << numDecodings2(s) << std::endl;
	std::cout << numDecodings3(s) << std::endl;
	std::cout << numDecodings4(s) << std::endl;
	std::cout << numDecodings5(s) << std::endl;
	return 0;
}