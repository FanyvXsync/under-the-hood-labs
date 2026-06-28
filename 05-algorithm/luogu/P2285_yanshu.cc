#include <iostream>
using namespace std;
const int N = 1010;

int n,m;
int dist[N][N];
int ret; int path;
int dx[] = { 0 , 0 , 1 ,-1};
int dy[] = { 1 , -1 , 0 ,0};
int tim;

void dfs(int i, int j, int tim)
{
    if(i < 0 || j < 0 || i > n || j > n )
    {
        ret = max(ret, path);
        return ;
    }

    if(tim == dist[i][j]) ret++;

    for(int k = 0; k < 4; k++)
    {   
        int a = i + dx[k],  b = j + dy[k];
        dfs(a, b, tim + 1);
    }
    

}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int t, x, y; cin >> t >> x >> y;
        dist[x][y] = t;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dfs(i ,j, 1);
        }
    }

    cout << ret << endl;

    return 0;
}