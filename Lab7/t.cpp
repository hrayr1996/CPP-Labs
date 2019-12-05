#include <iostream>
#include <cstring>

using namespace std;

void some_func(int &tiv)
{
    tiv=6;
}


char* input_charZ(char* msg, int n,char* &rtn)
{
    cout << msg;
    char* s = new char[n];
    int i=n;
    while(strstr(s, "=") == NULL)
    {
        cin >> s;
        if(strlen(s)+strlen(rtn) >= i )
        {
            char* z_tmp = new char[i];
            strcpy(z_tmp, rtn);
            i = i + strlen(s);
            memset(rtn, '\0', strlen(s));
            strcpy(rtn, z_tmp);
        }
        // strcpy(rtn+strlen(rtn), (char*)" ");
        strcpy(rtn+strlen(rtn), s);
    }
    return rtn;
}

void replace(char* &s, char* rpl, int start, int end)
{
    char* tmp = new char[end];
    memcpy(tmp, s+end, strlen(s+start));
    memcpy(s+start, rpl, strlen(rpl));
    memcpy(s+start+strlen(rpl), tmp, strlen(tmp));
    int pos = strlen(rpl) + strlen(tmp);
    if(pos < strlen(s+start))
    {
        memset(s+start + strlen(rpl) + strlen(tmp), '\0', pos);
    }
}

int main(void)
{
    // int i = 15;
    // char* str = new char[i];
    // char* text = new char[i-10];

    // input_charZ((char*)"INput your string", i, str);
    // input_charZ((char*)"Text to add: ", 5, text);
    
    // int start   = 5,
    //     end     = 7;

    // cout << str + start << endl;

    // replace(str, text, start, end);
    // cout << str << endl;
    // some_func(i);
    
    double dbl = 2222;
    char* ptr = new char[10];
    // memcpy(ptr, &dbl, sizeof(dbl));
    sprintf(ptr, "%f", dbl);
    char* ggg = new char;
    memset(ggg, '\0', 2);
    memcpy(ggg, ptr, 2);
    
    memset(ggg+2, '\0', 2);
    cout << ggg << endl;
}