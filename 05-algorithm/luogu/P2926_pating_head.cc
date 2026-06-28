#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int a[N];
int cnt[M];
int n;

int div(int x)
{
    int ret = 0;
    for(int i = 1; i <= x / i; i++)
    {
        if(x % i == 0)
        {
            ret += cnt[i] + cnt[x/i];
            if(i == x/i) ret -= cnt[i];
        }
        
    }

    return ret - 1;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i = 1; i <= n; i++)
    cout << div(a[i]) << endl;

    return  0;
}