#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 1e5+10;

LL a[N],b[N];
int n,m;
LL ret;

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m ; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    a[0] = -1e7+10;
    a[m+1] = -1e7+10;

    sort(a+1,a+1+m);
    for(int i = 1; i <= n ; i++)
    {
        auto it = lower_bound(a+1,a+1+m,b[i]);
        ret += min(abs(*it - b[i]), abs(*(it - 1) - b[i]));
    }

    cout << ret << endl;

}