#include <iostream>
using namespace std;

const int N = 1e4 + 10;

int n,k;
int a[N];
int f[N];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        int t = a[i];
        for(int j = i - 1; j >= 0 && i - j <= k; j--)
        {
            f[i] = max(f[i],  f[j] + t * (i - j));
            t = max(t, a[j]);
        }
    }

    cout << f[n] << endl;

    return 0;
}