#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> wordQ;
    unordered_set<string> seenSet;
    unordered_set<string> wordSet(wordList.begin(),wordList.end());
    unordered_map<string, vector<string>> parents;
    
    wordQ.push(make_pair(beginWord, 0));
    wordQ.pus
    
    
}
int main(){

    return 0;
}