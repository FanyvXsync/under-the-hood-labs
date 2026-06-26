#include <iostream>

using namespace std;
int n;
const int N = 15;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int arr[N][N];

int main ()
{
    cin >> n;
    int x=1,y=1;
    int cnt = 1;
    int pos = 0;

    while(cnt <= n*n)
    {
        arr[x][y] = cnt;

        int a = x + dx[pos];
        int b = y + dy[pos];

        if(a<1||a>n||b<1||b>n||arr[a][b])
        {
            pos = (pos+1) % 4;
            a = x + dx[pos];
            b = y + dy[pos];
        }

        x = a;
        y = b;
        cnt++;

    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%3d", arr[i][j]);
        }
        puts("");
    }

    return 0;

}
