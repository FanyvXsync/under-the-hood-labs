#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+10;

struct node
{
    int t;
    int d;
}a[N];

int n;

bool cmp(node& x ,node& y)
{
    return x.t * x.d < y.t * y.d;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].t >> a[i].d;
    }

    sort(a+1,a+1+n,cmp);
    LL ret = 0;
    LL t = 0;

    for(int i = 1; i <= n; i++)
    {
        ret += a[i].d * t;
        t += 2 * a[i].t;
    }

    cout << ret << endl;


}

