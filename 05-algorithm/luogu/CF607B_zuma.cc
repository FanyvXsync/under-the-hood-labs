#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;

int a[N];
int f[N][N];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    memset(f, 0x3f ,sizeof f);
    
    for(int i = 1; i <= n; i++) f[i][i] = 1;

    for(int i = 1; i + 1 <= n; i++)
    {
        int j = i + 1;
        if(a[i] == a[j]) f[i][j] = 1;
        else  f[i][j] = 2;
    }


    for(int len = 3; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;

            for(int k = i; k < j; k++)
            {
                f[i][j] = min(f[i][j], f[k + 1][j] + f[i][k]);
            }

            if(a[i] == a[j]) f[i][j] = min(f[i][j], f[i + 1][j - 1]);

        }
    }


    cout << f[1][n] << endl;

    return 0;
}