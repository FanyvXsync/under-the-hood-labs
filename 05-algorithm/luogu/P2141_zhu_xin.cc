#include <iostream>
using namespace std;

const int N = 110, M = 20010;
int a[N];
bool cnt[M];
bool vis[M];

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]] = true;
    }

    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
           int sum = a[i] + a[j];
           if(cnt[sum] && !vis[sum])
           {
                ret++;
                vis[sum] = true;
           }
        }
    }

    cout << ret << endl;

    return 0;
}