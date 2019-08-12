#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const vector<vector<char> > &m){
    int nr = m.size();
    int nc = m[0].size();

    for (int i = 0; i < nr ; i++){
        for (int j = 0; j < nc ; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<char> > &grid, int i, int j){
    int nr = grid.size();
    int nc = grid[0].size();

    if (i < nr && i >=0 && j < nc && j >= 0 && grid[i][j] != '0'){
        return true;
    }
    return false;

}

void dfs(vector<vector<char> > & grid, int i, int j){
    
    if (isSafe(grid,i,j)) grid[i][j] = '0';
    if (isSafe(grid,i-1,j)) dfs(grid,i-1, j);
    if (isSafe(grid,i+1,j)) dfs(grid,i+1,j);
    if (isSafe(grid,i,j-1)) dfs(grid,i,j-1);
    if (isSafe(grid,i,j+1)) dfs(grid,i,j+1);

}

int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    int nc = grid[0].size();
    int num_islands = 0;

    for (int i = 0; i < nr ; i++){
        for (int j = 0; j < nc ; j++){
            if (grid[i][j] == '1'){
                num_islands++;
                dfs(grid,i,j);
            }
        }
    }
    return num_islands;

}

int main(){
    //vector<vector<char> > m = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    vector<vector<char> > m = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    int n = numIslands(m);
    print(m);
    cout << n << endl;
    return 0;
}