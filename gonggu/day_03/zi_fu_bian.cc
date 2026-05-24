#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
const int N = 20;

unordered_map<string, int> dist;
string a,b;
int n = 0;
string x[N], y[N];

int bfs()
{
    if(a == b) return 0;
    queue<string> q;
    dist[a] = 0;
    q.push(a);

    while(q.size())
    {
        string s = q.front(); q.pop();

        if(dist[s] >= 10) return -1; // 提前剪枝
        // 变

        for(int i = 0; i < n; i++)
        {
            int pos = 0;
            while(s.find(x[i],pos) != -1)
            {
                pos = s.find(x[i],pos);
                string tmp = s.substr(0, pos) + y[i] + s.substr(pos + x[i].size());
                pos++;

                if(dist.count(tmp)) continue;
                dist[tmp] = dist[s] + 1;
                q.push(tmp);

                if(tmp == b) return dist[tmp];
            }
        }

    }

    return -1;
}

int main()
{
    cin >> a >> b;
    
    while(cin >> x[n] >> y[n]) n++;

    int ret = bfs();

    if(ret == -1) cout << "NO ANSWER!" << endl;
    else cout << ret << endl;

    return 0;
}