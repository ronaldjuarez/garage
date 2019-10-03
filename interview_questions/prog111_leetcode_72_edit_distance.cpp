#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance_rec(string word1, string word2, int i, int j, vector<vector<int>> memo) {
	int size1 = word1.size();
	int size2 = word2.size();
	int ans = 0;

	if (size1 <= i || size2 <= j) {
		if (size1 <= i && size2 <= j) {
			return 0;
		}
		else if (size1 > i) {
			return size1 - i;
		}
		else if (size2 > j) {
			return size2 - j;
		}
	}

	if (memo[i][j] != -1) return memo[i][j];
	if (word1[i] == word2[j]) {
		ans = minDistance_rec(word1, word2, i + 1, j + 1, memo);
	}
	else {
		int a = minDistance_rec(word1, word2, i + 1, j + 1, memo);
		int b = minDistance_rec(word1, word2, i, j + 1, memo);
		int c = minDistance_rec(word1, word2, i + 1, j, memo);
		ans = 1 + min(a, min(b, c));
	}
	memo[i][j] = ans;
	return ans;
}

int minDistance(string word1, string word2) {
	vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
	return minDistance_rec(word1, word2, 0, 0, memo);
}

int minDistance_rec2(string word1, string word2, int i, int j, vector<vector<int>> memo) {
	int size1 = word1.size();
	int size2 = word2.size();
	int ans = 0;

	if (i == 0) return memo[i][j] = j;
	if (j == 0) return memo[i][j] = i;

	if (memo[i][j] != -1) return memo[i][j];
	if (word1[i-1] == word2[j-1]) {
		ans = minDistance_rec2(word1, word2, i - 1, j - 1, memo);
	}
	else {
		int a = minDistance_rec2(word1, word2, i - 1, j - 1, memo);
		int b = minDistance_rec2(word1, word2, i, j - 1, memo);
		int c = minDistance_rec2(word1, word2, i - 1, j, memo);
		ans = 1 + min(a, min(b, c));
	}
	memo[i][j] = ans;
	return ans;
}

int minDistance2(string word1, string word2) {
	int sizeWord1 = word1.size();
	int sizeWord2 = word2.size();
	vector<vector<int>> memo(sizeWord1 + 1, vector<int>(sizeWord2 + 1, -1));
	return minDistance_rec2(word1, word2, sizeWord1, sizeWord2, memo);
}


int minDistance3(string word1, string word2) {
	int sizeWord1 = word1.size();
	int sizeWord2 = word2.size();
	vector<vector<int>> memo(sizeWord1 + 1, vector<int>(sizeWord2 + 1, -1));

    for (int i = 0 ; i <=sizeWord1; i++){
        for (int j = 0 ; j <= sizeWord2; j++){
            if ( i == 0) {
                memo[i][j] = j;
                continue;
            }
            if ( j == 0) {
                memo[i][j] = i; 
                continue;
            }

            if (word1[i-1] == word2[j-1]){
                memo[i][j] = memo[i-1][j-1];
            }
            else{
                memo[i][j] = 1 + min(memo[i-1][j-1],min(memo[i][j-1],memo[i-1][j]));
            }
        }
    }
	return memo[sizeWord1][sizeWord2];
}

int main() {
	cout << minDistance("horse", "ros") << endl;
	cout << minDistance("tion", "tion") << endl;
	cout << minDistance("ten", "ecu") << endl;
	cout << minDistance("nten", "xecu") << endl;
	cout << minDistance("inten", "execu") << endl;
	cout << minDistance("algorithm", "altruistic") << endl;
	cout << minDistance("intention", "execution") << endl;

	cout << endl;

	cout << minDistance2("horse", "ros") << endl;
	cout << minDistance2("tion", "tion") << endl;
	cout << minDistance2("ten", "ecu") << endl;
	cout << minDistance2("nten", "xecu") << endl;
	cout << minDistance2("inten", "execu") << endl;
	cout << minDistance2("algorithm", "altruistic") << endl;
	cout << minDistance2("intention", "execution") << endl;
	cout << endl;

	cout << minDistance3("horse", "ros") << endl;
	cout << minDistance3("tion", "tion") << endl;
	cout << minDistance3("ten", "ecu") << endl;
	cout << minDistance3("nten", "xecu") << endl;
	cout << minDistance3("inten", "execu") << endl;
	cout << minDistance3("algorithm", "altruistic") << endl;
	cout << minDistance3("intention", "execution") << endl;
	return 0;
}