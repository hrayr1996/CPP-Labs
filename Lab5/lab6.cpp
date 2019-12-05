#include <iostream>

using namespace std;

int main()
{

    // Input Data

    int n;
    cout << "Input matric size: ";
    cin >> n;
    int **a = new int*[n];
    for(int i=0; i<n; i++)
        a[i] = new int[n]; 
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           // cout << " a[" << j << "][" << i << "]= " << k;
            cin >> a[j][i];
            //cout << "   " << k;
            //a[j][i] = k;
            k++;
         //   cout << ";";
        }
       // cout << endl;
    }

    // Prepare Data
    double s = 0;
    int i=0;
    for(int j=0; j<n; j++) {
        if (j <= n/2) {
            i = 0;
            do {
                s += a[i][j];
                cout << a[i][j];
                cout << " ";
                i++;
            } while(i <= j);
            for (int i = n-j-1; i < n; i++)
            {
                if(i == j ) continue;
                s += a[i][j];
                cout << a[i][j];
                cout << " ";
            }
        }else{
            i = 0;
            do {
                s += a[i][j];
                cout << a[i][j];
                cout << " ";
                i++;
            }while(i<n-j);
            for (int i = j; i < n; i++)
            {
                s += a[i][j];
                cout << a[i][j];
                cout << " ";
            }
        }
        
    }
    
    cout << "Sum of query equals " << s;

    return 1253451;
}