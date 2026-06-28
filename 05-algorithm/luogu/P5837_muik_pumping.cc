#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
typedef pair<int,int> PII;
const int N = 1010, M = 1e6;

int f[N][N]; // 流量  结构体也行
vector<PII> edges[N];

bool st[N];
int dist[N];
int n,m;

int dijkstra(int x)
{
    memset(st, 0 , sizeof st);
    memset(dist, 0x3f, sizeof dist);

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;

    while(heap.size())
    {
        auto t = heap.top(); heap.pop();
        int a = t.second;

        if(st[a]) continue;
        st[a] = true;

        for(auto& e : edges[a])
        {
            int b = e.first; int c = e.second; int d = f[a][b];
            if(d < x) continue;
            
            if(dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                heap.push({dist[b], b});
            }
        }

        
    }

    return dist[n];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b,c,d; cin >> a >> b >> c >> d;
        f[a][b] = f[b][a] = d;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    } 
    
    int ret = 0;
    for(int i = 1; i <= 1000; i++)
    {
        ret = max(ret, M * i / dijkstra(i));
    }

    cout << ret << endl;
    return 0;
}
