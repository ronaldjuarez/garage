#include <string>
#include <set>
#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    set<int> temp_set;
    
    int longest = 0;
    int i =0, j = 0;

    while (i < n && j < n){
        if (!temp_set.count(s[i])){
            temp_set.insert(s[i]);
            j++;
            longest = max(longest, j - i);
        }
        else{
            temp_set.erase(s[i]);
            i++;
        }
    }
    return longest;
}

int main(){
    string s = "abcabcbb";
    int longest = lengthOfLongestSubstring(s);

    cout << longest << endl;
    return 0;
}