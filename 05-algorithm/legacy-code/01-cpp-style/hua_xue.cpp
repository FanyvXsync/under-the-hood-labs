#include <iostream>
using namespace std;

const int N = 110;

int r,c;
int dx[] = { 0 , 0, 1 , -1};
int dy[] = { 1 , -1 , 0, 0};

int ret = 1;
int s[N][N];
int f[N][N];

int dfs(int x, int y)
{
    if(f[x][y]) return f[x][y];

    int len = 1;
    for(int k = 0; k < 4 ; k++)
    {
        int a = x + dx[k], b = y + dy[k];
        if(a < 1 || a > r || b < 1 || b > c) continue;
        if(s[x][y] <= s[a][b]) continue;
        len = max(dfs(a,b) + 1 , len);
    }

    return f[x][y] = len;

}

int main()
{
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> s[i][j];

    
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            ret = max(dfs(i,j), ret);
    
    cout << ret << endl;
    return 0;
}
