#include <iostream>
using namespace std;

const int N = 3e4 + 10;
const int M = 30;

int n,m;
int f[N];
int v[M], p[M];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> v[i] >> p[i];

    for(int i = 1; i <= m; i++)
    {
        for(int j = n; j >= v[i]; j--)
        {
            f[j] = max(f[j] , f[j - v[i]] + v[i]*p[i]);
        }
    }

    cout << f[n] << endl;

    

    return 0;
}