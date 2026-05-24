#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e3 + 10;
int n,s;
int a,b;

int cnt;
int x[N]; // 只需读高度小的就行

int t[N];

int main()
{
    cin >> n >> s;
    cin >> a >> b;

    a += b;

    for(int i = 1; i <= n; i++)
    {
        int x,y; cin >> x >> y;
        if(x <= a) t[++cnt] = y;
    }

    sort(t , t + 1 + cnt);

    int ret = 0; int sum = 0;
    for(int i = 1; i <= cnt; i++)
    {   
        sum += t[i];
        if(sum <= s) ret++;
    }

    cout << ret << endl;
    return 0;

}