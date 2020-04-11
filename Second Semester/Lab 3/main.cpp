//
// Created by Hrayr on 4/8/2020.
//

#include <iostream>
#include "Connections.cpp"

using namespace std;

int main() {
    cout << "Welcome to Connections" << endl
    << "Type your connections titles:" << endl;
    Connections c;
    char* f = new char[1];
    char* g = new char[1];
    cin >> f >> g;
    c.add(f, g);
    cout << c.count() << " elements. ";

}