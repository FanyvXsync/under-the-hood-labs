#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int n,m;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int prev = 0; int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        int d = a[i + 1] - a[i];
        if(d == 0) continue;

        d = (d > 0 ? 1 : -1);
        if(d != prev) cnt++;
        prev = d;
    }

    cout << cnt + 1 << endl;

    return 0;
}