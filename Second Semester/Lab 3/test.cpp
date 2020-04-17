// istream::getline example
#include <iostream>     // std::cin, std::cout

/*
int main () {
    char *title = new char[256];
    char* m = new char[1000];
    char end_of_string_character = '\0';
    std::cout << "Please, enter your favourite movie: ";
    int i = 0;
    size_t j = 0;
    while (true) {
        std::cin.getline (title, 1000);
        i = 0;
        for (; title[i] != '\0'; ++i) {}
        std::cout << " Size of title is " << i << std::endl;
//        std::cout << title << std::endl;
        j = 0;
        for (; title[j] != '-' && j < i; ++j) {}
*/
/*for (int a=0; a <= j; ++a) {
            std::cout << title[a];
}*//*

        memcpy(m, &title[2], sizeof(char) * (j-2));
        memcpy(m + sizeof(char) * (j), "\0", 1);
        std::cout << " Size of cup is " << j << std::endl;
        std::cout << m << std::endl;
//        std::cout << std::endl;
//        std::cout << "Position " << j << std::endl;
        if (i > 0 && title[0] == '\\')
            break;
    }

    return 0;
}*/
/*

using namespace std;

int main() {
    size_t i = 123;
    size_t f = 7895;
    char* str = new char[20];
    str = static_cast<char*>(static_cast<void*>(&i));

    cout << str << endl;
    f = static_cast<size_t*>(static_cast<void*>(str))[0];
    cout << f << endl;
    return 0;
}*/

//#include <iostream>     // std::cin, std::cout

int main () {
    char *name, title[256];
    name = new char[256];
    int f = 0;
    while (true) {

        std::cout << "Input a number: ";
        std::cin >> f;
        std::cout << std::endl << "Please, enter your name: ";
        std::cin.getline (name,256);

        std::cout << "Please, enter your favourite movie: ";
        std::cin.getline (title,256);

        std::cout << name << "'s favourite movie is " << title << std::endl;
        if (name[0] == '\\') {
            break;
        }
    }

    return 0;
}