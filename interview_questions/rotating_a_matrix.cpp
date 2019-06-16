#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generateData(int N){
    vector<vector< int> > matrix(5, vector<int>(5));
    for (int i = 0 ; i < N * N; i++){
        int row = i/N, col = i % N ;
        matrix[row][col] = i;

    }
    return matrix;
}

void printMatrix(vector<vector<int> > &v){
    int n = v.size();
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n ; j++){
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
}

void rotateMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    int temp;

    for (int layer = 0; layer < n/2 ; layer++){
        int last = (n - 1) - layer;
        for (int i = layer; i < last ; i++){
            temp = matrix[layer][i];                    // temp = top[i]
            matrix[layer][i] = matrix[n-1-i][layer];    // top[i] = left[i]
            matrix[n-1-i][layer] = matrix[last][n-1-i];         // left[i] = bottom[i]
            matrix[last][n-1-i] = matrix[i][last];  // bottom[i] = right[i]
            matrix[i][last] = temp;             // right[i] = temp
        }
    }

    cout << endl;
}

int main(){
    int N = 5;  //number and rows/columns

    vector<vector< int> > matrix(N, vector<int>(N));

    matrix = generateData(N);
    
    //before
    printMatrix(matrix);

    rotateMatrix(matrix);

    //after
    printMatrix(matrix);

    return 0;
}