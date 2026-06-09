#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 25;

int a[N];

vector<int> edges[N];
int n; int ret; int ps;
vector<int> path;

void dfs(int i)
{
    path.push_back(i);
    
    for(auto e: edges[i])
    {
        
        if(e > i) ps += a[e];

        if(ps >= ret)
        {
            path.push_back(e);
            ret = ps;
        }        
        
        dfs(e);
        ps -= a[e];
        path.pop_back();
    }
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            int x;  cin >> x;
            if(x) edges[i].push_back(j);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        dfs(i);
    }

    for(auto p: path)
    {
        cout << p << " ";
    }
    puts("");

    cout << ret << endl;
    return 0;
}

