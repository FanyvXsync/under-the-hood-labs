#include <iostream>
#include <cstring>

using namespace std;
const int N = 10;


int a[N]; int t[N];
        
int n = 5;


int calc(int st)
{
    int cnt = 0;
    while(st)
    {
        st = st & (st-1);
        cnt++;
    }

    return cnt;
}

int main()
{
    
    int T;
    cin >> T;
    while(T--)
    {
        memset(a,0,sizeof a);
        
        int ret = 0x3f3f3f3f;
        
        for(int i=0; i<5 ;i++)
        {
            for(int j = 0; j < 5; j++)
            {
                char ch;
                cin >> ch;
                if(ch == '0') a[i] |= 1 << j;
            }
        }

        for(int st = 0; st < (1 << n) ;st++)
        {
            memcpy(t,a,sizeof a);
            int cnt = 0;
            int push  = st;
            
            for(int i = 0; i < 5; i++)
            {
                cnt += calc(push);
                
                t[i] = t[i] ^ push ^ (push << 1) ^ (push >> 1);
                t[i] &= (1 << n) - 1;

                t[i+1] = t[i+1] ^ push;
                push = t[i];
            }

            if(t[n-1] == 0) ret = min(ret,cnt);
        }
        
        if(ret > 6) cout << -1 << endl;
        else cout << ret << endl;
        
    
    
    }

   


    return 0;
}