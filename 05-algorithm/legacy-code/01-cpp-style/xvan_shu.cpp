#include <iostream>
#include <cstring>
using namespace std;

const int N = 15;

int t[N],d[N],l[N];
bool st[N];
int n;

bool dfs(int pos, int end)
{
    if(pos > n)
    {
        return true;
    }

   for(int i = 1; i <= n; i++)
   {
        if(st[i]) continue;
        if(end > t[i] + d[i]) continue;
        int newend = max(t[i],end) + l[i];
        st[i] = true;

        if(dfs(pos+1, newend)) return true;
        st[i] = false;

   }

   return false;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        memset(st,0,sizeof st);
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            cin >> t[i] >> d[i] >> l[i];
        }

        if(dfs(1,0)) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

    return 0;
}