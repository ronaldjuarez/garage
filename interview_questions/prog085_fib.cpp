#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

int fib(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int fib2(int n, vector<long long> &memo){
    if (memo[n] !=  -1 ) return memo[n];
    if (n < 0) return -1;
    if (n == 0) return memo[n] = 0ll;
    if (n == 1) return memo[n] = 1ll;
    memo[n] = fib2(n-1,memo) + fib2(n-2, memo);
    return memo[n];
}

int main(){
    vector<long long> memo(100,-1);
    clock_t begin = clock();
    cout << fib(10) << " ";
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "(Elapsed time: " << elapsed_secs << ") sec" << endl;
    begin = clock();
    cout << fib2(45, memo) << " ";
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "(Elapsed time: " << elapsed_secs << ") sec" << endl;
    return 0;
}