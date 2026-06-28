#include <iostream>
#include <algorithm>
using namespace std;
const int N = 410;
const int M = 4e4 + 10;

struct node
{
    int a;
    int h;
    int c;
}a[N];

int f[M];


bool cmp(node& x, node& y)
{
    return x.a < y.a;
}

int main()
{
    int n;  cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].h >> a[i].a >> a[i].c;
    }

    sort(a + 1, a + 1 + n, cmp);

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = a[i].a; j >= 0; j--)
        {
            for(int k = 0; k <= a[i].c && k * a[i].h <= j; k++)
            {
                f[j] = max(f[j],  f[j - k * a[i].h] + k * a[i].h);
            }

            ret = max(ret, f[j]);
        }
    }

    cout << ret << endl;
    return 0;
}