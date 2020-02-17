#include <stdio.h>
#include <stdlib.h>

char* getFileName()
{
    char* s = malloc(sizeof(char));
    scanf("%s", s);
    return s;
}

char* getFileContent()
{
    // char *file_name = getFileName();
    char *file_name = "C:/Users/laptop/Documents/CPP/Lab 1/e.txt";
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

int main() {
    char *content;
    content = getFileContent();
    printf("%s", content);
    return 0;
}