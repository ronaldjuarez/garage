#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include "helper.h"

using namespace std;

void DFS(unordered_map<string, vector<string>>& parents, vector<vector<string>> &ans, string source, string target, vector<string>& currentPath) {

	if (source == target) {
		ans.push_back(vector<string>(currentPath.rbegin(), currentPath.rend()));
		return;
	}

	for (auto parent : parents[source]) {
		currentPath.push_back(parent);
		DFS(parents, ans, parent, target, currentPath);
		currentPath.pop_back();
	}
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	queue<pair<string, int>> wordQ;
	unordered_set<string> seenSet;
	unordered_set<string> processed;
	unordered_set<string> wordSet(wordList.begin(), wordList.end());
	unordered_map<string, int > bannedPos;
	unordered_map<string, vector<string>> parents;
	bool found = false;

	wordQ.push(make_pair(beginWord, 0));
	seenSet.insert(beginWord);
	parents[beginWord] = {};
	bannedPos[beginWord] = -1;


	while (!wordQ.empty()) {
		auto elem = wordQ.front();
		wordQ.pop();
		string currWord = elem.first;
		int depth = elem.second;

		for (int i = 0; i < currWord.size(); i++) {
			if (i == bannedPos[currWord]) continue;
			for (int j = 0; j < alphabet.size(); j++) {
				if (currWord[i] != alphabet[j]) {
					string tempWord = currWord;
					tempWord[i] = alphabet[j];
					if (wordSet.count(tempWord) != 0 && processed.count(tempWord) == 0){
						if (seenSet.count(tempWord) == 0 ) {
							wordQ.push(make_pair(tempWord, depth + 1));
							bannedPos[tempWord] = i;
						}
						if (tempWord == endWord) {
							found = true;
						}
						parents[tempWord].push_back(currWord);
						seenSet.insert(tempWord);
					}
				}
			}
		}
		processed.insert(currWord);

	}

	vector<string> currentPath;
	vector<vector<string>> ans;
	currentPath.push_back(endWord);

	DFS(parents, ans, endWord, beginWord, currentPath);
	return ans;
}
int main() {
	string source3 = "hit";
	string target3 = "lod";
	vector<string> words3{ "hot", "lit", "lot", "lid", "lod" };
	print2D(findLadders(source3, target3, words3));

	string source = "bit";
	string target = "dog";
	vector<string> words{ "but", "put", "big", "pot", "pog", "dog", "lot" };
	print2D(findLadders(source, target, words));

	string source2 = "cot";
	string target2 = "lit";
	vector<string> words2{ "hot", "pot", "lot", "pit", "lit" };
	print2D(findLadders(source2, target2, words2));
	return 0;
}

