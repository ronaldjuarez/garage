#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int shortestWordEditPath(const string& source, const string& target, const vector<string>& words)
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    queue<pair<string,int>> wordQ;
    unordered_set<string> seenWords;
    unordered_set<string> wordSet;


    wordQ.push(make_pair(source,0));
    seenWords.insert(source);
    
    // dump words into a set 
    for (auto word:words){
        wordSet.insert(word);
    }

    while (!wordQ.empty()){
        auto currWord = wordQ.front();  
        wordQ.pop();
        for (int i = 0; i < currWord.first.size(); i++){
            for (int j = 0 ; j < alphabet.size() ; j++){
                char c = alphabet[j];
                string temp = currWord.first;
                temp[i] = c;
                if (seenWords.count(temp) != 0
            }
        }
    }
  
}

int main() 
{
	return 0;
}
