#include <iostream>
#include <string>
using namespace std;

// Single Student Data structure
struct student {
    char* name;
    char* lastname;
    int age;
    int avrgR;
};

// Student List Data Structure
struct Students {
    struct student *list;
    int usr_count;
};


// anun azganun-i mej gone 2 mianman tar
bool findSameChar(char* s, char* d)
{
    int count = 0;
    for(int i=0;i < sizeof(s); i++)
    {
        if(s[i] == '\0')
        {
            break;
        }
        for (int j=0; j < sizeof(d); j++)
        {
            if(s[i] == '\0')
            {
                break;
            }
            if(s[i] == d[j])
            {
                count++;
            }
            if(count >= 2)
            {
                return true;
            }
        }
    }
    return false;
}


// Find out that '(int)a' is a Prime number
bool only2(int a)
{
    float cond = ((float)a)/2;
    for (int i = 2; i < cond; i++)
    {
        if(a % i == 0)
            return false;
    }
    
    return true;
}

// get single student data from command line
struct student inputSingle()
{
    student s;
    
    cout << "Input Student Information splitted by space (Name Lastname Age AvarageRating): " << endl;
    s.name = new char[25];
    s.lastname = new char[36];
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

// Given Problem Condition
void SolveProblem(Students &s)
{
    int count = 0;
    for (int i = 0; i < s.usr_count; i++)
    {
        if(only2(s.list[i].age + s.list[i].avrgR) && findSameChar(s.list[i].name, s.list[i].lastname))
        {
            showSingle(s.list[i]);

            count++;
        }
    }

    if(count == 0)
    {
        cout << "Sorry, In given list we have got no Student with given conditions." << endl << "Try Again with other user information";
    }
}

// Main - Program Start Point
int main()
{
    Students stud_list;

    inputData(stud_list);

    showAll(stud_list);

    cout << "Problem solving is in process. Wait and see answer below. " << endl;

    SolveProblem(stud_list);

    return 0;
}


/*

Data for testing

Hrayr Stepanyan 3 8
Karen Eghiazaryan 27 31
Garik Ghazaryan 4 7

*/