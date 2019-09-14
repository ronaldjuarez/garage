#include <iostream>
#include <vector>

using namespace std;

int numFriendRequests(vector<int>& ages) { 
    int contNum[121] = {0};
    int accNum[121] = {0};
    int ans = 0;

    for (int age: ages){
        contNum[age]++;
    }

    for (int i = 1; i <= 120; ++i){
        accNum[i] = contNum[i] + accNum[i-1];
    }

    for (int i = 15; i <= 120; ++i){
        if (contNum[i] != 0){
            int b = i/2 + 7;
            int countPeople = accNum[i] - accNum[b];
            ans += (countPeople- 1) * contNum[i];
        }
    }

    return ans;
}

int main(){
    vector<int> v1{16,16,17,17,17};
    cout << numFriendRequests(v1) << endl;
    return 0;
}