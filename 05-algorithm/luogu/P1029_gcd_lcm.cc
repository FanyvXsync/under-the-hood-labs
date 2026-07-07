#include <iostream>
using namespace std;
typedef long long LL;
LL x,y;


LL gcd(LL a, LL b)
{
    return b == 0? a : gcd(b, a % b);
}


int main()
{
    cin >> x >> y;
    LL n = x * y;
    int cnt = 0;
    for(LL p = 1; p <= n / p; p++)
    {
        if(n % p) continue;

        LL q = n / p;
        if(gcd(p,q) == x)
        {
            cnt += 2;
            if(p == q) cnt--;
        }
    }

    cout << cnt << endl;

    return 0;
}