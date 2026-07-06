// 求最小公倍数 最大公因数乘最小公倍数对等于两个数的乘积

#include <iostream>
using namespace std;
typedef long long LL;
LL a, b, c;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b)
{
    return a / gcd(a, b) * b; // 防溢出
}

int main()
{
    cin >> a >> b >> c;

    cout << lcm(lcm(a,b), c) << endl;
    return 0;
}