#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countWays(const int &n, const vector<int> &v){

    if (n < 0) return 0;
    if (n == 0) return 1;
    if (n == 1) {
        if (std::find(v.begin(), v.end(), 1) != v.end()){
            return 1;
        }
        else{
            return 0;
        }
    }

    int total = 0;
    int size = v.size();

    for (int i = 0; i < size; i++){
        if( n - v[i] >= 0) {
            total += countWays(n-v[i], v);
        }
    }
    return total;
}

int countWays2(const int &n, const vector<int> &v, vector<int> &memo){
    if (memo[n] != -1) return memo[n];
    if (n < 0) return memo[0] = 0;
    if (n == 0) return memo[0] = 1;
    if (n == 1) {
        if (std::find(v.begin(), v.end(), 1) != v.end()){
            return memo[1] = 1;
        }
        else{
            return memo[1] = 0;
        }
    }

    int total = 0;
    int size = v.size();
    for (int i = 0; i < size; i++){
        if( n - v[i] >= 0) {
            total += countWays(n-v[i], v);
        }
    }
    memo[n] = total;
    return memo[n];
}

int countWays3(const int &n, const vector<int> &v){
    if (n < 0) return 0;
    if (n == 0) return 1;
    bool oneExist = std::find(v.begin(), v.end(), 1) != v.end();
    if (n == 1) {
        if (oneExist){
            return 1;
        }
        else{
            return 0;
        }
    }
    vector<int> memo(n+1,0);
    memo[0] = 1;
    memo[1] = oneExist? 1:0;

    for (int i = 2; i < n + 1 ; i++){
        for( int j = 0; j < v.size(); j++){
            if (i - v[j] >= 0){
                memo[i] += memo[i-v[j]];
            }        
        }
    }
    return memo[n];
}


int main(){
    int n = 4;
    vector<int> steps{1,2};
    vector<int> memo(n+1,-1);
    cout << countWays3(n,steps) << endl;
    return 0;
}