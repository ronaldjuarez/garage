#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    queue<pair<string,int>> wordQ;
    unordered_set<string> seenWords;
    unordered_set<string> wordSet;


    wordQ.push(make_pair(beginWord,0));
    seenWords.insert(beginWord);
    
    // dump words into a set 
    for (auto word:wordList){
        wordSet.insert(word);
    }

    while (!wordQ.empty()){
        auto elem = wordQ.front();  
        string currWord = elem.first;
        int depth = elem.second;
        wordQ.pop();
        
        if (endWord == currWord) return depth + 1;

        for (int i = 0; i < currWord.size(); i++){
            for (int j = 0 ; j < alphabet.size() ; j++){
                char c = alphabet[j];
                string temp = currWord;
                temp[i] = c;
                if (wordSet.find(temp) != wordSet.end() && seenWords.count(temp) == 0){
                    wordQ.push(make_pair(temp,depth+1));
                    seenWords.insert(temp);
                }
            }
        }
    }
    return -1;
    
}
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
        auto elem = wordQ.front();  
        string currWord = elem.first;
        int depth = elem.second;
        wordQ.pop();
        
        if (target == currWord) return depth;

        for (int i = 0; i < currWord.size(); i++){
            for (int j = 0 ; j < alphabet.size() ; j++){
                char c = alphabet[j];
                string temp = currWord;
                temp[i] = c;
                if (wordSet.find(temp) != wordSet.end() && seenWords.count(temp) == 0){
                    wordQ.push(make_pair(temp,depth+1));
                    seenWords.insert(temp);
                }
            }
        }
    }
    return -1;
}


int main() 
{
	string source3 = "hit";
	string target3 = "lod";
	vector<string> words3{ "hit", "hot", "lit", "lot", "lid", "lod" };
	print2D(findLadders(source3, target3, words3));
	string source = "bit";
	string target = "dog";
	vector<string> words{ "but", "put", "big", "pot", "pog", "dog", "lot" };
	print2D(findLadders(source, target, words));

	string source2 = "cot";
	string target2 = "lit";
	vector<string> words2{ "hot", "pot", "lot", "pit", "lit" };	
	print2D(findLadders(source, target, words));
	return 0;
}
