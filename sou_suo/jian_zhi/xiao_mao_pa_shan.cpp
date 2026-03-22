#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;

int ret = N, cnt;
int c[N], s[N];

int n, w;


void dfs(int pos)
{
    if ( cnt >= ret) return ;

    if(pos > n)
    {
        ret = cnt;
        return ;
    }

    for(int i = 1; i <= cnt; i++)
    {
        if(s[i] + c[pos] > w) continue;

        s[i] += c[pos];
        dfs(pos + 1);
        s[i] -= c[pos];
    }


    cnt++;
    s[cnt] = c[pos];
    dfs(pos + 1);
    s[cnt] = 0;
    cnt--;

}


bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> c[i];

    sort(c + 1, c + 1 + n, cmp);
    dfs(1);

    cout << ret << endl;

    return 0;
}