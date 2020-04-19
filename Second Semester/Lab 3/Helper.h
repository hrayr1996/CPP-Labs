//
// Created by Hrayr on 4/8/2020.
//

#ifndef CPP_LABS_HELPER_H
#define CPP_LABS_HELPER_H
#include <iostream>

using namespace std;

class Helper {
public:
    static bool starting_text_input;
    static bool pointer_found_;
    static bool new_line;

    static size_t sizeOfString(char *str) {
        size_t i = 0;
        for (; str[i]!='\0'; i++) {}
        return i;
    }
    static bool strCompare(char *str_1, char *str_2) {
        size_t pos = 0;
        while (str_1[pos] != '\0' && str_2[pos] != '\0') {
            if (str_1[pos] != str_2[pos]) {
                return false;
            }
            pos++;
        }
        return true;
    }

    static bool prepareClause(char* str, char* &rtn, size_t start, size_t end) {
        size_t i = start;
        size_t j = end;
        // Check if clause starts with space character start trim the clause
        if (str[start] == ' ') {
            for (;str[i] == ' ';++i){}
        }
        if (str[end] == ' ') {
            for (;str[j] == ' '; --j){}
        }
        memcpy(rtn, &str[i], j - i+1);
        memcpy(rtn + (j - i + 1), "\0", 1);
        cout << Helper::sizeOfString(rtn) << endl;
        // Mike Davis - Melissa Rosenberg, Hilly Hicks JR., David Petrarca
    }

    static bool preparePointer(char *str, char* &pointer, char** &pointers, size_t &index) {
        char* tmp = new char[1000];
        size_t start_pos = 0;
        // says what should be taken from string stream
        for (size_t i = 0; i < 1000; ++i) {
            if (str[i] == '-') {
                Helper::new_line = false;
                index = 0;
                Helper::prepareClause(str, pointer, start_pos, i-1);
                start_pos = i+1;
                continue;
            }
            if (str[i] == ',' || str[i] == '\0') {
                Helper::new_line = false;
                pointers[++index] = (char*)malloc(sizeof(char));
                Helper::prepareClause(str, pointers[index], start_pos, i-1);
                start_pos = i+1;
                if (str[i] == '\0') {
                    return true;
                }
                continue;
            }
        }
        return true;
    }
};


#endif //CPP_LABS_HELPER_H
