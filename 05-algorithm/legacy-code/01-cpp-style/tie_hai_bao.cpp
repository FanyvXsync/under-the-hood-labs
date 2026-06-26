#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;
const int N = 1010;

int a[N],b[N];
int n,m;

int disc[N*4];
int pos;

int wall[N*4];
bool st[N*4];
unordered_map<int,int> id;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        disc[++pos] = a[i]; disc[++pos] = a[i] + 1;
        disc[++pos] = b[i]; disc[++pos] = b[i] + 1;
        
    }

    sort(disc + 1 , disc + 1 + pos);
    int cnt = 0;
    for(int i = 1 ; i <= pos ; i++)
    {
        int x = disc[i];
        if(id.count(x)) continue;
        cnt++;
        id[x] = cnt;
    }

    //

    for(int i = 1; i <= m; i++)
    {
        int l = id[a[i]] , r = id[b[i]];
        for(int j = l; j <= r; j++)
        {
            wall[j] = i;
        }
    }

    int ret = 0;
    for(int i = 1; i <= cnt ; i++)
    {
        int x = wall[i];
        if(x == 0 || st[x]) continue;

        ret++;
        st[x] = true;
    }

    cout << ret << endl;
    

    return 0;
}