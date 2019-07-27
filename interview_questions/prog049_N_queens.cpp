#include <stdio.h>
#define N 8
using namespace std;


int count = 0;
void printSol(int board[N][N]){

    for (int i = 0 ; i < N; i++){
        for (int j = 0; j < N; j++){
            printf ("%d ", board[i][j]);
        }
        printf("\n");
    }

}

bool isSafe(int board[N][N], int r,int c){
    
    for (int i = 0; i < c; i++){
        if (board[r][i] == 1) return false;
    }
    
    for (int i = r, j = c; i >= 0 && j >= 00; i--,j--){
        if (board[i][j] == 1) return false;
    }

    for (int i = r, j = c; i < N && j >= 0; i++, j--){
        if (board[i][j] == 1) return false;
    }

    return true;
}

bool solveNQRec(int board[N][N], int col){
    
    if (col >= N) {
        return true;
        count+=1;
    }
    for ( int i = 0; i < N ; i++ ){
        if (isSafe(board, i, col)){
            board[i][col] = 1;
            if (solveNQRec(board, col+1)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ(){
    int board[N][N] = {{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}};

    

    bool existSol = solveNQRec(board,0);
    if (existSol) {
    
        printf("Count: %d\n", count);
        printSol(board);
    }
    else 
        printf("Solution does not exist");
    return existSol;
    
}


int main(){
    
    solveNQ();
    return 0;
}