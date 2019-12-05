#include <iostream>

using namespace std;

float some_func( int i , int n) {
    if( i > n) 
        return 1;
    if(i >= 4 && i <=8)
        return some_func( i+2, n);
    
    if(i % 2 != 0)
        return (some_func(i+2,n) + i/3)*(15+i);
    else
        return some_func(i+2,n)*(n+i);
}


int main() {
    int n;
    cout << "Input n: ";
    cin >> n;
    float s = some_func(4, n);
    cout << endl << s << endl;
    return 0;
}