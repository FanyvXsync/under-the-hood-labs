#include <iostream>
using namespace std;
typedef long long LL;

const int mod = 20100403;

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b&1)ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    } 
    return ret;

}

LL C(int n, int m)
{
    if(n < m) return 0;

    LL up = 1, down = 1;
    for(int i = n - m + 1; i <= n; i++) up = up * i % mod;
    for(int i = 2; i <= m; i++) down = down * i % mod;

    return up * qpow(down, mod - 2, mod) % mod;
}

int main()
{
    int n, m ; cin >> n >> m;
    LL ret = C(n + m, n) - C(n + m, m - 1);

    cout << ((ret % mod) + mod) % mod << endl;

}