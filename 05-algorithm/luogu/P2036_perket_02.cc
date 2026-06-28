#include <iostream>
#include <cmath>
using namespace std;
const int N = 15;

typedef long long LL;

LL n;
LL s[N],b[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> b[i];

    
    LL ret = 1e9 + 10;
    for(int st = 1; st <( 1 << n) ; st++)
    {
        LL x = 1, y = 0;
        for(int i = 0; i < n; i++)
        {
            if((st >> i) & 1)
            {
                x *= s[i];
                y += b[i];
            }
        }

        ret = min(ret, abs(x - y));
    }

    cout << ret << endl;
    return 0;
}