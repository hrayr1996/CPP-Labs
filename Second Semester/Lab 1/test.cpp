#include <iostream>

using namespace std;

struct word {
    char* word; // char array with word
    long pos; // position in file
    long index; // index in words count of file
};

struct clause {
    char* clause; // char array with word
    long start; // start position in file
    long end; // end position in file
};

long fileSize(FILE* f)
{
    long cur = ftell(f);
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, cur, SEEK_SET);
    return fsize;
}

bool checkWordEndChar(char c)
{
    return c == EOF || c < '0' || (c > '9' && (c < 'A' || (c > 'Z' && (c < 'a' || c > 'z'))));
}

bool checkClauseEndChar(char c)
{
    return c == EOF || c == '.' || c == '?' || c == '!';
}

char* readWord(FILE* f, long current_position, long length)
{
    char* current_word = new char[length+1];
    fseek(f, current_position, SEEK_SET);
    fread(current_word, 1, length, f);
    current_word[length] = '\0';
    return current_word;
}

/**
 * Get word index by position in file
 * 
 **/
long getWordIndex(FILE* f, long posit)
{
    long current_position = 0;
    long file_size = fileSize(f);
    long current_index = -1;
    bool new_word = true;

    char sym = '\0';
    long pos = 0;

    while(true) {
        // Check which direction to walk
        current_position++;
        pos++;
        fseek(f, current_position, SEEK_SET);
        sym = fgetc(f);
        // If it is end of word. found symbol other than letter A-Za-z0-9
        if (checkWordEndChar(sym) || current_position > file_size)
        {
            current_index++;
            if ((sym == EOF || current_position > file_size))
            {
                break;
            }
            if (new_word && current_position < file_size)
            {
                continue;
            }
            if (current_position >= posit)
            {
                return current_index;
            }
            pos = 0;
            new_word = true;
        } else {
            new_word = false;
        }
    }
    return -1;
}

word getWord(FILE* f, long index)
{
    long current_position = 0;
    long file_size = fileSize(f);
    long current_index = -1;
    char* current_word;
    bool direction = true;
    bool new_word = true;
    bool it_was_end = false;
    struct word cur_word;

    cur_word.word = (char*)"";

    char sym = '\0';
    long pos = 0;

    while(true) {
        // Check which direction to walk
        current_position++;
        pos++;
        fseek(f, current_position, SEEK_SET);
        sym = fgetc(f);
        // If it is end of word. found symbol other than letter A-Za-z0-9
        if (checkWordEndChar(sym) || current_position > file_size)
        {
            if ((sym == EOF || current_position > file_size) && index != current_index)
            {
                break;
            }
            if (new_word && current_position < file_size)
            {
                continue;
            }
            current_index++;
            if (index == current_index)
            {
                pos--;
                current_word = readWord(f, current_position - pos, pos);
                cur_word.word = current_word;
                cur_word.pos = current_position - pos;
                cur_word.index = current_index;
                return cur_word;
            }
            pos = 0;
            new_word = true;
        } else {
            new_word = false;
        }
    }
    return cur_word;
}

FILE* getFileInstance(char* file_name)
{
    // char *file_name = "e.txt";
    FILE* f = fopen(file_name,"rb+");
    if( !f ) perror(file_name),exit(1);
    fseek(f, 0, SEEK_SET);
    return f;
}

/**
 * long pos - some position of clause
 * Even if current checking symbol is ending clause sybmol first go left and find start position of clause
 **/
struct clause getClause(FILE* file, long pos)
{
    long start = -1;
    long end = -1;
    long current_pos = pos;
    long file_size = fileSize(file);
    char ch = '\0';
    struct clause current;
    while(true)
    {
        fseek(file, current_pos, SEEK_SET);
        ch = getc(file);
        if (start == -1)
        {
            if (checkClauseEndChar(ch) || current_pos == 0)
            {
                if (current_pos != pos || pos == 0)
                {
                    if (current_pos != 0)
                    {
                        start = current_pos + 1;
                    }else 
                        start = current_pos;
                    current_pos = pos;
                    continue;
                }
            }
            current_pos--; // go left
        }
        else {
            if (checkClauseEndChar(ch))
            {
                if (current_pos != pos)
                {
                    current_pos++; // go right
                    end = current_pos;
                    current_pos = pos;
                    break;
                }
            }
            current_pos++; // go right
        }
    }
    current.clause = new char[end-start +1];
    current.start = start;
    current.end = end;
    fseek(file, start, SEEK_SET);
    fread(current.clause, sizeof(char), end-start, file);
    current.clause[end-start] = '\0';
    return current;
}


char* getFileName(const char* msg)
{
    char* s = new char[256];
    printf("%s", msg);
    scanf("%s", s);
    return s;
}

FILE* getKeywordFile()
{
    static char* file_name = (char*)"\0";
    static FILE* f;
    if (file_name[0] == '\0')
    {
        file_name = getFileName("Keywords File:\n");
        f = getFileInstance(file_name);
    }
    return f;
}

FILE* getClauseFile()
{
    static char* file_name = (char*)"\0";
    static FILE* f;
    if (file_name[0] == '\0')
    {
        file_name = getFileName("Clause File:\n");
        f = getFileInstance(file_name);
    }
    return f;
}

bool equal(char* a, char* b)
{
    for (int i = 0; true; i++)
    {
        // Checks if char arrays are not equal by size
        if ((a[i] == '\0' && b[i] !='\0') || (a[i] != '\0' && b[i] =='\0'))
        {
            return false;
        }
        // Check if min 1 char is not same
        if (a[i] != b[i])
            return false;
        // Checks if end of arrays
        if (a[i] == '\0')
            return true;
    }

    return true;
}

long startHandle()
{
    long current_position = 0;
    FILE* keywords = getKeywordFile();
    FILE* clauseFile = getClauseFile();
    struct word cword, kword;
    struct clause current;
    cword = getWord(clauseFile, 0);

    // Start first loop in clause to distinct duplicates
    // loop until getWord function will return (char*)""
    // loop for clause
    for(long c_i = 1; cword.word != ""; c_i++)
    {
        kword = getWord(keywords, 0);
        // loop for keywords
        for(long w_i=1; kword.word != ""; w_i++)
        {
            if (equal(cword.word, kword.word))
            {
                current = getClause(clauseFile, cword.pos);
                cout << current.clause << endl;
                c_i = getWordIndex(clauseFile, current.end);
                break;
            }
            kword = getWord(keywords, w_i);
        }
        cword = getWord(clauseFile, c_i);
    }
    fclose(keywords);
    fclose(clauseFile);
    return 0;
}

int main()
{
    startHandle();
    return 0;
}