#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5e4+10;
struct node
{
    int begin;
    int end;
}a[N];

vector<int> opt;

int n;

bool cmp(node& x, node& y)
{
    return x.begin < y.begin;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].begin >> a[i].end;

    sort(a+1,a+1+n,cmp);

    int ret = 1;
    int cnt = 1;
    int r = a[1].end;

    for(int i = 2; i <= n; i++)
    {
       opt.push_back(cnt);
       int l = a[i].begin , r = a[i].end;
       if(r >= l) 
       {
            ret++;
            cnt++;
       }
    }
    

}