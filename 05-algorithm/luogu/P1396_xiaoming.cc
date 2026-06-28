#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10, M = 2e4 + 10;
int n,m,s,t;

struct node
{
    int u;
    int v;
    int w;
}e[M];  // 存边的大小

int fa[N];

bool cmp(node& x, node& y)
{
    return x.w < y.w;
}

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]); 
}

void un(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;

    if (s == t) {
    cout << 0 << endl;
    return 0;
}

    sort(e + 1, e + 1 + m, cmp);

    for(int i = 1; i <= n; i++) fa[i] = i;
    int ret = e[m].w;

    for(int i = 1; i <= m; i++)
    {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        un(u ,v);

        ret = w;

        if(find(s) == find(t)) break;
    }
    
    cout << ret << endl;
    return 0;
 }