#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10;

int a[N];
int n,k;

int merge_cmp(int l, int r)
{
    if(l > r) return 0;

    int mid = (l + r)/ 2 ;
    // [l , mid] [mid + 1, r]

    int rem = 0;
    for(int i = mid; i >= l; i--)
    {
        if(a[mid] - a[i] <= k) rem++;
    }
    
    for(int i = mid + 1; i <= r; i++)
    {
        if(a[i] - a[mid + 1] <= k) rem++;
    }

    int rel = merge_cmp(l, mid);
    int rer = merge_cmp(mid + 1, r);


    return max(rem, rel + rer);
}


int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    int ret = merge_cmp(1,n);

    cout << ret << endl;

    return 0;
}