#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;

int n , m;
int a[N][N];

bool st[N][N];
int l[N][N], r[N][N];

int dx[] = { 0 , 0, 1, -1};
int dy[] = { 1, -1, 0, 0 };

void dfs(int i, int j)
{
    st[i][j] = true;
    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if(x < 1 || x > n || y < 1 || y > m || a[x][y] >= a[i][j]) continue;

        if(!st[x][y]) dfs(x, y); //  注意这里不能continue

        l[i][j] = min(l[i][j], l[x][y]);
        r[i][j] = max(r[i][j], r[x][y]);

    }
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];


    //初始化
    memset(l, 0x3f, sizeof l);
    for(int j = 1; j <= m; j++) 
        l[n][j] = r[n][j] = j;

    //
    for(int j = 1; j <= m; j++)
        if(!st[1][j])  dfs(1,j);

    int cnt = 0;
    for(int j = 1; j <= m; j++)
        if(!st[n][j]) cnt++;

    if(cnt) 
    {
        cout << 0 << endl << cnt << endl;
        return 0;
    }

    // 区间覆盖
    int x = 1;
    while(x <= m)
    {
        int right = 0;
        for(int i = 1; i <= m; i++)
            if(l[1][i] <= x) 
                right = max(right, r[1][i]);
        
        cnt++;
        x = right + 1;
    }

    cout << 1 << endl << cnt << endl;
    return 0;
}