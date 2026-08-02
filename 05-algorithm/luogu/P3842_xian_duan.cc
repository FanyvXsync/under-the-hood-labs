// 动态规划   路径类 有向无环图
// 找到性质 每一行要么从左端点要么从右端点
#include <iostream>
using namespace std;

const int N = 2e4 + 10;

int n;
int f[N], g[N];
int l[N], r[N];

int main()
{

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    f[1] = r[1] - 1 + r[1] - l[1];
    g[1] = r[1] - 1;

    for(int i = 2; i <= n; i++)
    {
        int len = r[i] - l[i] + 1;
        f[i] = min(abs(r[i] - l[i - 1]) + f[i-1], abs(r[i] - r[i - 1]) + g[i - 1]) + len;
        g[i] = min(abs(l[i] - l[i - 1]) + f[i-1], abs(l[i] - r[i - 1]) + g[i - 1]) + len;
    }

    cout << min(f[n] + n - l[n], g[n] + n - r[n]) << endl;

    return 0;
}