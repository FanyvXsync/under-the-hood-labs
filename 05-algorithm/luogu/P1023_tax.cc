#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;


int zp;
int p[N], m[N];
int dp;


int main()
{
    cin >> zp;
    int x, y;
    int i = 1;
    while(cin >> x >> y, x != -1 || y != -1)
    {
        p[i] = x;
        m[i] = y;
        i++;
    }

    cin >> dp;

    LL maxw = 0;
    for(int j = 1; j <= i; j++)
    {
        LL w = (p[j] - p[1]) * m[i];
        maxw = max(maxw, w);
    }

    int ip = 0; int ddp = 0;
    while(1)
    {
        ip++; 
    }



    return 0;
}