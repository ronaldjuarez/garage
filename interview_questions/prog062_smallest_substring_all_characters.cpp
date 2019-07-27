#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool containsAll(string &ss, map<char,int> &m){
    int sizeStr = ss.length();
    int sizeMap = m.size();

    if (sizeStr < sizeMap){
        return false;
    }
    else{
        for (int i = 0; i< sizeStr; i++){
            if ()
        }
    }
}


string getShortestUniqueSubstring( const vector<char>& arr, const string &str ) 
{
    int i =0 ;
    int j = arr.size() - 1 ;
    int l = str.length();

    int min = 9999999;

    map<char,int> m;

    for(int i = 0; i < arr.size(); i++){
        m[arr[i]] = 1;
    }

    while ( i < l && j < l ){ //o(n)
        string ss = str.substr(i,j - i);
        if (!containsAll(ss, m)){ //o(n)
            j++
        }  //o(n)
        else{
            i++;
            if (j-i < l){
                j++ 
            }
            min = min < j-i ? min: j-i;
        } 
    }
    
}

int main() {

    string s("xyyzyzyx");
    vector<char> v;
    v.push_back('x');
    v.push_back('y');
    v.push_back('z');

    return 0;
}