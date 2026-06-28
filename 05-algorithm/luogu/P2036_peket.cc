#include <iostream>
using namespace std;
const int N = 15;

int a[N],b[N],n;
int ret = 1e9 + 10;
int su, ku;

int dfs(int pos)
{
    
    for(int i = pos + 1; i <= n; i++)
    {
        su += a[pos]; ku *= b[pos];
        ret = min(ret, abs(su - ku));
        dfs(pos);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    
    ret = dfs(1);
    
    cout << ret << endl;
    return 0;
}