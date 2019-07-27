#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector< vector< int> > findPairs(vector<int> &v, int k) {
	map<int, int> m;
	vector<vector<int> > result;
	int x, y, l = v.size();

	for (int i = 0; i < l; i++) {
		x = v[i];
		y = x - k;
		m[y] = x;
	}

	for (int i = 0; i < l; i++) {
		if (m.count(v[i]) > 0) {
			vector<int> pair;
			pair.push_back(v[i] + k);
			pair.push_back(v[i]);
			result.push_back(pair);
		}
	}
	return result;
}

vector< vector< int> > findPairs2(vector<int> &v, int k) {
	map<int, int> m;
	vector<vector<int> > result;
	int x, y, l = v.size();


	for (int i = 0; i < l; i++) {
		x = v[i];
		y = x - k;
        if (m.count(x) > 0){
			vector<int> pair;
			pair.push_back(x);
			pair.push_back(y);
			result.push_back(pair);
        }
		else if (m.count(y) == 0) {
			m[y] = x;
		}
		else {
			vector<int> pair;
			pair.push_back(x);
			pair.push_back(y);
			result.push_back(pair);
		}
	}

	return result;
}


//{0, -1, -2 , 2 ,1}
//{-1, -2 , -3 , 1, 0}
//{-1:0, -2:-1, -3:-2 , 1:2, 0:1}

int main() {
	int input[] = { 0, -1, -2, 2, 1 }, k = 1;
	//int input[] = {1, 7, 5, 3, 32, 17, 12 }, k = 17;
	int n = sizeof(input) / sizeof(input[0]);

	vector<int> v(input, input + n);

	vector< vector < int> > output;

	output = findPairs2(v, k);

	/*
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
	cout << *it << endl;
	}
	*/
	for (unsigned int i = 0; i < output.size(); i++) {
		for (unsigned  int j = 0; j < output[0].size(); j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}