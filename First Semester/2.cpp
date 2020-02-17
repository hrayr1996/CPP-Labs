#include <iostream>

using namespace std;

int main()
{
    char* n = new char[100];
    int k = 0;
    cout << "Input symbols count: ";
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cout << "n[" << i << "]: ";
        cin >> n[i];
    }

    for(int i = 0; i < k; i++)
    {
        if(n[i] >= 'A' && n[i] <= 'Z')
        {
            cout << n[i] << endl;
        }
    }

    return 0;
}