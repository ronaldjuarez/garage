#include <vector>
#include <algorithm>
#include <iostream> 

using namespace std; 
void printVector(vector<int> v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}
float returnMedian(vector<int> &v1, vector<int> &v2){
    vector<int> v3 ;
    int i = 0;
    for (vector<int>::iterator it = v1.begin(); it != v1.end() ; ++it){
        if (*it < v2[i]){
            v3.push_back(*it);
            v3.push_back(v2[i]);
        } 
        else{
            v3.push_back(v2[i]);
            v3.push_back(*it);
        }
        ++i;
    }
    printVector(v3);
    return (float(v3[v1.size()-1])  + v3[v1.size()] ) / 2;
}
int main(){
    int arr1[] = {1,12,15, 26, 38};
    int arr2[] = {2,13,17,30,45};
    int median;
    int n = sizeof(arr1) / sizeof(arr1[0]);

    vector<int> v1(arr1, arr1 + n);
    vector<int> v2(arr2, arr2 + n);
    median = returnMedian(v1,v2);

    cout << "Median: " << median << " ";
    return 0;
}