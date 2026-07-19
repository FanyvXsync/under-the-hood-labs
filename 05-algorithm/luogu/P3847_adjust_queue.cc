// 区间dp
#include <iostream>
using namespace std;

const int N = 3010;

int n;
int a[N];
int f[N][N];

int main()
{
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if(a[i] == a[j]) f[i][j] = f[i + 1][j - 1];
            else
            {
                f[i][j] = min(min(f[i + 1][j], f[i][j - 1]), f[i+1][j - 1]) + 1;
            }
        }
    }

    cout << f[1][n] << endl;

    return 0;
}
