#include <iostream>
#include <vector>

using namespace std;
const int N = 200;

int n,m;
vector<int> edges[N];

int ret[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int a = 1; a <= n; a++)
    {
        for(int i = 1; i <= 4; i++)
        {
            bool flag = true;
            for(auto b: edges[a])
            {
                if(ret[b] == i)
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                ret[a] = i;
                break;
            }
        }

    }

    for(int i = 1; i <= n; i++) cout << ret[i];
    return 0;
}