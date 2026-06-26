#include <iostream>
using namespace std;

const int N = 1e6+10;
typedef long long LL;

LL a[N];
LL n,m;

LL calc(LL x)
{
    
    LL cnt = 0;
    for(int i = 1; i <= n ;i++)
    {
        if(x >= a[i]) continue;
        else cnt += a[i] - x;
    }

    return cnt;
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n ;i++)
    {
        cin >> a[i];
    } 

    int left = 1 , right = 4e5+10;
    
     while(left < right)
    {
        LL mid = (left + right + 1) / 2;
        if(calc(mid) >= m) left = mid;
        else right = mid - 1;
    }

    cout << right << endl;

}