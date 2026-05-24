#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1010;

bool cmp(idx x, idx y)
{
    return x.z <= y.z;
}

int n,h,r;
struct idx
{
    int x;
    int y;
    int z;
}a[N];

bool dfs(int la)
{
    if(la >= h) return true;



}

int main()
{
    int t; cin >> t;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }



    if(dfs(0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}