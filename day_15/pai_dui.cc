#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
typedef long long LL;
struct pe
{
    int idx;
    int t;
}a[N];

bool cmp(pe x, pe y)
{
    if(x.t == y.t) return x.idx < y.idx;
    else return x.t < y.t;
}


int main()
{
    int n ; cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        a[i].idx = i;
        a[i].t = x;
    }

    sort(a + 1, a + n + 1, cmp);

    double ret = 0;
    for(int i = 2; i <= n; i++)
    {
        int x = 0;
        for(int j = 1; j < i; j++)
        {
            x += a[j].t;
        }

        ret += x;
    }

    for(int i = 1; i <= n; i++)
    cout << a[i].idx << " ";
    puts("");

    ret /= n;

    printf("%.2f", ret);
    
    return 0;
}