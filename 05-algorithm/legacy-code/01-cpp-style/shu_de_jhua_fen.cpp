#include <iostream>
using namespace std;

int n,k;

int ret, path;

void dfs(int pos, int begin)
{
    if(pos == k)
    {
        if(path == n) ret++;
        return ;
    }

    for(int i = begin ; i <= n; i++)
    {
        if(path + i * (k - pos) > n)  return;

        path += i;
        dfs(pos+1, i);
        path -= i;
    }
}


int main()
{
    cin >> n >> k;

    dfs(0,1);

    cout << ret << endl;

    return 0;
}