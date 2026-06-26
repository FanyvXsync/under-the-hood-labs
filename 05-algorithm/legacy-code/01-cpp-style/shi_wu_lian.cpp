#include <iostream>

using namespace std;
const int N = 5e4 + 10;

int n,k;
int fa[N], d[N];

int find(int x)
{
   if(fa[x] == x) return x;
   int t = find(fa[x]);

   d[x] += d[fa[x]];

   return fa[x] = t;
}

void un(int x,int y,int w)
{
    int fx = find(x), fy = find(y);
    if(fx != fy)
    {
        fa[fx] = fy;
        d[fx] = d[y] + w - d[x];

    }
}


int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) fa[i] = i;


    int ret = 0;
    while(k--)
    {
        int op, x , y ; cin >> op >> x >> y;
        int fx = find(x) , fy = find(y);

        if(x > n || y > n) ret++;
        else if(op == 1)
        {
            if(fx == fy && ((d[y] - d[x]) % 3 + 3) % 3 != 0 ) ret++;
            else un(x,y,0);
        }
        else
        {
            if(fx == fy && ((d[y] - d[x]) % 3 + 3) % 3 != 1 ) ret++;
            else un(x,y,2);
        }

    }

    cout << ret << endl;
    return 0;
}
