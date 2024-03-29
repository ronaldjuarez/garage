
// C++ program to compute 
// factorial of big numbers 
#include <iostream> 
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <typeinfo>
#include <random>
#include "helper.h"
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

void test4(){
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

}

void test10(){
    std::set<int> s; 
    s.insert(5);
    s.insert(7);
    s.insert(10);
    s.insert(2);
    s.insert(7);
    s.insert(3);

    std::set<int>::iterator itr;

    for (itr = s.begin(); itr != s.end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << s.count(7) << std::endl;   
    std::cout << s.count(8) << std::endl;

}

void test11(){
    std::unordered_map<int,int> m;

    m[2] = 3;
    m[1] = 5;
    m[3] = 4;

    std::unordered_map<int,int>::iterator itr;

    for(itr = m.begin(); itr != m.end(); itr++){
        std::cout << itr->first << " " << itr->second << std::endl;
    }

    std::map<int,int> mm;

    mm[2] = 3;
    mm[1] = 5;
    mm[3] = 4;

    std::map<int,int>::iterator itr2;

    for(itr2 = mm.begin(); itr2 != mm.end(); itr2++){
        std::cout << itr2->first << " " << itr2->second << std::endl;
    }

}

struct Node{
    int x;
    Node(int i): x(i) {}
};
void test12_f(Node* n){
    Node vv(3);
    std::cout << n << std::endl;
    *n = vv;
    std::cout << n->x << std::endl;
}
void test12(){
    Node* n = new Node(2);
    Node* nn = n;
    std::cout << n << std::endl; 
    std::cout << nn << std::endl; 
    std::cout << &n << std::endl; 
    std::cout << &nn << std::endl; 
    Node* nnn = nullptr;
    Node* nnnn = NULL;
    
    if (nnn == nnnn){
        std::cout << "YEE-HAW" << std::endl;
    }

    if ( nnn != nullptr){
        std::cout << "not initialized" << std::endl;
    }
    std::cout << &nnn << std::endl; 
    test12_f(nnn);

}

void test13(){
    const int a2 = 20;
    const int * b2 = &a2;
    int *d2 = (int *) (b2);
    *d2 = 30;
    std::cout <<  a2 << std::endl;
    std::cout << *d2 << std::endl;
}

void test14(){
    struct myStruct{
        int x;
        int y;
        char c;
        bool b;
    };
    myStruct s; 
    s.x = 5; s.y = 10; s.c = 'a'; s.b= true;
    int * p = reinterpret_cast<int *> (&s);
    cout << *p << endl;
    p++;
    cout << *p << endl;
    p++;
    char * c = reinterpret_cast<char *> (p);
    cout << *c << endl;
    p++;

    float a = 3.9f;
    std::cout << static_cast<int>(a) << std::endl;

    string s1 = "ab";
    string s2 = "cd";

    string s3 = s1 + s2;

    std::cout << s3 << std:: endl;

    std::cout << log10(99) << std::endl;
    std::cout << log10(100) << std::endl;
    std::cout << log10(101) << std::endl;
}

void test15(){
    map<int,int> m;
    m[15] = 1;
    m[5] = 3;
    m[2] = 7;
    m[4] = 2;

    map<int,int>::iterator it;

    for (it = m.begin(); it != m.end(); it++){
        cout << it->first << ": " << it->second << endl;
    }
}

void test16_helper(const vector<int> &v ) {
    //v[1] = 4;
}

void test16(){
    vector<int> v{1,2,3};
    test16_helper(v);
    Helper::print1D(v);
    vector<int> vv;
    cout << vv.size() << endl;
}

void test17(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5,6};

    cout << &v1 << endl;
    cout << &v2 << endl;

    v2 = v1;

    cout << &v1 << endl;
    cout << &v2 << endl;
    
    Helper::print1D(v1);
    Helper::print1D(v2);

}

void test18(){
    int a  = 's';
    std::cout << a << std::endl;
}

void test19()
{
    int a = 80;

    double b = log2(static_cast<double>(a));

    std::cout << b << std::endl;

    int c = static_cast<int>(b);

    std::cout << c << std::endl;

    auto d = ceil(b);
    auto e = static_cast<int>(d);

    std::cout << "d type: " << typeid(d).name() << std::endl;
    std::cout << "d value: " << d << std::endl;

    std::cout << "e type: " << typeid(e).name() << std::endl;
    std::cout << "e value: " << e << std::endl;
}

void test20()
{
    std::unordered_map<int, std::vector<int>> randomMap;

    randomMap[1].push_back(2);

    std::unordered_map<int, std::vector<int>>::iterator randomMapIt;

    std::cout << "printing...." << std::endl;

    for(randomMapIt = randomMap.begin(); randomMapIt  != randomMap.end(); randomMapIt++)
    {
        std::cout << randomMapIt->first << std::endl;
    }
}

void test21()
{
    Node* node1 = new Node(1);

    Node* node1_copy = node1;

    if ( node1 == node1_copy)
    {
        std::cout << "they are the same " << std::endl;
    }
    else
    {
        std::cout << "they are not the same " << std::endl;
    }
}

void test22()
{
    std::unordered_map<int, double> map;
    std::cout << "test 21..." << std::endl;
    if (map.find(2) != map.end())
    {
        std::cout << map[2] << std::endl;
    }
    std::cout << "map size..." << std::endl;
    std::cout << map.size() << std::endl;
}

void test23()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::map<int, int> hist;
    std::uniform_int_distribution<int> dist(0,9);

    for (int n = 0 ; n < 20000; n++)
    {
        hist[dist(gen)]++;
    }

    for (auto p: hist)
    {
        std::cout << p.first << ": " << std::string(p.second/100,'*') << std::endl;
    }
}

void test24()
{
    std::vector<int> testVector {1,2,3,4,5};
    std::vector<int>::iterator beginIt = testVector.begin();
    std::vector<int>::iterator endIt = testVector.end();

    std::cout << "Distance: " << std::distance(beginIt, endIt);
}

int main() {     
    std::cout << "printing from main...." << std::endl;
    test24();
    //test23();
    //test22();
    //test21();
    //test20();
    //test19();
    //test18();
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
