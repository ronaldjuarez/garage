#include <iostream>
using namespace std;

long long power(int n , long long r){
    
    if (r == 0){
        return 1;
    }
    else if (r % 2 == 0){
        return power(n, r/2) * power(n, r/2);
    }
    else {
        return n  * power(n, r/2) * power(n , r/2);
    }

}

long long power2(int n , long long r){
    if (r == 0 ) {
        return 1;
    }
    long long temp = power2(n, r /2);
    if (r % 2 == 0){
        return temp * temp;            
    }
    else {
        return n * temp * temp;
    }
}
int main(){
    int n = 5, r = 3;
    
    cout << power2(n, r) << endl;
    return 0;
}