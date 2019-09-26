#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "helper.h"

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int i = 0, j = 1;
	int size = intervals.size();
	vector<vector<int>> ans;
	int newElem = true;
	while (i < size) {
		if (newElem) {
			ans.push_back(intervals[i]);
			newElem = false;
		}
		else if (j < size && (
			     (intervals[i][1] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) ||
			     (intervals[j][1] >= intervals[i][0] && intervals[j][1] <= intervals[i][1]))) {
			int sizeAns = ans.size();
			ans[sizeAns - 1][0] = min(ans[sizeAns - 1][0], intervals[j][0]);
			ans[sizeAns - 1][1] = max(ans[sizeAns - 1][1], intervals[j][1]);
			j++;
		}
		else {
			newElem = true;
			i = j;
			j++;
		}
	}
	return ans;
}

int main() {
	vector<vector<int>> v{ {1,3},{2,6},{8,10},{15,18} };
	vector<vector<int>> vv{ {1,4},{4,5} };
	vector<vector<int>> vvv{ {1,3} };
	vector<vector<int>> vvvv{ {1,4},{5,6} };
	vector<vector<int>> vvvvv{ {1,4},{0,4} };
	vector<vector<int>> vvvvvv{ {1,4},{0,0} };
	vector<vector<int>> vvvvvvv{ {1,4},{0,2},{3,5} };
	vector<vector<int>> vvvvvvvv{ {1,5},{0,1} };
	print2D(merge(v));
	print2D(merge(vv));
	print2D(merge(vvv));
	print2D(merge(vvvv));
	print2D(merge(vvvvv));
	print2D(merge(vvvvvv));
	print2D(merge(vvvvvvv));
	print2D(merge(vvvvvvvv));
	return 0;
}