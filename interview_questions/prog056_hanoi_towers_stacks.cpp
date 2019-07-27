#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Tower{
    private: 
        stack <int> disks;
        int index;
    public:
        Tower(int);
        int getIndex(void);
        int setIndex(int index);

};

Tower::Tower(int idx){
    index = idx;
}

int Tower::getIndex(void){
    return index;
}

int Tower::setIndex(int idx){
    index = idx;
}

int main(){ 
    int nrods = 3;
    
    vector<Tower> towers;
      for (int i = 0; i < nrods; i++){
        Tower tower(i);
        towers.push_back(tower);
    }

    for (int i = 0; i < nrods; i++){
        cout << towers[i].getIndex() << " ";
    }
    
    return 0;
}