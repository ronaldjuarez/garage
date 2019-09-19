#include <iostream>
#include <vector>
#include "helper.h"

using namespace std;

int quickSelectPartition(vector<vector<int>>& points, int l, int r) {
	int pivot = r;
	if (l == r)
		return l;
	int i = l;
	int dr = points[r][0] * points[r][0] + points[r][1] * points[r][1];
	for (int j = l; j < pivot; j++) {
		int dj = points[j][0] * points[j][0] + points[j][1] * points[j][1];
		if (dj < dr) {
			std::swap(points[i], points[j]);
			i++;
		}
	}
	std::swap(points[i], points[r]);
	return i;
}

int randomPartition(vector<vector<int>>& points, int l, int r) {
	int n = r - l + 1;
	int pivot = rand() % n;
	std::swap(points[l + pivot], points[r]);
	return quickSelectPartition(points, l, r);
}
void kClosest_rec(vector<vector<int>>& points, int l, int r, int k, vector<vector<int>>& ans) {
	int size = points.size();
	if (k > 0 && k <= size) {
		int i = randomPartition(points, l, r);
		if (i - l == k - 1) {
			std::vector<std::vector<int>>::iterator it;
			for (it = points.begin(); it != points.begin() + i+1; it++)
				ans.push_back(*it);
		}
		else if (i - l > k - 1) {
			kClosest_rec(points, l, i - 1, k, ans);
		}
		else {
			kClosest_rec(points, i + 1, r, k - (i + 1) + l, ans);
		}

	}
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	vector<vector<int>> ans;
	kClosest_rec(points, 0, points.size() - 1, K, ans);
	return ans;
}
int main() {
	vector<vector<int>> v{{1,0},{0,1}};
	print2D(kClosest(v, 2));
	return 0;
}