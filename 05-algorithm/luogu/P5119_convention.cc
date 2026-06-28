#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

int n,m,c;
int a[N];

int calc(int x)
{
    int cnt = 0;
    int l = 1, r = 1;

    while(r <= n)
    {
        while(r <= n && a[r] - a[l] <= x && r - l + 1 <= c) r++;
        cnt++;
        l = r;
    }
    return cnt;
}


int main()
{
    cin >> n >> m >> c;
    for(int i = 1;i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    int l = 0, r = a[n] - a[1];
    while(l < r)
    {
        int mid = ( l + r )/2;
        if(calc(mid) <= m) r = mid;
        else l = mid + 1;
    }

    cout << l << endl;
    return 0;
}