#include <iostream>
using namespace std;

const int N = 2e5 + 10;

int n;
int a[N];


int dfs(int left , int right)
{
    if(left == right) return a[left];

    int mid = (left + right)/2;
    int ret = max(dfs(left,mid), dfs(mid+1 ,right));

    int sum = a[mid], lmax = a[mid];
    for(int i = mid -1 ; i >= left ; i--)
    {
        sum += a[i];
        lmax = max(sum, lmax);
    }

    sum = a[mid + 1];  int rmax = a[mid + 1];

    for(int i = mid + 2; i <= right ; i++)
    {
        sum += a[i];
        rmax = max(sum, rmax);
    } 

    ret = max(ret, lmax + rmax);

    return ret;

}

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];

    cout << dfs(1,n);
    return 0;
}