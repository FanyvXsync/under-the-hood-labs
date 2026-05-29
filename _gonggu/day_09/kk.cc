#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 1510;

vector<PII> edges[N];
int in[N];
int f[N];
int n , m;



int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int u , v ,m;  cin >> u >> v >> m;
        edges[u].push_back({v, m});
        in[v]++;
    }

    queue<int> q;
    
    for(int i = 2; i <= n; i++)
    {
        if(in[i] == 0) q.push(i);
        f[i] = -1e9;
    }

    while(q.size())
    {
        auto u = q.front(); q.pop();

        for(auto& e: edges[u])
        {
            int v = e.first;
            in[v]--;

            if(in[v] == 0) q.push(v);
        }    
    }

    q.push(1);

    while(q.size())
    {
        auto u = q.front(); q.pop();

        for(auto& e : edges[u])
        {
            int v = e.first; int m = e.second;
            f[v] = max(f[u] + m, f[v]);

            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }

    if(f[n] == -1e9) cout << -1 << endl;
    else cout << f[n] << endl;
    
    return 0;
}