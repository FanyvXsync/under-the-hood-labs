#include <iostream>

using namespace std;
const int N = 1e4+10;
int a[N],b[N],g[N],k[N];

// 倒着枚举，数组存坐标

int main ()
{
    int n ; cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }

    int x,y;
    cin >> x >> y;

    for(int i=n;i>=0;i--)
    {
        if(x>=a[i] && x<=a[i]+g[i] && y>=b[i] && y<=b[i]+k[i]) 
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}