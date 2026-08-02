#include <iostream>
#include <cstring>
using namespace std;

const int N = 20;
int a[N][N];

int d[N][N], s[N];
int f[N][N];

bool st[N];

int n, m, r, c;
int ret = 1e9;

void dp()
{
    memset(d, 0, sizeof d);
    memset(s, 0, sizeof s);
    memset(f, 0x3f, sizeof f);

    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            for (int k = 1; k <= n; k++)
                if (st[k])
                    d[i][j] += abs(a[k][i] - a[k][j]);

    int prev = 0;

    for (int i = 1; i <= n; i++)
    {
        if (st[i])
        {
            for(int j = 1; j <= m; j++)
            if (prev)
                s[j] += abs(a[prev][j] - a[i][j]);
            prev = i;
        }
    
    }

    for(int i = 1; i <= m; i++)
    {
        f[i][1] = s[i];
        for(int j = 2; j <= c; j++)
        {
            for(int k = 1; k < i; k++)
            f[i][j] = min(f[i][j], f[k][j - 1] + d[k][i] + s[i]);
        }
    }

    for(int i = 1; i <= m; i++) ret = min(ret, f[i][c]);

}

void dfs(int pos, int cnt)
{
    if (cnt == r)
    {
        dp();
        return;
    }

    if (pos == n + 1)
        return;

    st[pos] = true;
    dfs(pos + 1, cnt + 1);

    st[pos] = false;
    dfs(pos + 1, cnt);
}

int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    dfs(1, 0);

    cout << ret << endl;

    return 0;
}