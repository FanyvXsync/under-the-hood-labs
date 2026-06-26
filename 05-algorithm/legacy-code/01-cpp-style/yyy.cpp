#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
struct node
{
    int l;
    int r;
}a[N];


bool cmp(node& x, node& y)
{
    return x.l < y.l;
}

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n ;i++)
    {
        cin >> a[i].l >> a[i].r;
    }

    sort(a+1,a+1+n,cmp);

    int ret = 1;
    int r = a[1].r;
    for(int i = 2; i <= n; i++)
    {
        int left = a[i].l ,right = a[i].r;
        if(left < r)
        {
            r = min(r,right);
        }
        else
        {
            ret++;
            r = right;
        }

    }

    cout << ret << endl;

    return 0;

}

