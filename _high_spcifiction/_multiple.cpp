#include <iostream>

using namespace std;

const int N = 1e6+10;
int a[N],b[N],c[N];
int la,lb,lc;

void Mul(int a[],int b[])
{
    for(int i=0;i<la;i++)
    {
        for(int j=0;j<lb;j++)
        {
            c[i+j] += a[i] * b[j]; // 无进位相乘，模拟竖式的时候，中间的一坨存在i+j位上（规律），要+=上
        }
    }

    for(int i=0;i<lc;i++) //处理一些进位就好了
    {
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }

    while(lc > 1 && c[lc-1] == 0) lc--; // 有乘 0 的情况，所以要清除一下前导零


}

int main ()
{
    string x,y;
    cin >> x >> y;

    la = x.size(); lb = y.size();
    lc = la + lb; // 这里注意，两个数相乘的最大位数不会超过他们的和

    for(int i = 0;i<la;i++) a[i] = x[la-i-1] - '0';
    for(int i = 0;i<lb;i++) b[i] = y[lb-i-1] - '0';

    Mul(a,b);

    for(int i=lc-1;i>=0;i--) cout << c[i];

    return 0;
}