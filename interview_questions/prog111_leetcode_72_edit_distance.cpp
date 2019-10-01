#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance_rec(const string &word1 , const string &word2, int i, int j, vector<vector<int>> memo){
    int sizeWord1 = word1.size();
    int sizeWord2 = word2.size();

    if (sizeWord1 == 0) return memo[0][sizeWord1] =  sizeWord2;
    if (sizeWord2 == 0) return memo[sizeWord1][0] = sizeWord1;
    
    if ( i > sizeWord1) return -1;
    if ( j > sizeWord2) return -1;
    
}
int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size()+1, vector<int>(word2.size()+1,-1));
    return minDistance_rec(word1,word2,0,0,memo);
    
}
int main(){
    cout << minDistance("horse", "ros");
    return 0;
}