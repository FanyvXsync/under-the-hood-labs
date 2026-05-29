#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N];

int main()
{
    
    int ret = 0;
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if(a[i] == i) ret++;
    }

    if(ret == n) cout << ret << endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(a[i] != i && a[a[i]] == i)
            {
                cout << ret + 2 << endl;
                return 0;
            }
        }

        cout << ret + 1 << endl;
    }



    return 0;
}