#include <iostream>
using namespace std;
const int N = 1010;
int n,m,c;
int a[N][N];
int f[N][N];

int main()
{
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= m; j++)
        {
            int x; cin >> x;
            f[i][j] = f[i-1][j] + f[i - 1][j] - f[i-1][j-1] + a[i][j];
            
        }
    }
    return 0;
}