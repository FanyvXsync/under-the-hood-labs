#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2010, M = 2e6 + 10;
int n,c,m;
int x[N], y[N];
int fa[N];

struct node
{
    int u; 
    int v;
    int w;
}e[M];

int calc(int i, int j)
{
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

bool cmp(node& x, node& y)
{
    return x.w < y.w;
}

int find(int x)
{
    return fa[x] == x? x : fa[x] = find(fa[x]);
}

int main()
{
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int t = calc(i, j);
            if(t >= c)
            {
                m++;
                e[m] = {i, j, t};
            }
        }
    }

    for(int i = 1; i <= n; i++) fa[i] = i;

    sort(e + 1, e + 1 + m, cmp);
    int ret = 0;
    int cnt = 0;
    for(int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int fu = find(u);
        int fv = find(v);
        if(fu == fv) continue;

        ret += w;
        cnt++;
        fa[fu] = fv;

        if(cnt == n - 1) break;
    }

    if(cnt == n - 1) cout << ret << endl;
    else cout << -1 << endl;
 
    return 0;
}