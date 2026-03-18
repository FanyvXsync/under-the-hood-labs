#include <iostream>
using namespace std;
typedef long long LL;
const int N = 2e5+10;

LL f[N];
LL n;


int main()
{
    cin >> n;
    

    for(int i = 1; i <= n; i++)
    {
        LL x; cin >> x;
        f[i] = f[i-1] + x;
    }

    LL ret = -1e20;
    LL prevmin = 0;
    
    for(int i = 1;i <= n; i++)
    {
        ret = max(ret , f[i] - prevmin);
        prevmin = min(prevmin, f[i]);
    }
    
    cout << ret << endl;
    
   
    return 0;
}
