#include <iostream>
using namespace std;

const int N = 5e6 + 10;

int a[N];
int f[N];
int n, p;

int main()
{
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
    {
        cin >>  a[i];
        f[i] = a[i] - a[i - 1];
    }

    while(p--)
    {
        int x, y, z; cin >> x >> y >> z;
        f[y + 1] -= z;
        f[x] += z;
    }

    int ret = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i] + f[i - 1];
        ret = min(ret, f[i]);
    }

    cout << ret << endl;

    return 0;
}