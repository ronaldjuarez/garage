
// C++ program to compute 
// factorial of big numbers 
#include <iostream> 
#include <map>
#include <vector>
#include <algorithm>
using namespace std; 
  
// Maximum number of digits in  
// output 
#define MAX 100000 
  
// This function multiplies x 
// with the number represented by res[]. 
// res_size is size of res[] or 
// number of digits in the number 
// represented by res[]. This function 
// uses simple school mathematics 
// for multiplication. 
// This function may value of res_size 
// and returns the new value of res_size 
int multiply(int x, int res[], int res_size) { 
  
    // Initialize carry 
    int carry = 0; 
    
    // One by one multiply n with 
    // individual digits of res[] 
    for (int i = 0; i < res_size; i++) { 
        int prod = res[i] * x + carry; 
    
        // Store last digit of 
        // 'prod' in res[] 
        res[i] = prod % 10; 
    
        // Put rest in carry 
        carry = prod / 10; 
    } 
    
    // Put carry in res and 
    // increase result size 
    while (carry) { 
        res[res_size] = carry % 10; 
        carry = carry / 10; 
        res_size++; 
    } 
    return res_size; 
    } 
  
// This function finds 
// power of a number x 
void power(int x, int n)  
{ 
    
    //printing value "1" for power = 0 
    if(n == 0 ){  
        cout<<"1"; 
        return; 
    } 
    
    
    int res[MAX]; 
    int res_size = 0; 
    int temp = x; 
    
    // Initialize result 
    while (temp != 0) { 
        res[res_size++] = temp % 10; 
        temp = temp / 10; 
    } 
    
    // Multiply x n times 
    // (x^n = x*x*x....n times) 
    for (int i = 2; i <= n; i++) 
        res_size = multiply(x, res, res_size); 
    
    cout << x << "^" << n << " = "; 
    for (int i = res_size - 1; i >= 0; i--) 
        cout << res[i]; 
} 

void print(const vector<int> & v){
    int size = v.size();
    for(int i = 0; i< size; i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void modify(vector<int> & v){
    v[1] = 1000;
}

struct comparator{
    bool operator()(const int& i, const int& j) {
        return i > j;
    }
};
  
class Test { 
    int value; 
public: 
    Test(int v = 0) {value = v;} 

    int getValue() const {return value;}   
    void setValue(int v);
}; 

void Test::setValue(int v ) {
    value = v;
}
// Driver program 
int main() { 

    //std::vector<int> vv({3,4,7,8,9,9,10,13,15,20});
    std::vector<int> vv({44,33,77,11,55,88,66});

    std::make_heap(vv.begin(), vv.end());
    print(vv);
    std::cout << vv.front() << endl;
    std::pop_heap(vv.begin(),vv.end()); vv.pop_back();
    std::cout << vv.front() << endl;
    print(vv);
    std::pop_heap(vv.begin(),vv.end()); vv.pop_back();
    std::cout << vv.front() << endl;
    print(vv);
    std::pop_heap(vv.begin(),vv.end()); vv.pop_back();
    std::cout << vv.front() << endl;
    print(vv);
    
    std::pop_heap(vv.begin(),vv.end()); vv.pop_back();
    std::cout << vv.front() << endl;
    print(vv);

    std::pop_heap(vv.begin(),vv.end()); vv.pop_back();
    std::cout << vv.front() << endl;
    print(vv);


    /*
    int exponent = 100; 
    int base = 20; 
    //power(base, exponent); 

    map<int, char> m;

    m[1] = 1;

    if (m[2] == 0)
        cout << "This is true" << endl;
    else   
        cout << "this is false" << endl;
     */
    return 0; 
} 
