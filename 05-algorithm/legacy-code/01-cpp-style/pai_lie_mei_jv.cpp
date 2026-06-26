#include  <iostream>
#include <vector>

using namespace std;
const int N = 15;
int n;

vector<int> path;
bool st[N];

void dfs()
{
    if( path.size() == n)
    {
        for(auto e : path) printf("%5d",e);
        cout << endl;
        return;
    }


    for(int i = 1; i <= n; i++)
    {
        
        if(st[i]) continue;
        
        path.push_back(i);
        st[i] = true;
        dfs();

        path.pop_back();
        st[i] = false;

    }
}

int main()
{
    cin >> n;
    dfs();

    return 0;
}