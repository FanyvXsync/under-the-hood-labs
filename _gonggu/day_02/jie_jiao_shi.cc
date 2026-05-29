#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n,m;

int r[N], d[N],s[N],t[N];
int f[N];

bool check(int mid)
{
    for(int i = 1; i <= n; i++) f[i] = r[i] - r[i-1];

    for(int i = 1; i <= mid; i++)
    {
        // s[i] , t[i]   d[i]
        f[s[i]] -= d[i];
        f[t[i] + 1] += d[i];
    }

    for(int i = 1; i <= mid ; i++) 
    {
        f[i] = f[i-1] + f[i];
        if(f[i] < 0) return false;
    }

    return true;
}


int main()
{
    cin >> n >> m;
    for(int i = 1; i <=n; i++) cin >> r[i];
    for(int i = 1; i <=m; i++) cin >> d[i] >> s[i] >> t[i];
    
    int l = 1, r = m;
   
    while(l < r)
    {
        int mid = (l + r)/2;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }

    if(check(l)) cout << "0" << endl;
    else cout << -1 << endl << l << endl;



    return 0;
}