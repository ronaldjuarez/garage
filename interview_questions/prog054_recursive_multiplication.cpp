#include <iostream>
#include <vector>

using namespace std;

int prod1( int a , int b){
    int sum = 0;

    for (int i = 0 ; i < b; i++){
        sum += a;
    }
    return sum;
}

int prod2_rec(int a, int b, vector<int> &memo){
    if (memo[a] != 0){
        return memo[a];
    }
    if (a == 1) {
        return b;
    }
    if (a == 0){
        return 0;
    }
    memo[a] =  prod2_rec( a >> 1 , b, memo) + prod2_rec(a - (a>>1), b,memo);
    return memo[a];
}
int prod3_rec(int a, int b, vector<int> &memo){

    int half;
    if (memo[a] != 0){
        return memo[a];
    }
    if (a == 1) {
        return b;
    }
    if (a == 0){
        return 0;
    }
    half = prod2_rec( a >> 1 , b, memo);
    memo[a] =  half + half;
    
    if (a % 2 == 1) 
        memo[a] = memo[a] + b;
    return memo[a];
}

int prod3 (int a, int b){
    vector<int> memo(a+1,0);
    return prod3_rec(a,b,memo);
}
int prod2 ( int a , int b){
    vector<int> memo(a+1,0);
    return prod2_rec(a,b,memo);
}

int main(){
    int a = 7; 
    int b = 9;  
    int prod;

    prod = prod3(a,b);
    cout << prod << " " ;
    return 0;
}