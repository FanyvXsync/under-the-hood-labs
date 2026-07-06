#include <iostream>
using namespace std;
typedef long long LL;
// 链式前向星
// 每个节点一个链表，一个哨兵位的头节点

const int N = 1e6 + 10, M = 2e6 + 10; //双向链表
int h[N], e[M], ne[M], w[M], id;
int n;
bool st[N];

void add(int a, int b, int c)
{
    id++;
    e[id] = b;
    w[id] = c;

    ne[id] = h[a];
    h[a] = id;
}

LL ret;
int dfs(int a)  
{
    st[a] = true;

    int cnt = 1;
    for(int i = h[a]; i; i = ne[i]) //遍历每个节点所在的链表即可
    {
        int b = e[i]; LL c = w[i];
        if(st[b]) continue;

        int t = dfs(b);
        ret += abs(n - t - t) * c;
        cnt += t;
    }

    return cnt;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        LL a, b, c; scanf("%lld%lld%lld", &a,&b,&c);
        add(a, b, c); add(b, a, c);
    }

    dfs(1);

    cout << ret << endl;
}