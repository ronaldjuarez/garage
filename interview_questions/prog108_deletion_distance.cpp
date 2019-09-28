#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int LCS(const string& str1, const string& str2, vector<vector<int>> &memo, int i, int j ){
  int size1 = str1.size();
  int size2 = str2.size();
  int ans;
  
  if (size1 <= i || size2 <= j) return 0;
  
  if (memo[i][j] != -1) return memo[i][j];
  
  if (str1[i] == str2[j]) 
      ans = 1 + LCS(str1,str2, memo, i+1, j+1);
  else {
      ans = max(LCS(str1,str2,memo, i+1,j), LCS(str1,str2,memo, i,j+1));
  }
  memo[i][j] = ans;
  return ans;
  
}
int deletionDistance( const string& str1, const string& str2 ) 
{
  // your code goes here
  vector<vector<int>> memo(str1.size(), vector<int>(str2.size(), -1));
  int longest = LCS(str1, str2, memo, 0, 0);
  
  return str1.size() - longest + str2.size() - longest;
}

int deletionDistance( const string& str1, const string& str2 ) {
    vector<vector<int>> dp(str1.size(), vector<int>(str2.size(),-1));
    
    dp[0][0] = 0;
    for (int i = 0; i < str1.size(); i++){
        for (int j = 0; j < str2.size; j++){
            if ( (i == 0 && j != 0) || (i != 0 && j == 0)) {
                dp[i][j] == 0;
            }
        }
    }
    for (int i = 0; i < str1.size(); i++){
        for (int j = 0; j < str2.size; j++){
            if ( (i == 0 && j != 0) || (i != 0 && j == 0)) {
                
            }
        }
    }

}

int main() {
    cout << deletionDistance("", "") << endl;
    cout << deletionDistance("", "hit") << endl;
    cout << deletionDistance("neat", "") << endl;
    cout << deletionDistance("heat", "hit") << endl;
    cout << deletionDistance("hot", "not") << endl;
    cout << deletionDistance("some", "thing") << endl;
    cout << deletionDistance("ab", "ba") << endl;
    return 0;
}

/*      acc += 
        ma = {'o': 2, 'g': 2, 'x' : 1}     map= {'o': 2, 'g': 2, 'z' : 1}
        ogxog   gxog    
        ooggz   oggz
        
        lsoome  ldoome
        loome   loome
        memo[i,j] = val;
        if ( word1[i] == word2[i])
           1 + findLCS(gxog,oggz)
        else
           max(findLCNS(gxog,ggz),findLCNS(xog,oggz) )
           
           
        word1 = dog
        word2 = frog
        memo[2, 2] =  LCS(og, rog);
        i = 0
        LCS(dog, frog) = max(LCS(og,frog), LCS(dog, rog));
                       = max(max(LCS(g,rog), LCS(og, rog)), 
                             max(LCS(dog, og), LCS(og, rog))
                             
       LCS(g,rog) = max(LCS('',og), LCS(g,og))
       LCS(og, rog) = max(LCS(og, og), LCS(g, rog))
       LCS(og, og) = 1 + LCS(g, g) = 1 + (1 + LCS('', '')) = 2
       LCS('', string) = 0
       
       return len(dog) - LCS(dog, frog)  + len(from) - LCS(dog, frog) ;
       
        O(N*M)
        O(N*M)
        
input:  str1 = "dog", str2 = "frog"
output: 3

input:  str1 = "some", str2 = "some"
output: 0

input:  str1 = "some", str2 = "thing"
output: 9

input:  str1 = "", str2 = ""
output: 0


*/