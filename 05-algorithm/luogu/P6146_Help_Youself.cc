#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10, MOD = 1e9 + 7;
typedef long long LL;


int n;
struct node
{
    int l, r;
}a[N];

LL f[N], s[N + N];


bool cmp(node& x, node& y)
{
    return x.l < y.l;
}

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }

    return ret;
}


int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
        s[a[i].r]++;
    }



    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n + n; i++) s[i] += s[i - 1];

    

    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 1] + qpow(2, s[a[i].l - 1], MOD);
        f[i] %= MOD;
    }
    
    cout << f[n] << endl;

    return 0;
}