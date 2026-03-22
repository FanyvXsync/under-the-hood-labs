#include <iostream>
#include <vector>
using namespace std;

const int N = 15;
int ret;

vector<int> path;
bool col[N],st1[N*2],st2[N*2];
int n;

void dfs(int x)
{
    if( x > n )
    {
        ret++;
        if(ret <= 3)
        {
            for(auto e : path) cout << e << " ";
            cout << endl;
        }

        return ;
    }


    for(int y = 1; y <= n ; y++)
    {
        if(col[y] || st1[y - x + n] || st2[x + y]) continue;
        path.push_back(y);
        col[y] = true , st1[y - x + n] = true , st2[x + y] = true;
        dfs(x+1);

        col[y] = false , st1[y - x + n] = false , st2[x + y] = false;
        path.pop_back();
    }

}


int main()
{
    cin >> n;

    dfs(1);
    cout << ret ;
    return 0;
}