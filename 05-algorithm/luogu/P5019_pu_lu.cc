#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
priority_queue<int, vector<int>, greater<int>> q;
int n,ret;
int a[N];

void dfs(int l, int r)
{
    if(l > r) return ;

    int minx = 0x3f3f3f3f;
    int idx = 0;
    for(int i = l; i <= r; i++) minx = min(minx,a[i]);
    
    ret += minx;
    for(int i = l; i <= r; i++)
    {
        a[i] -= minx;
        if(a[i] == 0) idx = i; 
    }
    // [l , idx - 1] idx [idx + 1, r]
    dfs(l , idx - 1);
    dfs(idx + 1, r);

    return ;

}



int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        q.push(a[i]);
    }

    dfs(1,n);

    cout << ret << endl;
    return 0;
}