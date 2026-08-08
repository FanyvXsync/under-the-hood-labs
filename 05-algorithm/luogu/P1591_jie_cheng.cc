#include <iostream>
using namespace std;

const int N = 1010, M = 3000;

int f[N][M];

void mul(int c[], int a[], int x)
{
    int t = 0;
    for(int i = 0; i < M; i++)
    {
        t = a[i] * x + t;
        c[i] = t % 10;
        t = t / 10;
    }
}


void init()
{
    f[0][0] = 1;
    for(int i = 1; i <= 1000; i++)
    {
        mul(f[i], f[i - 1], i);
    }
}

int main()
{
    init();

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;

        int pos = M - 1;
        while(!f[n][pos]) pos--;

        int cnt = 0;
        for(int i = pos; i >= 0; i--)
        {
            if(f[n][i] == m) cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}