#include <iostream>
using namespace std;

const int N = 1e4, M = 4e4 + 10;

int v[N], w[N], pos;
int f[M];


int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int a, b, c; cin >> a >> b >> c;

        int t = 1;
        while(c >= t)
        {
            pos++;
            v[pos] = t * a;
            w[pos] = t * b;
            c -= t;

            t *= 2;
        }

        if(c)
        {
            pos++;
            v[pos] = c * a;
            w[pos] = c * b;
        }
    }

    for(int i = 1; i <= pos; i++)
        for(int j = m; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + v[i]);


    cout << f[m] << endl;
    return 0;
}