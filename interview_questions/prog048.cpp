#include <bits/stdc++.h> 

using namespace std;

int invert(int x){
    int rev = 0, pop;
    while (x != 0) {
        pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev ;
}

int main(){
    
    int n = -321; 
    int result = invert(n);
    cout << result << " ";
    cout << -19 % 10<< " ";
    return 0;
}


/*
Invert a 32-bit integer, examples:

input = 123  --> output = 321



*/