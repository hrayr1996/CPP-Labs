#include <iostream>

using namespace std;

struct keyWord {
    char* word;
    int size;
};
struct keyWords {
    struct keyWord *keyword;
    int count;
} keyword_list;

long fileSize(FILE* f)
{
    fseek(f, 0, SEEK_END);
    return ftell(f);
}

void getKeyWord(FILE* f, long index)
{
    static int current_index = 0;
    static long current_pos = 0;
    static long file_size = fileSize(f);
    static char* current_word = (char*)"";
    
    if (current_pos >= file_size)
    {
        if (index > current_index)
            std::cout << "File on the end";
            return;
        current_pos = file_size;
    }

    if (current_index == index && current_word > 0)
    {
        std::cout << current_word << std::endl;
    }

    bool direction = current_index <= index; // get direction to walk
    char* word = (char*)malloc(1);
    char ch = '\0';
    long pos = 0;
    if (current_pos > 0)
        pos = 1;
    bool newWord = true;
    long tmp = 0;
    fseek(f, current_pos, SEEK_SET);
    while (ch != EOF)
    {
        if (current_pos < 0)
        {
            current_pos = 0;
            direction = true;
        }
        // cout << "1 " << current_pos << " -> " << ftell(f) << " | \t";
        if (ch == EOF) break;
        ch = fgetc(f);
        // cout << "2 " << current_pos << " -> " << ftell(f) << " | \t";
        if (direction)
            fseek(f, current_pos+1, SEEK_SET);
        else
            fseek(f, current_pos-1, SEEK_SET);
        //cout << "3 " << current_pos << " -> " << ftell(f) << " | \t";

        if (ch == ' ' || ch == '\r' || ch == '\n')
        {
            if (newWord)
            {
                // Skip this symbol cause there was more than 1 space character
                continue;
            }
            else {
                free(word);
                word = (char*)malloc(pos*sizeof(char));
                // pos++;
                // current_pos = ftell(f);
                fseek(f,current_pos - pos, SEEK_SET);
        cout << "4 " << current_pos << " -> " << ftell(f) << " | \t";
                fread(word, sizeof(char)*(pos), 1, f);
        cout << "5 " << current_pos << " -> " << ftell(f) << " | \t";
                if (current_index == index) {
                    current_pos -= pos;
                    current_word = word;
                    printf("%s\n", word);
                    break;
                }
                if (direction)
                {
                    current_index++;
                } else {
                    current_index--;
                }
                fseek(f, current_pos, SEEK_SET);
        cout << "6 " << current_pos << " -> " << ftell(f) << " | \t";
                pos=1;
            }
            newWord = true;
        }
        else {
            pos++;
            newWord = false;
        }
        if (direction)
        {
            current_pos++;
        } else {
            current_pos--;
        }
        cout << "7 " << current_pos << " -> " << ftell(f) << " | \t";
    }
}

void getFileContent(FILE* f)
{
    char ch;
    fseek(f, 0, SEEK_SET);
    while ((ch = fgetc(f)) != EOF)
    {
        std::cout << ch;
    }
}

char* getFileName(const char* msg)
{
    char* s = (char*)malloc(256 * sizeof(char));
    printf("%s", msg);
    scanf("%s", s);
    return s;
}
FILE* getFileInstance(char* file_name)
{
    // char *file_name = "e.txt";
    FILE* f = fopen(file_name,"rb+");
    if( !f ) perror(file_name),exit(1);
    fseek(f, 0, SEEK_SET);
    return f;
}

int main()
{
    char *file_name = (char*)"wordlist.txt";// getFileName("Keywords File:\n");
    FILE* f = getFileInstance(file_name);
    long pos = 0;
    std::cout << "Type index of word" << std::endl;
    while (true)
    {
        std::cin >> pos;
        if (pos < 0)
        break;
        getKeyWord(f,pos);
    }
    
    fclose(f);
    return 0;
}