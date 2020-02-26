#include <bits/stdc++.h> 
#include <cstdio> 
using namespace std; 
  
int main() 
{ 
    FILE* file_; 
    char buffer[100]; 
    file_ = fopen("wordlist.txt", "rb"); 
    while (!feof(file_)) // to read file 
    { 
        // fucntion used to read the contents of file 
        fread(buffer, sizeof(buffer), 1, file_);
        cout << buffer;
    } 
    return 0; 
} 