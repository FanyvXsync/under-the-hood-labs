#include <iostream>
#include <algorithm>
using namespace std;
const int N = 6010;


int n;
int fa[N], cnt[N];

struct node
{
    int x, y, z;
}e[N];


bool cmp(node& x, node& y)
{
    return x.z < y.z;
}

int find(int x)
{
    return fa[x] == x? x : fa[x] = find(fa[x]);
}
int kk()
{
    for(int i = 1; i <= n; i++) 
    {
        fa[i] = i;
        cnt[i] = 1;
    }

    sort(e + 1, e + n, cmp);

    int ret = 0;
    for(int i = 1; i < n; i++)
    {
        int fx = find(e[i].x), fy = find(e[i].y), z = e[i].z;
        if(fx == fy) continue;

        ret += (cnt[fx] * cnt[fy] - 1) * (z + 1);
        fa[fx] = fy; 
        cnt[fy] += cnt[fx];
    }

    return ret;

}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i < n; i++) cin >> e[i].x >> e[i].y >> e[i].z;
    
        cout << kk() << endl;
    }
    
    return 0;
}