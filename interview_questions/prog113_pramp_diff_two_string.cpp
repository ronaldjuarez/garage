#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "helper.h"

using namespace std;

vector<string> diffBetweenTwoStrings(const string& source, const string& target)
{
	int sizeSource = source.size();
	int sizeTarget = target.size();
	vector<vector<int> > memo(sizeSource + 1, vector<int>(sizeTarget + 1, 0));
	for (int i = 0; i <= sizeSource; i++) {
		for (int j = 0; j <= sizeTarget; j++) {
			if (i == 0) {
				memo[i][j] = j;
			}
			else if (j == 0) {
				memo[i][j] = i;
			}
			else if (source[sizeSource - i] == target[sizeTarget - j]) {
				memo[i][j] = memo[i - 1][j - 1];
			}
			else {
				memo[i][j] = 1 + min(memo[i][j - 1], memo[i - 1][j]);
			}
		}
	}

	print2D(memo);

	int i = sizeSource;
	int j = sizeTarget;
	vector<string> ans;

	while (i >= 1 && j >= 1) {
		if (source[sizeSource - i] == target[sizeTarget - j]) {
			ans.push_back(string(1, source[sizeSource - i]));
			i--; j--;
		}
		else {
			if (memo[i - 1][j] <= memo[i][j - 1]) {
				ans.push_back("-" + string(1, source[sizeSource - i]));
				i--;

			}
			else {
				ans.push_back("+" + string(1, target[sizeTarget - j]));
				j--;
			}
		}
	}

	while (j >= 1) {
		ans.push_back("+" + string(1, target[sizeTarget - j]));
		j--;
	}
	return ans;
}

vector<string> diffBetweenTwoStrings2(const string& source, const string& target)
{
	int sizeSource = source.size();
	int sizeTarget = target.size();
	vector<vector<int> > memo(sizeSource + 1, vector<int>(sizeTarget + 1, 0));
	for (int i = 0; i <= sizeSource; i++) {
		for (int j = 0; j <= sizeTarget; j++) {
			if (i == 0) {
				memo[i][j] = j;
			}
			else if (j == 0) {
				memo[i][j] = i;
			}
			else if (source[i - 1] == target[j - 1]) {
				memo[i][j] = memo[i - 1][j - 1];
			}
			else {
				memo[i][j] = 1 + min(memo[i][j - 1], memo[i - 1][j]);
			}
		}
	}

	print2D(memo);

	int i = 1;
	int j = 1;
	vector<string> ans;

	while (i <= sizeSource && j <= sizeTarget) {
		if (source[i-1] == target[j-1]) {
			ans.push_back(string(1, source[i-1]));
			i++; j++;
		}
		else {
			if (memo[i + 1][j] <= memo[i][j + 1]) {
				ans.push_back("-" + string(1, source[i - 1]));
				i++;
			}
			else {
				ans.push_back("+" + string(1, target[j - 1]));
				j++;
			}
		}
	}

	while (j <= sizeTarget) {
		ans.push_back("+" + string(1, target[j - 1]));
		j++;
	}
	return ans;
}

int main()
{
	string source = "ABCDEFG";
	string target = "ABDFFGH";
	print1D(diffBetweenTwoStrings2(source, target));

	print1D(diffBetweenTwoStrings2("AABACC", "BABCAC"));
	return 0;
}