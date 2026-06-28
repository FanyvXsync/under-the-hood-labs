#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n,x;
int a[N];

int main()
{
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];


    int ret = 0;
    for(int i = 2; i < n; i+=2)
    {
       if(a[i] + max(a[i-1], a[i+1]) > x)
       {
            int cnt = a[i] + max(a[i-1], a[i+1]);
            ret += cnt;
            a[i] -= cnt;
       }
    }
}