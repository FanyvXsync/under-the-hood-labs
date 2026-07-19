// 二分 + 01bfs (单调不递减)
#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;
const int N = 1e4 + 10;
typedef pair<int,int> PII;

vector<PII> edges[N];

int dist[N];
bool st[N];

int n , p , k;

bool check(int mid)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    deque<int> q;
    q.push_back(1);
    dist[1] = 0;

    while(q.size())
    {
        int a = q.front(); q.pop_front();
        if(st[a]) continue;
        st[a] = true; // 来到 a 这个点一定是最短路径了

        for(auto& t: edges[a])
        {
            int b = t.first, c = t.second > mid ? 1 : 0;

            if(dist[a] + c < dist[b])
            {
                dist[b] = dist[a] + c;
                if(c) q.push_back(b);
                else q.push_front(b);
            }

           
        }


        return dist[n] <= k;
    }
}


int main()
{
    cin >> n >> p >> k;
    for(int i = 1; i <= p; i++)
    {
        int a , b , c;  cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }

    int l = 0, r = 1e6;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid + 1;
    }

    if(dist[n] == 0x3f3f3f3f) cout << -1 << endl;
    else cout << l << endl; 

    return 0;
}