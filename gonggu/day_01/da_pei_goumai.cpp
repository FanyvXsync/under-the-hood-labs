#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 1e4 + 10;

vector<int> edges[N];
int n; int m; int w;
int c[N], d[N];
bool st[N];

int cnt;
int cc[N], dd[N]; 

int f[N];

void dfs(int a)
{
    st[a] = true;
    cc[cnt] += c[a];
    dd[cnt] += d[a];

    for(auto b : edges[a])
    {
        if(!st[b]) dfs(b);
    }
}

int main()
{
    cin >> n >> m >> w;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];   
    }

    for(int i = 1; i <= m; i++)
    {
        int a , b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
    {
        if(!st[i])
        {
            cnt++;
            dfs(i);
        }
    }

    for(int i = 1; i <= cnt; i++)
    {
        for(int j = w; j >= cc[i]; j--)
            f[j] = max(f[j], f[j - cc[i]] + dd[i]);
    }

    cout << f[w] << endl;

    return 0;
}