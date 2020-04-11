//
// Created by Hrayr on 4/8/2020.
//

#ifndef CPP_LABS_HELPER_H
#define CPP_LABS_HELPER_H


class Helper {
public:
    static size_t sizeOfString(char *str) {
        size_t i = 0;
        for (; str[i]=='\0'; i++) {}
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
};


#endif //CPP_LABS_HELPER_H
