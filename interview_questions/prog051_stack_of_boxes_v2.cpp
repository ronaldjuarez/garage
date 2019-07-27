#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Box{
    int height, weight, depth;
};
void testModify(vector<Box> &l){
    l[0].depth = 1000;
}

bool compareBoxes(Box b1, Box b2){
    return b1.height > b2.height;
}

void printListBoxes(vector<Box> l){
    for (vector<Box>::iterator it = l.begin(); it != l.end(); ++it){
        cout << (*it).height << ", " << (*it).weight << ", " << (*it).depth << " ";
        
    }
}


int getMaxHeight_rec(vector<Box> &l, Box bottom, int offset, vector<int> &stackMap){
    
    int heightWithBottom = 0;
    int heightWithoutBottom = 0;
    if (offset >= l.size()) return 0;

    Box newBottom = l[offset];
    
    if (bottom == NULL || canBeAbobe(newBottom, bottom){
        if (stackMap[offset] == 0){
            stackMap[offset] = getMaxHeight_rec(l, newBottom, offset + 1, stackMap);
            stackMap[offset] += newBottom.height;
        }
        heightWithBottom = stackMap[offset];
    }

    heightWithoutBottom = getMaxHeight(l, bottom, offset+1, stackMap);

    return max(heightWithBottom, heightWithoutBottom);
}

int getMaxHeight(vector<Box> &l){
    vector<int> stackMap(l.size());
    return getMaxHeight_rec(l, NULL, 0, stackMap);
}


int main(){
    
    Box listBoxes[] = { {4, 6, 7},{ 1, 2, 3}, {4, 5, 6},{10, 12, 32}};
    int n = sizeof(listBoxes)/sizeof(listBoxes[0]);
    int maxHeight;
    vector<Box> l(listBoxes, listBoxes+n);
    
    sort(l.begin(), l.end(), compareBoxes);
    
    //maxHeight = getMaxHeight(l);

    cout << "Max Height: " << maxHeight << " ";
    
    
    printListBoxes(l);
    return 0;
}