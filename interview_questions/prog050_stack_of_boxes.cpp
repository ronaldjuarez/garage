#include <iostream>
#include <algorithm>
using namespace std;
struct Box{
    int height, weitgh, depth;
};

bool compareBoxes(Box b1, Box b2){
    return b1.height > b2.height;
}

void printBoxes(Box listBoxes[], int n){
    for (int i = 0 ; i < n ; i++){
        cout << "{" << listBoxes[i].height << ", " << listBoxes[i].weitgh << ", " << listBoxes[i].depth << "} ";
    }
}

bool canBeAbove(Box b1, Box b2){
    return b1.height < b2.height and b1.weitgh < b2.weitgh and b1.depth < b2.depth;
}


int createStackRec(Box listBoxes[], int index, int n, int heightMemo[]){

    if (heightMemo[index] > 0) {
        return heightMemo[index];
    }

    Box baseBox = listBoxes[index];
    int maxHeight = 0, currentHeight = 0;
    
    for (int i = index + 1; i < n; i++ ){
        if (canBeAbove(listBoxes[i], baseBox)){
            currentHeight = createStackRec(listBoxes, i, n, heightMemo);
            maxHeight = max(currentHeight, maxHeight);
        }
    }
    maxHeight += baseBox.height;
    heightMemo[index] = maxHeight;
    return maxHeight;
}

int createStacks(Box listBoxes[], int n){
    int current_max = 0;
    int maxHeight = 0;
    int heightMemo[n] = {0};

    for ( int i = 0; i < n ; i++){
        current_max = createStackRec(listBoxes,i, n, heightMemo);
        maxHeight = max(current_max, maxHeight);
    }
    
    return maxHeight;
}
int main(){
    Box listBoxes[] = {{4, 6, 7},{ 1, 2, 3}, {4, 5, 6},{10, 12, 32}};
    int n = sizeof(listBoxes) / sizeof(listBoxes[0]);
    int maxHeight;

    sort(listBoxes, listBoxes + n, compareBoxes);

    maxHeight = createStacks(listBoxes, n);

    cout << "Max height: " <<  maxHeight << " ";
    printBoxes(listBoxes, n);
    return 0;
}