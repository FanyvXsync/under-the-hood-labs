// 找规律 + 扩欧

#include  <iostream>
using namespace std;

typedef long long LL;

LL qmul(LL a, LL b, LL p)
{
    LL ret = 0;
    while(b)
    {
        if( b & 1 ) ret = (ret + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }

    return ret;
}

LL qpow(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = qmul(ret, a , p);
        b >>= 1;
        a = qmul(a, a, p); 
    }

    return ret;
}

void exgcd(LL a, LL b, LL& x, LL& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return;
    }

    LL x1, y1;
    exgcd(b, a % b, x1, y1);

    x = y1; y = x1 - a/b * y1;
}


int main()
{

    LL n, m, l; cin >> n >> m >> l;

    LL a = qpow(2, m, n + 1);
    LL b = n + 1, c = l, x , y;

    exgcd(a, b, x, y);
    x = (x % b + b) % b;

    cout << qmul(x, c, b) << endl;
    
    return 0;
}