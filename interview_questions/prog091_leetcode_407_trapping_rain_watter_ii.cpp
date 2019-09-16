#include <queue>
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int trapRainWater(vector<vector<int>>& heightMap) {
	int ans = 0;
	int maxHeight = INT_MIN;
	int nrow = heightMap.size();
	if (nrow == 0) return ans;
	int ncol = heightMap[0].size();
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<pair<int,int>>> q;
	std::vector<std::vector<int>> visited(nrow, vector<int>(ncol, 0));


	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			if (i == 0 || i == nrow - 1 || j == 0 || j == ncol - 1) {
				q.push(std::make_pair(heightMap[i][j], i * ncol + j));
				visited[i][j] = 1;
			}
		}
	}
	
	int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

	while (!q.empty()) {
        std::pair<int, int> val = q.top(); q.pop();
		int height = val.first; 
		int r = val.second / ncol; 
		int c = val.second % ncol;

		maxHeight = std::max(maxHeight, height);

		for (int* d : dir) {
			int r2 = r + d[0];
			int c2 = c + d[1];
			if (r2 >= nrow || r2 < 0 || c2 >= ncol || c2 < 0 || visited[r2][c2] != 0) continue;
			visited[r2][c2] = 1;
			ans += std::max(maxHeight - heightMap[r2][c2],0);
			q.push(make_pair(heightMap[r2][c2], r2 * ncol + c2));
		}
	}

	return ans;
}
int main() {
	vector<vector<int>> heightMap{ {1, 1, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1} };
	std::cout << trapRainWater(heightMap) << std::endl;
	return 0;
