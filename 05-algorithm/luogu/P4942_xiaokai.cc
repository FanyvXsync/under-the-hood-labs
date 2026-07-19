// 秦九韶 2345   89101112
// 后面 10 是两位数 乘一百
// 等差数列的求和

#include <iostream>
using namespace std;
typedef long long LL;

LL q;
LL l, r;

int main()
{
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        LL x = l + r, y = r - l + 1;

        LL ret;
        if(x % 2 == 0) ret = x/2 % 9 * y % 9;
        else ret = y/2 % 9 * x % 9;

        cout << ret << endl;
    }

    return 0;
}