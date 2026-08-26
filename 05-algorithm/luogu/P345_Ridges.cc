#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N];
bool st[N][N];
bool up,down;

int n; 

int dx[] = { 0 , 0, 1, -1, 1, 1, -1, -1};
int dy[] = { 1, -1, 0 , 0, 1, -1, 1 , -1};

void dfs(int i, int j)
{
    st[i][j] = true;
    for(int k = 0; k < 8; k++)
    {
        int x = i + dx[k] , y = j + dy[k];
        if(x < 1 || x > n || y < 1 || y > n) continue;

        if(a[x][y] > a[i][j]) up = false;
        else if(a[x][y] < a[i][j]) down = false;
        else if(!st[x][y]) dfs(x, y);

    }

}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    int c1 = 0 , c2 = 0;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(st[i][j]) continue;

            up = down = true;
            dfs(i, j);
            if(up) c1++;
            if(down) c2++;
        }
    }

    cout << c1 << " " << c2 << endl;
    return 0;
}