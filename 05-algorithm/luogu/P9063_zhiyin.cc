#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        LL n; cin >> n;
        if(n % 2 == 0 || n == 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}