#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 2e5+10;

LL a[N];
LL n,c;

int main()
{
    LL ret = 0;
    
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a+1,a+1+n);

    for(int i = 1; i <= n ; i++)
    {
        int m = a[i] + c;
        int left = 1 , right = n;
        while(left < right)
        {
            int mid = (left + right + 1)/ 2;
            if(a[mid] <= m) left =mid;
            else right = mid - 1;
        }

        if(a[left] != m) continue;
        int retleft = left;

        left = 1; right = n;
        
        while(left < right)
        {
            int mid = (left + right)/ 2;
            if(a[mid] >= m) right = mid;
            else left = mid + 1;
        }

        ret += retleft - left + 1;
        
    }

    cout << ret << endl;

    return 0;

}