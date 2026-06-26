#include <iostream>
using namespace std;
typedef long long LL;

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b&1) ret = ret * a % p;
        a = a * a % p;
        b = b >> 1;
    }

    return ret;
}

int main()
{
    LL a ,b, p;
    cin >> a >> b >> p;

    LL ret = qpow(a,b,p);
    printf("%lld^%lld mod %lld=%lld",a,b,p,ret);
    return 0;
}