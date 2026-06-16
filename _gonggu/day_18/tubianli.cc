#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n , m;
int ret[N];
vector<int> edges[N];


void dfs(int u, int r)
{
    ret[u] = r;

    for(auto v : edges[u])
    {
        if(ret[v]) continue;
        dfs(v , r);
    }
}


int main()
{
    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int a , b; cin >> a >> b;
        edges[b].push_back(a);
    }

    for(int i = n; i >= 1; i--)
    {
        if(ret[i]) continue;
        dfs(i, i);
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ret[i] << " ";
    }

    return 0;
}