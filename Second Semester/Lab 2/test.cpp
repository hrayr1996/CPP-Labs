#include <iostream>

using namespace std;

// Single Student Data structure
struct student {
    char name[25];
    char lastname[36];
    int age;
    int avrgR;
};

// Student List Data Structure
struct Students {
    struct student *list;
    int usr_count;
} stud_list;

long findSymbolPos(FILE* file, char s, long start = 0)
{
    long current = -1;
    long lastpos = ftell(file);
    char tmp;
    fseek(file, start, SEEK_SET);
    while (true)
    {
        tmp = fgetc(file);

        if (tmp == s || tmp == EOF)
        {
            current = ftell(file) - 1;
            break;
        }
    }
    if (tmp == EOF && start == current+1)
    {
        return EOF;
    }
    fseek(file, lastpos, SEEK_SET);
    return current;
}

// get single student data from command line
struct student inputSingle()
{
    student s;
    
    cout << "Input Student Information splitted by space (Name Lastname Age AvarageRating): " << endl;
    // s.name = new char[25];
    // s.lastname = new char[36];
    cin >> s.name >> s.lastname >> s.age >> s.avrgR;

    return s;
}

// Input data for many students
void inputData(struct Students &studlist)
{
    student *s;
    int si = 0;
    cout << "How many students will be stored?" << endl;
    cin >> si;

    s = new student[si];

    for(int i = 0; i < si; i++)
    {
        s[i] = inputSingle();
    }
    studlist.usr_count = si;
    studlist.list      = s;
}

// Shows just information about single student
void showSingle(struct student s)
{
    cout << s.name << " " << s.lastname << ", " << s.age << " years old. Got " << s.avrgR << " rating." << endl;
}

// Shows information about all students in given Students list structure
void showAll(struct Students &s)
{
    for(int i; i < s.usr_count; i++)
    {
        showSingle(s.list[i]);
    }
}

bool writeColumn(FILE* f, char* word, char* devider)
{
    char tmp;
    for (long i = 0; (tmp = word[i]) != '\0'; i++)
    {
        fwrite(&word[i], sizeof(char), 1, f);
    }
    fwrite(devider, sizeof(char), 1, f);
    return true;
}

bool writeColumn(FILE* f, int a, char* devider)
{
    fwrite(&a, sizeof(int), 1, f);
    fwrite(devider, sizeof(char), 1, f);
    return true;
}

long fileSize(FILE* f)
{
    long cur = ftell(f);
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, cur, SEEK_SET);
    return fsize;
}

bool saveToFile(char* filename, struct Students students)
{
    FILE* file = fopen(filename, "w");
    
    for (int i=0; i < students.usr_count; i++)
    {
        // fwrite(&students.list[i], sizeof(struct student), 1, file);
        writeColumn(file, students.list[i].name, (char*)" ");
        writeColumn(file, students.list[i].lastname, (char*)" ");
        writeColumn(file, students.list[i].age, (char*)" ");
        writeColumn(file, students.list[i].avrgR, (char*)"\n");
        // fwrite((char*)"\n", sizeof(char), 1, file);
    }
    fclose(file);
    return true;
}

bool read(char* filename, struct Students &students)
{
    FILE *infile; 
    infile = fopen (filename, "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        return false;
    }
    int count = 0;
    long pos = 0;
    long lastpos = 0;
    long filesize = fileSize(infile);
    while((pos = findSymbolPos(infile, '\n', pos)) != -1) 
    {
        pos++;
        count++;
    }
    if (count == 0)
    {
        return false;
    }
    
    students.usr_count = count;
    students.list = new student[count];
    
    fseek(infile, 0, SEEK_SET);

    // read file contents till end of file 
    long i = 0;
    while(true)
    {
        lastpos = ftell(infile);

        // If file ends break cycle
        if (lastpos == filesize)
            break;

        pos = findSymbolPos(infile, ' ', lastpos+1);
        fread(&students.list[i].name, pos-lastpos, 1, infile);
        lastpos = ftell(infile);
        pos = findSymbolPos(infile, ' ', lastpos+1);
        fread(&students.list[i].lastname, pos-lastpos, 1, infile);
        fgetc(infile); // Move Forward
        fread(&students.list[i].age, 1, sizeof(int), infile);
        fgetc(infile); // Move Forward
        fread(&students.list[i].avrgR, 1, sizeof(int), infile);
        fgetc(infile); // Move Forward

        printf ("%s %s %d\n", students.list[i].name, 
        students.list[i].lastname, students.list[i].age);
        i++;
    }
  
    // close file 
    fclose (infile);
    return true;
}



FILE* getFileInstance(char* file_name)
{
    // char *file_name = "e.txt";
    FILE* f = fopen(file_name,"rb+");
    if( !f ) perror(file_name),exit(1);
    fseek(f, 0, SEEK_SET);
    return f;
}

char* getFileName(const char* msg)
{
    char* s = new char[256];
    printf("%s", msg);
    scanf("%s", s);
    return s;
}

void storeNew()
{
    inputData(stud_list);
}

void menu()
{
    int chosen = -1;
    while (true)
    {
        cout << endl << endl;
        cout << "Please type the number of action." << endl;
        cout << "1. Store new students Database." << endl;
        cout << "2. Load From file." << endl;
        cout << "3. Save Data." << endl;
        cout << "4. Show Database Data." << endl;
        cout << endl << "0. Exit" << endl;
        cout << "> ";
        cin >> chosen;
        switch (chosen)
        {
        case 1:
            inputData(stud_list);
            break;
        case 2:
            read((char*)"students.csv", stud_list);
            break;
        case 4:
            showAll(stud_list);
            break;
        case 3:
            saveToFile((char*)"students.csv", stud_list);
            break;
        case 0:
            cout << "Exiting" << endl;
            return;
        default:
            cout << "Wrong choice. Please choose again." << endl;
            break;
        }
    }
}

// Main - Program Start Point
int main()
{
    // Initialize Structure as empty structure
    stud_list.usr_count = 0;
    stud_list.list = nullptr;
    menu();
    return 0;
}


/*

Data for testing

Hrayr Stepanyan 23 8
Karen Eghiazaryan 21 31
Garik Ghazaryan 45 123

*/