#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N  = 310;
int n;
int a[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n); 
    LL sum = 0;
    int l = 0; int r = n;
    
    while(l < r)
    {
        sum += (a[l] - a[r]) * (a[l] - a[r]);
        l++;
        sum += (a[l] - a[r]) * (a[l] - a[r]);
        r--;
    }

    cout << sum << endl;
    

    return 0;
}