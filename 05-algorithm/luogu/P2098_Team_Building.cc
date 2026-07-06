#include <iostream>
using namespace std;

const int N = 1010, M = 15, MOD = 1e9 + 9;

int n,m,p;
int a[N],b[N];
int f[N][N][M];

int main()
{
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            f[i][j][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            for(int k = 1; k <= p; k++)
            {
                f[i][j][k] = (f[i - 1][j][k] + f[i][j - 1][k]) % MOD - f[i - 1][j - 1][k];
                f[i][j][k] = (f[i][j][k] % MOD + MOD) % MOD;
                if(a[i] > b[j])
                f[i][j][k] = (f[i - 1][j - 1][k - 1] + f[i][j][k]) % MOD;
            }
        }
    }

    cout << f[n][m][p] << endl;

    return 0;
}