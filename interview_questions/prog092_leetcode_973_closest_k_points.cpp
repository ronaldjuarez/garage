#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "helper.h"

using namespace std;

float euclideanDistance(const vector<int> &p1,const vector<int> &p2){
    return sqrt(pow(p1[1]-p2[1],2) + pow(p1[0]-p2[0],2));
}

bool comparePoints(const vector<int> &p1, const vector<int> &p2){
    int d1 = euclideanDistance(p1, {0,0});
    int d2 = euclideanDistance(p2, {0,0});
    return d1 < d2;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    sort(points.begin(), points.end(),comparePoints);
}

int main(){
    vector<vector<int>> points {{3,3},{5,-1},{-2,4}};
    kClosest(points,2);
    print2D(points);
    return 0;
}