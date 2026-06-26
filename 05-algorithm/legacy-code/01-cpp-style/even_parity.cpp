#include <iostream>
#include <cstring>
using namespace std;

const int N = 30;
int a[N],t[N];
int n; 

int calc(int x,int y)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(((x >> i) & 1) == 0 && ((y >> i) & 1) == 1) cnt++;
        if(((x >> i) & 1) == 1 && ((y >> i) & 1) == 0) return -1;
    }

    return cnt;

}


int solve()
{
    int ret = 0x3f3f3f3f;
    
    for(int st = 0; st < (1 << n) ; st++)
    {
        memcpy(t,a,sizeof a);
        int change = st;
        int cnt = 0;
        int flag = 1;
       
       
        for(int i = 1; i<= n; i++)
       {           
            int c = calc(t[i],change);
            if(c == -1)
            {
                flag = 0;
                break;
            }
            else
            {
                cnt += c;
                t[i] = change; // 当前行的最终状态要放上
                change = t[i-1] ^ (t[i] >> 1) ^ (t[i] << 1);
                change &= ( 1 << n ) -1;

            }

       }

       if(flag) ret = min(ret,cnt);

    }

    if(ret == 0x3f3f3f3f)  return -1;
    else return ret;
}


int main()
{
    int k;
    cin >> k;

    for(int i = 1;i <= k; i++)
    {
        memset(a,0,sizeof a);

        cin >> n;
        for(int i = 1; i<=n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int ch; cin >> ch;
                if( ch == '1') a[i] |= 1 << j;
            }


        }

        solve();

        printf("Case %d: %d",k,solve());
    }
}