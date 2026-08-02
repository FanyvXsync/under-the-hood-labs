// 多个数组多维护一些信息    走到 x % n, y % n , i , j
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1510;

int n, m, x1, y1;
char g[N][N];
bool st[N][N];
int prevx[N][N], prevy[N][N];

int dx[] = { 0 , 0 , 1 , -1};
int dy[] = {1 , -1, 0 , 0};

bool dfs(int x, int y)
{
    int i = (x % n + n )%n, j = (y % m + m) % m;
    if(st[i][j] && (prevx[i][j] != x || prevy[i][j] != y)) return true;
    if(st[i][j] && (prevx[i][j] == x && prevy[i][j] == y)) return false;

    st[i][j] = true;
    prevx[i][j] = x;
    prevy[i][j] = y;


    for(int k = 0; k < 4; k++)
    {
        int a = x + dx[k], b = y + dy[k];
        int pa = (a % n + n )%n, pb= (b%m + m) %m;
        if(g[pa][pb] == '#') continue;

        
        if(dfs(a, b)) return true;

    }

    return false;
}

int main()
{
   

    while(cin >> n >> m)
    {
        
        memset(st, 0, sizeof st);
        memset(prevx, 0, sizeof prevx);
        memset(prevy, 0, sizeof prevy);
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                if(g[i][j] == 'S') x1 = i, y1 = j;
            }
        }

        if(dfs(x1, y1)) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    

    return 0;
}