// 队列  计数排序  快速读写
#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int n;
int cnt[N];

LL tmp[3];
queue<LL> q[3];

int read()
{
    int ret = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9')
    {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }

    return ret;
}


int main()
{
    n = read();
    
    for(int i = 1; i <= n; i++)
    {
        int x = read();
        cnt[x]++;
    }

    for(int i = 1; i < N; i++)
        while(cnt[i]--)
            q[1].push(i);

    LL ret = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j <= 2; j++) //  两次操作防止写很多if else
        {
            //什么时候必定选队列1
            if(q[2].empty() || (q[1].size() && q[1].front() < q[2].front()))
            {
                tmp[j] = q[1].front();
                q[1].pop();
            }
            else
            {
                tmp[j] = q[2].front();
                q[2].pop();
            }
        }

        ret += tmp[1] + tmp[2];
        q[2].push(tmp[1] + tmp[2]);
    }

    cout << ret << endl;
    
    return 0;
}