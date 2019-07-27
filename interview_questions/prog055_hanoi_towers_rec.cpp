#include <iostream>
#include <cstdio>

using namespace std;

int hanoi(int n){
    if (n == 1){
        return 1;
    }
    if (n == 0){
        return 0;
    }
    return 2 * hanoi(n-1) + 1;
}

void hanoi_instructions(int n, char rodOrigin, char rodAux, char rodDest){
    if (n == 1){
        printf("Move disk %d from %c to %c\n", n, rodOrigin, rodAux);    
        return;
    }
    hanoi_instructions(n-1, rodOrigin, rodDest,rodAux);
    printf("Move disk %d from %c to %c\n", n, rodOrigin, rodAux);
    hanoi_instructions(n-1, rodAux, rodOrigin,rodDest);
}

int main(){
    int n = 5; // num of disk
    cout << hanoi(n) << endl ;

    hanoi_instructions(n, 'A', 'B', 'C');
    return 0;
}