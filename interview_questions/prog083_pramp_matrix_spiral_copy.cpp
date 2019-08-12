#include <vector>
#include <iostream>
#include "helper.h"

std::vector<int> spiralCopy(const std::vector<std::vector<int> >& inputMatrix){
    std::vector<int> ans;

    int nr = inputMatrix.size();
    int nc = inputMatrix[0].size();
    int layer = 0;
    while (nr * nc > 0){

        //top = m[layer][layer:nc-1-layer] - inclusive
        for (int c = layer; c < nc - 2 - layer; c++){
            ans.push_back(inputMatrix[layer][c];
        }

        //left = m[layer:nr-1-layer][nc-1-layer] - inclusive
        for(int r = layer; r < nr - 2 - layer; r++ ){
            ans.push_back(inputMatrix[r][nc-1-layer]);
        }

        //bottom = m[nr-1-layer][nc-1-layer:-1:1+layer]

    }

    return ans;
}

int main(){
    std::vector<std::vector<int> > matrix = { 
            {1,    2,   3,  4,    5},
            {6,    7,   8,  9,   10},
            {11,  12,  13,  14,  15},
            {16,  17,  18,  19,  20}};

    print2D(matrix);
   
    return 0;
}