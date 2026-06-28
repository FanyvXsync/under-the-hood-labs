#include <iostream>
using namespace std;
const int N = 10;

int a[N][N];
bool vis[N][N];
int n,m,t;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0 , 0};

int sx, sy, fx, fy;
int ret;
int path;

void dfs(int x, int y)
{
    if(x == fx && y == fy)
    {
        ret++;
        return;
    }

    for(int k = 0; k < 4; k++)
    {
        int i = x + dx[k];
        int j = y + dy[k];

        if(i >= 1 && j >= 1 && i <= n && j <= m && a[i][j] == 0 && vis[i][j] == false)
        {
            vis[i][j] = true;
            dfs(i,j);

            vis[i][j] = false;
        }
    }
}


int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;

    while(t--)
    {
        int x,y; cin >> x >> y;
        a[x][y] = 1;
    }

    vis[sx][sy] = true;

    dfs(sx, sy);

    cout << ret << endl;

    return 0;
}