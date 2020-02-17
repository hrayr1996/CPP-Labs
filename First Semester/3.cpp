#include <iostream>

using namespace std;

struct student {
    char* name;
    char* lastname;
    unsigned age;
};

struct Students {
    student* list;
    int count;
};

// get single student data from command line
struct student inputSingle()
{
    student s;
    
    cout << "Input Student Information splitted by space (Name Lastname Age): " << endl;
    s.name = new char[25];
    s.lastname = new char[36];
    cin >> s.name >> s.lastname >> s.age;

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
    studlist.count = si;
    studlist.list  = s;
}


// anun azganun-i mej gone 2 mianman tar
bool findChaA(char* s, char* d)
{
    int count = 0;
    for(int i=0;i < sizeof(s); i++)
    {
        if(s[i] == '\0')
        {
            break;
        }
        if(s[i] == 'a')
        {
            return true;
        }
        
    }
    
    for(int i=0;i < sizeof(d); i++)
    {
        if(d[i] == '\0')
        {
            break;
        }
        if(d[i] == 'a')
        {
            return true;
        }
        
    }
    return false;
}

int main()
{
    Students studlist;
    inputData(studlist);
    student s;
    for(int i=0; i < studlist.count; i++)
    {
        s = studlist.list[i];
        if(findChaA(s.name, s.lastname))
        {
            cout << s.age << endl;
        }
    }
    return 0;
}