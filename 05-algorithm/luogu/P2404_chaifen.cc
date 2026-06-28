#include <iostream>

using namespace std;
const int N = 10;

int n;
int sum;
int path[N];

void dfs(int pos)
{
    if(sum > n) return;
    if(sum == n)
    {
        if(pos == 2) return;
        for(int i = 1; i < pos - 1; i++)
        {
            cout << path[i] << "+";
        }
        cout << path[pos - 1]<< endl;
    }

    for(int i = path[pos - 1]; i <= n; i++)
    {
        sum += i;
        path[pos] = i;
        dfs(pos + 1);
        sum -= i;
        path[pos] = 0;
    }

}


int main()
{
    cin >> n;
    path[0] = 1;
    dfs(1);

    return 0;
}