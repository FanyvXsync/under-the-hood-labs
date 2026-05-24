#include <iostream>
using namespace std;
const int N = 2e6 +  10;
typedef long long LL;

int c[N],a[N];
int f[N][N];
int n , m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> c[i] >> a[i];

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= a[i]; k++)
            {
                f[i][j] = min(f[i][j] , f[i][j - k] + k*c[i]);
            }
        }
    }

    int ret = 0;

    for(int i = 1; i <= m; i++)
    {
        ret = min(ret, f[i][n]);
    }
    
    cout << ret << endl;

    return 0;

}
