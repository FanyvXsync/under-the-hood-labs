#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e6+10;
int a[N],b,c[N];
int la,lc; //   注意这里是b，这是高精度除以低精度的

void Div(int a[],int b)
{
    LL t = 0;  // 用一个变量 t 来存储余数，可以超过 int 的范围，用LL

    for(int i = la-1;i>=0;i--) // 这里从最高位开始除，和之前的不太一样
    {
        t = t*10 + a[i];
        c[i] = t / b;
        
        t %= b;
    }

    // 注意这里是可能有前导零的，商零的，最后处理掉就可以了
    // 我一开始想的是先找到从哪一位开始除，但是不好控制，上面的更好

    while( lc > 1 && c[lc-1] == 0) lc--;

}


int main()
{
    string x;
    cin >> x >> b;

    la = x.size();
    lc = la;

    for(int i = 0;i<la;i++) a[i] = x[la-i-1] - '0';
    

    Div(a,b);


    for(int i=lc-1;i>=0;i--) cout << c[i];

    return 0;
}