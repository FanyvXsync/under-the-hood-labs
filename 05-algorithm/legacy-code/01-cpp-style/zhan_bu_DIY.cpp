#include <iostream>

using namespace std;
const int N = 15, M = 6;

int n = 13, m = 4;
int a[N][M];
int cnt[N];

void dfs(int x)
{
    if( x == 13 ) return ;

    int t = a[x][cnt[x]];
    cnt[x]--;
    dfs(t);
}

int main()
{
    for(int i = 1; i <= n; i++)
    {
        cnt[i] = 4;
        for(int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if(ch >= '2' && ch <= '9') a[i][j] = ch - '0';
            else if(ch == 'A') a[i][j] = 1;
            else if(ch == 'J') a[i][j] = 11;
            else if(ch == 'Q') a[i][j] = 12;
            else if(ch == 'K') a[i][j] = 13;
            else if(ch == '0') a[i][j] = 10;
        }
    }

    for(int i = 1; i <= m ; i++)
    {
        dfs(a[n][i]);
    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 0) ret++; 
    }

    cout << ret << endl;

    return 0;
}