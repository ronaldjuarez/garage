#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> reverseArray(const vector<char>& arr){
    vector<char> vv = arr;
    int size = vv.size();
    for (int i = 0; i < size /2 ; i++)
        swap(vv[i], vv[size - 1 - i]); 
    return vv;
}

vector<char> reverseWords(const vector<char>& arr)
{
	// your code goes here
	vector<char> result = reverseArray(arr);
	int size = result.size();
	int i = 0, beginning = 0;
	while (i < size) {
		if (result[i] == ' ' ) {
			int size_subarray = i - beginning;
			for (int k = beginning; k < beginning + size_subarray / 2; k++) {
				swap(result[k], result[i - 1 - (k - beginning)]);
			}
			beginning = i + 1;
		}
        else if ( i == size - 1) {
            i++;
			int size_subarray = i - beginning;
			for (int k = beginning; k < beginning + size_subarray / 2; k++) {
				swap(result[k], result[i - 1 - (k - beginning)]);
			}
			beginning = i + 1;
        }
		i++;
	}
	return result;
}


int main() {
    //char c[] = { 'p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e'};
    char c[] = { ' ',  ' ', ' '};
    int n = sizeof(c)/sizeof(c[0]);
    vector<char> v(c, c+n);
    vector<char> vv = reverseWords(v);
    for (int i = 0; i <vv.size(); i++){
        cout << vv[i] << " ";
    }
    cout << endl;
    return 0;
}


/*
You are given an array of characters arr that consists of sequences of 
characters separated by space characters. Each space-delimited sequence of 
characters defines a word. Implement a function reverseWords that reverses
the order of the words in the array in the most efficient manner.

Explain your solution and analyze its time and space complexities.
input:  arr = [ 'p', 'e', 'r', 'f', 'e', 'c', 't', '  ',
                'm', 'a', 'k', 'e', 's', '  ',
                'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' ]

output: [ 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', '  ',
          'm', 'a', 'k', 'e', 's', '  ',
          'p', 'e', 'r', 'f', 'e', 'c', 't' ]

 */