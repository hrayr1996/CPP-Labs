//
// Created by Hrayr on 4/8/2020.
//

#include "Cast.h"

int Cast::integer(char *str) {
    int tmp = 0;
    int cur = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (i > 10) {
            throw "Cast error: given number greater than size of integer. Given number should be in range (+-)2147483647";
        }
        switch (str[i]) {
            case '0':
                cur = 0;
                break;
            case '1':
                cur = 1;
                break;
            case '2':
                cur = 2;
                break;
            case '3':
                cur = 3;
                break;
            case '4':
                cur = 4;
                break;
            case '5':
                cur = 5;
                break;
            case '6':
                cur = 6;
                break;
            case '7':
                cur = 7;
                break;
            case '8':
                cur = 8;
                break;
            case '9':
                cur = 9;
                break;
            default:
                return tmp;
        }
        tmp = tmp * 10 + cur;
    }
    return tmp;
}


size_t Cast::toSize_t(char *str) {
    size_t tmp = 0;
    int cur = 0;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (i > 10) {
            throw "Cast error: given number greater than size of integer. Given number should be in range (+-)2147483647";
        }
        switch (str[i]) {
            case '0':
                cur = 0;
                break;
            case '1':
                cur = 1;
                break;
            case '2':
                cur = 2;
                break;
            case '3':
                cur = 3;
                break;
            case '4':
                cur = 4;
                break;
            case '5':
                cur = 5;
                break;
            case '6':
                cur = 6;
                break;
            case '7':
                cur = 7;
                break;
            case '8':
                cur = 8;
                break;
            case '9':
                cur = 9;
                break;
            default:
                return tmp;
        }
        tmp = tmp * 10 + cur;
    }
    return tmp;
}