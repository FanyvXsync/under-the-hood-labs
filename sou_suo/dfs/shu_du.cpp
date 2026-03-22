#include <iostream>
using namespace std;

const int N = 10;
int a[N][N];
bool col[N][N], row[N][N], st[N][N][N];

bool dfs(int x, int y)
{
    if(y == 9)
    {
        x++;
        y = 0;
    }

    if(x == 9) return true;
    if(a[x][y]) return dfs(x,y+1);

    for(int i = 1; i <= 9; i++)
    {
        if(col[y][i] || row[x][i] || st[x/3][y/3][i] ) continue;
        a[x][y] = i;

        col[y][i] = row[x][i] = st[x/3][y/3][i] = true;
        if(dfs(x, y + 1)) return true;
        
        col[y][i] = row[x][i] = st[x/3][y/3][i] = false;
        a[x][y] = 0;
    }

    return false;

}

int main()
{
    for(int i = 0; i < 9 ; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
            if(a[i][j]) 
            {
                col[j][a[i][j]] = true;
                row[i][a[i][j]] = true;

                st[i / 3][ j / 3][a[i][j]] = true;
            }
        }
    }


    dfs(0,0);

   for(int i = 0; i < 9 ; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << a[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}