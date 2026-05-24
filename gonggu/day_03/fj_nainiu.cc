#include <iostream>
using namespace std;

const int N = 5e4 + 10;
int a[N]; // 从 i 到 i + 1 演奏什么
int n,q;


int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        int b; cin >> b;
        int j = i;
        for(; j < i + b && j <= n; j++)
        {
            a[j] = i;
        }

        i = j;
    }

    a[0] = 1;
    while(q--)
    {
        int t; cin >> t;
        cout << a[t] << endl;
    }


    return 0;
}