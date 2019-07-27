#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int getMaxPriceRec(int prices[], int index, int lengthRod){
    if (index >= lengthRod){
        return 0;
    }
    
    if (lengthRod <= 0) {
        return 0;
    }
    return max(prices[index] + getMaxPriceRec(prices, index, lengthRod - (index+1)), getMaxPriceRec(prices, index+1, lengthRod));
}

int getMaxPrice(int prices[], int length){
    return getMaxPriceRec(prices, 0, length);
}

int cutRod(int prices[], int length){
    int maxPrice = 0;
    for (int i = 0; i < length; i++ ){
        maxPrice = max(maxPrice, prices[i] + cutRod(prices, length - (i+1)));
    }
    return maxPrice;
}
  
int main(){ 
    int prices[] = {1, 5, 8 , 9 ,10, 17, 17 , 20};
    int length = 8;
    int maxPrice;

    maxPrice = getMaxPrice(prices, length);
    
    cout << maxPrice << " ";

    cout << cutRod(prices, length) <<  " ";
    getchar(); 

    return 0;
}