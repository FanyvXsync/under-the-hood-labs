// 最小生成树   挑 k 个连通块
// 挑的边的个数和连通块的个数加起来是 n （n条边的n）
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e3 + 10, M = 1e4 + 10;

int n, m , k;

struct node
{
    int a, b, c;
}e[M];  // 存边就好

int fa[N];


bool cmp(node& x, node& y)
{
    return x.c < y.c;
}

int find(int x)
{
    return fa[x] == x? x : fa[x] = find(fa[x]);
}

void kk()
{
    sort(e + 1, e + 1 + m, cmp);
    for(int i = 1; i <= n; i++) fa[i] = i;

    int cnt = 0; int ret = 0;
    for(int i = 1; i <= m; i++)
    {
        int x = e[i].a, y = e[i].b, l = e[i].c;

        int fx = find(x);
        int fy = find(y);

        if(fx == fy) continue;

        cnt++;
        ret += l;
        fa[fx] = fy;

        if(cnt == n - k) break;
    }

    if(cnt == n - k) cout << ret << endl;
    else cout << "No Answer" << endl;

}


int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) cin >> e[i].a >> e[i].b >> e[i].c;
    
    kk();
    
    return 0;
}