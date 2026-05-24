#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;



const int N = 5e5 + 10;
int n;
LL a[N]; LL tmp[N];


LL merge_sort(int l, int r)
{
    if(l >= r) return 0;

    LL ret = 0;

    int mid = (l + r)/2;
    ret += merge_sort(l,mid);
    ret += merge_sort(mid+1, r);

    int cur1 = l; int cur2 = mid + 1; int i = l;
    while(cur1 <= mid && cur2 <= r)
    {
        if(a[cur1] <= a[cur2])
        {
            tmp[i++] = a[cur1++];
        }
        else
        {
            ret += mid - cur1 + 1;
            tmp[i++] = a[cur2++]; 
        }

    }

    while(cur1 <= mid) tmp[i++] = a[cur1++];
    while(cur2 <= r) tmp[i++] = a[cur2++];

    for(int j = l; j <= r; j++) a[j] = tmp[j];
    return ret;

    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    

    cout << merge_sort(1, n) << endl;

    return 0;
}
