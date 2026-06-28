#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010;
typedef long long LL;

int a[N][N];
LL f[N][N], g[N][N];

int n,m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    memset(f, -0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);

    f[0][1] = 0;
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            f[i][j] = max(f[i - 1][j], max(f[i][j - 1], g[i][j - 1])) + a[i][j];
        }

        for(int i = n; i >= 1; i--)
        {
            g[i][j] = max(g[i + 1][j], max(f[i][j - 1], g[i][j - 1])) + a[i][j];
        }

    }

    cout << f[n][m] << endl;

    return 0;
}