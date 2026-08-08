// 次短路  严格
// 找出可能是次短路中最小的那个 枚举所有的边
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int , int> PII;
const int N = 5010, M = 1e5 + 10, INF = 0x3f3f3f3f;

int n, m;
struct node
{
    int a,b,c;
}e[M];  // 存边

int f[N], g[N];
bool st[N];
vector<PII> edges[N];

void dijkstra(int s, int dist[])
{
    memset(st, 0, sizeof st);

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    dist[s] = 0;

    while(heap.size())
    {
        int a = heap.top().second;  heap.pop();
        if(st[a]) continue;

        st[a] = true;
        for(auto& e: edges[a])
        {
            int b = e.first, c = e.second;
            if(dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                heap.push({dist[b], b});
            }
        }
        

    }

}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b , c;  cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
        e[i] = {a, b, c};
    }
    
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);

    dijkstra(1, f);
    dijkstra(n, g);

    int ret = 0x3f3f3f3f;
    for(int i = 1; i <= m; i++)
    {
        int a = e[i].a, b = e[i].b, c = e[i].c;
        int len1 = f[a] + c + g[b];
        int len2 = f[b] + c + g[a];

        if(len1 > f[n]) ret = min(ret, len1);
        if(len2 > f[n]) ret = min(ret, len2);
    }

    cout << ret << endl;
    
    return 0;
}