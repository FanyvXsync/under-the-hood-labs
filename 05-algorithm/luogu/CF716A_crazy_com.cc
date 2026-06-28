#include <iostream>
using namespace std;
const int N = 1e5 + 10;

int n,c;
int a[N];
int ret;


int main()
{
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> a[i];

    ret++;
    for(int i = 2; i <=n ; i++ )
    {
        if(a[i] - a[i - 1] <= c) ret++;
        else
        {
            ret = 1;
        }

    }

    cout << ret << endl;

    return 0;
}