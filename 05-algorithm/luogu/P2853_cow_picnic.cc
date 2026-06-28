#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1010;

int k,n,m;
int a[N];
vector<int> edges[N];

int cnt[N];
bool st[N];

void dfs(int u)
{
    st[u] = true;
    cnt[u]++;

    for(auto e: edges[u])
    {
        if(!st[e]) dfs(e);
    }
}


int main()
{
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i++) cin >> a[i];

    for(int i = 1; i <= m; i++)
    {
        int x, y;  cin >> x >> y;
        edges[x].push_back(y);
    }

    for(int i = 1; i <= k; i++)
    {
        memset(st, 0, sizeof st);
        dfs(a[i]);
    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == k) ret++;
    }

    cout << ret << endl;

    return 0;
}