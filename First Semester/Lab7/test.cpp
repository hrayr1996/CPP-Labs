#include <iostream>
#include <cstring>

using namespace std;

char getSymbol(char*);
bool checkSymbol(char*);

int input_int(char* message)
{
    cout << message;
    int a;
    cin >> a;
    return a;
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
        strcpy(rtn+strlen(rtn), s);
    }
    return rtn;
}

/**
 * Find first operator position and return it
 * @param high
 *          -- true  - looking for * or /
 *          -- false - looking for + or -
 * 
 */
char* firstOperator(char* pos, bool high)
{
        while(true)
        {

            char s_l = getSymbol(pos);
            
            if(s_l - '=' == 0)
            {
                return NULL;
            }
            

            if(!checkSymbol(pos)) // if num skip this position
            {
                pos++;
                continue;
            }
            
            if(high) // for High Priority Operators * and /
            {
                if(s_l - '/' == 0 || s_l - '*' == 0)
                {
                    return pos;
                }
            }else
            {
                if(s_l - '+' == 0 || s_l - '-' == 0)
                {
                    return pos;
                }
            }
            pos++;
            
        }

        return NULL;
}


char getSymbol(char* i_p)
{
    char a;
    memcpy(&a, i_p, 1);
    return a;
}

// Checks first symbol of given char*
bool checkSymbol(char* i_p)
{
    char symbols[] = {'+', '-', '=', '*', '/'};

    size_t i = 0;
    char a;
    char b;
    while (i < 5)
    {
        memcpy(&a, i_p, 1);
        memcpy(&b, symbols + i, 1);
        if(a - b == 0)
        {
            return true;
        }
        i++;
    }
    

    return false;
}

/**
 * If direction is True look for left operand
 *                  False look for right operand
 * 
 * @param i_p // Expression cursor
 * @param direction // true search left | false search right
 * @param bigStart // Position from start of expression
 * 
 */
char* operand(char* i_p, bool direction, int bigStart)
{
    
    char* tmp;
    char *oper_d;
    int i = 1;
    
    while(true)
    {
        if(direction){
            tmp = new char[strlen(i_p-i)];
            strcpy(tmp, i_p-i);
            // tmp = i_p-i;
        }
        else
        {
            tmp = new char[strlen(i_p+i)];
            strcpy(tmp, i_p+i);
            // tmp = i_p+i;
        }
        if(i == bigStart) break;
        if(checkSymbol(tmp))
        {
            i--;
            break;
        }
         i++;
    }
    oper_d = new char[i];
    memset(oper_d, '\0', i);
    if(direction)
    {
        if(getSymbol(i_p-i-1) == '-'){
            i++;
        }
        memcpy(oper_d, i_p-i, i);
    }else
        memcpy(oper_d, i_p+1, i);
    memset(oper_d+i, '\0', i);
    return oper_d;
}

/**
 * Replaces given text(rpl) in given string(&s) from start(int) position to end(int) position
 * 
 */
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

double getNumber(char* x)
{
    double x_x = 0.0;
    sscanf(x, "%lf", &x_x);
    return x_x;
}

double calc(char* a, char* b, char oper_r)
{
    double a_a = getNumber(a);
    double b_b = getNumber(b);
    double result = 0;
    switch (oper_r)
    {
    case '+':
        result = a_a + b_b;
        break;
    case '-':
        result = a_a - b_b;
        break;
    case '*':
        result = a_a * b_b;
        break;
    case '/':
        result = a_a / b_b;
        break;
    
    default:
        break;
    }
    return result;
}

int main() 
{
    char* str;
    char* expression;

    str = new char;
    memset(str, '\0', 1);
    input_charZ((char*)"Input your custom string:\n", 10, str);

    // Save Expression for output on the result print
    expression = new char[strlen(str)];
    strcpy(expression, str);

    char *pos = str;
    char* left_operand = new char;
    char* right_operand = new char;
    char oper_r = '\0';
    int counter = 0;
    bool high_priority_operator = true;
    char* sum = new char;
    memset(left_operand, '\0', 1);
    memset(right_operand, '\0', 1);
    memset(sum, '\0', 1);
    while(true)
    {
        pos = firstOperator(pos, high_priority_operator);
        if(pos == NULL)
        {
            pos = firstOperator(str, high_priority_operator);
            if(pos == NULL)
            {
                if(!high_priority_operator)
                {
                    break; // If no operator found (+,-,*,/) so all calculated and break the cycle
                }
                pos = str;
                high_priority_operator = false;
                continue;
            }
        }
        left_operand = operand(pos, true, pos-str);
        right_operand = operand(pos, false, pos-str);
        memcpy(&oper_r, pos, 1); // oper_r{Operator} = pos[1]; 
        sprintf(sum, "%f", calc(left_operand, right_operand, oper_r));
        replace(str, sum, (pos-str)-strlen(left_operand), (pos-str)+strlen(right_operand)+1);
        pos = str;
        cout << str << endl;
    }
    
    cout << expression << sum;

    return 0;
}
// 12 + 3 * 4 - 3*8 + 12 / 4=