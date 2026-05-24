#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e4 + 10;
priority_queue<int,vector<int>,greater<int>> q;
int n , m;


int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        q.push(0);
    }

    int ret = 0;

    for(int i = 1; i <= n; i++)
    {
        int x;  cin >> x;
        int t = q.top(); q.pop();
        t += x;
        q.push(t);

        ret = max(ret, t);

    }

    cout << ret << endl;


    return 0;
}