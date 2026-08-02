#include <iostream>
using namespace std;
typedef long long LL;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        LL n;  cin >> n;
        if(n == 1) cout << 1 << endl;
        else cout << (n * (n - 1)) << endl;
    }


    return 0;
}