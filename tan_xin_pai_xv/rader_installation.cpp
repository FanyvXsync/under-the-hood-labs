#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


const int N = 1010;
struct node
{
   double l,r;
}a[N];

int n;
double d;

bool cmp(node& x, node& y)
{
    return x.l < y.l;
}

int main()
{
    cin >> n >> d;
    int cnt = 0;
    while( cin >> n >> d , n && d)
    {
        cnt++;
        int flag = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            double x,y ; cin >> x >> y;
            if (d < y) flag = 1;
            double l = sqrt(d*d - y*y);
            a[i].l = x - l;
            a[i].r = x + l;
        }
        cout << "Case" << cnt << ": ";
        if(flag) cout << -1 << endl;
        else
        {
            sort(a+1,a+1+n,cmp);

            int ret = 0;
            double r = a[1].r;

            for(int i = 2; i <= n; i++)
            {
                double left = a[i].l , right = a[i].r;
                if(left <= r)
                {
                    r = min(r,right);
                }   
                else
                {
                    ret++;
                    r = right;
                }
            }

            cout << ret << endl;

        }
    }
    

}
