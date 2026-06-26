#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;

struct node
{
    int index;
    int cnt;
}row[N],col[N];

int m, n, k, l ,d;

bool cmp1(node& x, node& y)
{
    return x.cnt > y.cnt;
}

bool cmp2(node& x, node& y)
{
    return x.index < y.index;
}



int main()
{
    cin >> m >> n >> k >> l >> d;
    for(int i = 1; i <= m; i++) row[i].index = i;
    for(int i = 1; i <= n; i++) col[i].index = i;
    
    
    while(d--)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if(x == p) col[min(y,q)].cnt++;
        else row[min(x,p)].cnt++;
    }

    sort(row+1,row+1+m,cmp1);
    sort(col+1,col+1+n,cmp1);

    sort(row + 1, row + 1 + k, cmp2);
    sort(col+1 ,col +1+ l,cmp2);

     for(int i = 1; i <= k; i++) 
    {
        cout << row[i].index << " ";
    }

    cout << endl;
    for(int i = 1; i <= l; i++)
    {
        cout << col[i].index << " ";
    }
    cout << endl;

    return 0;

}
