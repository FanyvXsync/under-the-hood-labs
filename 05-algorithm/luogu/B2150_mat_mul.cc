#include <iostream>
using namespace std;

const int N = 110;
int n,m,s;
int a[N][N], b[N][N], c[N][N];


void mul()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
           for(int k = 1; k <= m; k++)
            c[i][j] += a[i][k] * b[k][j];
        }
    }
}

int main()
{
    cin >> n >> m >> s;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            cin >> b[i][j];
        }
    }

    mul();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            cout << c[i][j] << " ";
        }

        cout << endl;
    }


    return 0;
}