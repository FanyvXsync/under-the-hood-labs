#include <iostream>
using namespace std;

const int N = 1e4 + 10;

int ret ; int p;
char f[N][N];

char dfs(int x, int y)
{
    if(f[x][y]) return f[x][y];
    f[x][y] = '3';
    
    
    if(x == 0) return f[x][y] = '1';
    if(y == 0) return f[x][y] = '2';

    return f[x][y] = dfs((x+y)%p , (x+2*y) %p);
}

int main()
{
    int T; cin >> T >> p;

    while(T--)
    {
        int x,y;
        cin >> x >> y;
        int ret = dfs(x, y);

        if(ret == '1') cout << 1 << endl;
        else if( ret == '2') cout << 2 << endl;
        else cout << "error" << endl;
 
    }

    return 0;
}