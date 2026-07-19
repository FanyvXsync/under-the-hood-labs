// 性质
// 第 n 项卡特兰数  一个操作大于等于另一个操作，求方案数
// 质因子计数法      
// 5. 模数不是植树 手算
#include <iostream>
using namespace std;
typedef long long LL;


const int N = 2e6 + 10;

int p[N], m;
int cnt[N];
int mp[N];
bool st[N];

void get_prime(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i]) p[++m] = i;

        for(int j = 1; 1ll * i * p[j] <= n; j++)
        {
            st[i * p[j]] = true ;
            mp[i * p[j]] = p[j];

            if(i % p[j] == 0) break;
        }


    }
}


LL qpow(LL a, LL b, LL mod)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1)ret = ret * a % mod;
        b >>= 1;
        a = a * a % mod;
    }

    return ret;
}

int main()
{
    int n, mod; cin >> n >> mod;
    get_prime(n + n);

    for(int i = 2; i <= n ;i++) cnt[i] = -1;
    for(int i = n + 2; i <= n + n; i++) cnt[i] = 1;

    for(int i = n + n; i >= 2; i--)
    {
        if(mp[i])
        {
            cnt[mp[i]] += cnt[i];
            cnt[ i / mp[i]] += cnt[i];

            cnt[i] = 0;
        }
    }

    LL ret = 1;

    for(int i = 2; i <= n + n; i++)
    if(cnt[i]) ret = ret * qpow(i, cnt[i], mod) % mod;

    cout << ret << endl;

    return 0;
}