#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {true, false} bool;

char* getFileName(const char* msg)
{
    char* s = malloc(sizeof(char));
    printf("%s", msg);
    scanf("%s", s);
    return s;
}

char* getFileContent()
{
    char *file_name = getFileName("Text File name: ");
    // char *file_name = "e.txt";
    FILE* f = fopen(file_name,"r");
    if( !f ) perror(file_name),exit(1);
    fseek(f, 0, SEEK_END);
    int file_size = ftell(f);
    char* content = (char*)malloc(file_size);
    fseek(f, 0, SEEK_SET);
    int i = fread(content, file_size, sizeof(char), f);
    fclose(f);
    return content;
}

FILE* getFileInstance(char* file_name)
{
    // char *file_name = "e.txt";
    FILE* f = fopen(file_name,"r");
    if( !f ) perror(file_name),exit(1);
    fseek(f, 0, SEEK_END);
    return f;
}

char** prepareKeyWords()
{
    char** list = (char**)malloc(1);
    char* word;
    char ch;
    int pos = 0;
    bool newWord = true;

    while ((ch = fgetc(f)) != EOF)
    {
            if (ch == ' ' || ch == '\n')
            {
                if (newWord)
                {
                    // Skip this symbol cause there was more than 1 space character
                    continue;
                }
                else {
                    if (sizeof(word) < sizeof(char) * pos)
                    {
                        word = realloc(word, pos*sizeof(char));
                    }
                    fseek(f, (-1) * (pos+1), SEEK_CUR);
                    fread(word, sizeof(char)*pos, 1, f);
                    fseek(f, (pos+1), SEEK_CUR);
                    printf("%s\n", word);
                }
                newWord = true;
            }
            else {
                pos++;
            }
            

            newWord = false;
    }
}

// Working directory is C:\Users\laptop\Documents\CPP
int main() {
    prepareKeyWords();
    return 0;
}