#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;

LL n, m;
LL a[N];


int calc(LL x)
{
    int cnt = 0, sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        if(sum > x)
        {
            cnt++;
            sum = a[i];
        }

    }

    return cnt + 1;
}

int main()
{
    cin >> n >> m;
    LL l = 0, r = 0;
    
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        l = max(l, a[i]); 
        r += a[i];
    }

    while(l < r)
    {
        LL mid = (l + r) / 2;
        if(calc(mid) <= m) r = mid;
        else l = mid + 1; 
    }

    cout << l << endl;

    return 0;

}