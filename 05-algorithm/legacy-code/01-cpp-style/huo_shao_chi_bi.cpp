#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int N = 2e4 + 10;


int  a[N],b[N];
int disc[N*2];
int pos;
int f[N*2];
unordered_map<int,int> mp;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;

    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i] >> b[i];
        disc[++cnt] = a[i];
        disc[++cnt] = b[i];
    }

    sort(disc + 1 , disc + cnt + 1);
    pos = unique(disc + 1 , disc + cnt + 1) - (disc + 1);

    for(int i = 1; i <= pos ; i++)
    {
        int x = disc[i];
        mp[x] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        // a[i] ~ b[i]
        int l = mp[a[i]] , r = mp[b[i]];
        f[l]++ ; f[r]--;
    }

    for(int i = 1; i <= pos; i++) f[i] += f[i-1];

    int ret = 0;
    for(int i = 1; i <= pos ; i++)
    {
        int j = i;
        while(j <= cnt && f[j] > 0) j++;
        ret += disc[j] - disc[i];

        i = j;
    }

    cout << ret << endl;


    return 0;
}