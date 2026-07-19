// 离线查询 第一次
#include <iostream>
#include <algorithm>
using namespace std;


const int N = 1e5 + 10;
int n,q;

struct node
{
    int x,y,z;
}a[N], b[N];

int fa[N], cnt[N], ret[N];


bool cmp(node& x, node& y)
{
    return x.z > y.z;
}

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> b[i].z >> b[i].y;
        b[i].x = i;
    }

    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + q, cmp);


    for(int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cnt[i] = 1;
    }

    int pos = 1;
    for(int i = 1; i <= q; i++)
    {
        int k = b[i].z, u = b[i].y;

        while(pos < n && a[pos].z >= k)
        {
            int x = a[pos].x, y = a[pos].y;

            int fx = find(x), fy = find(y);

            if(fx != fy)
            {
                fa[fx] = fy;
                cnt[fy] += cnt[fx];

                pos++;
            }

            
            
        }

        //
        ret[b[i].x] = cnt[find(u)] - 1;
    }

    for(int i = 1; i <= q; i++) cout << ret[i] << endl;

    return 0;
}