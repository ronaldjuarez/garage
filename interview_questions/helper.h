#include <vector>
#include <iostream>

void print1D(const std::vector<int> &v){
    int n = v.size();
    for (int e:v){
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void print2D(const std::vector<std::vector<int> > &m){
    int nr = m.size();
    int nc = m[0].size();

    for (int r = 0; r < nr ; r++){
        for(int c = 0; c < nc; c++){
            std::cout << m[r][c] << "\t";
        }
        std::cout << std::endl;
    }
}