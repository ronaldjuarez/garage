#include <iostream>
#include <string>

using namespace std;

bool stringToBool(string &s){
    bool result;
    if (s[0] == '1'){
        result = true;
    }
    else if (s[0] == '0'){
        result =false;
    }
    else 
        // raise exception
    
    return result;
}

int countWays(string &s, bool result){
    if (s.length() == 0) return 0;
    if (s.length() == 1) {
        return stringToBool(s) == result? 1: 0;
    }

    int output = 0;
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if (c == '&' || c == '^' || c == '|') {
            string sleft = s.substr(0,i);
            string sright = s.substr(i+1);  

            int leftTrue = countWays(sleft, true);
            int leftFalse = countWays(sleft, false);
            int rightTrue = countWays(sright, true);
            int rightFalse = countWays(sright, false);

            int total  = (leftTrue + leftFalse) * (rightTrue + rightFalse);

            int numWays = 0;
            if (c == '&') numWays = leftTrue * rightTrue;
            else if (c == '|') numWays = leftTrue * rightFalse + leftFalse * rightTrue + leftTrue * rightTrue;
            else if (c == '^') numWays = leftTrue * rightFalse + leftFalse * rightTrue;

            numWays = result == false? total - numWays : numWays;
            output += numWays;
        }
    }

    return output;

}

int main(){
    //string s("0^0&0^1|1");
    //string s("1^0|0|1");
    string s("0&0&0&1^1|0");
    bool result = true;
    //bool result = false;
    
    cout << countWays(s, result) << " ";
    //bool result = false;
    return 0;
}