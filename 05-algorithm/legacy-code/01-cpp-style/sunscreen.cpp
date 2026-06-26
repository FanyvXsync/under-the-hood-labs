#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2510;

int n,l;
struct node
{
    int x;  // 左区间  防晒强度
    int y;  // 右区间  瓶数
}a[N],b[N];

bool cmp(node& x, node& y)
{
    return x.x > y.x;
}

int main()
{
    cin >> n >> l;
    for(int i = 1; i <= n ; i++) cin >> a[i].x >> a[i].y;
    for(int i = 1; i <= l ; i++) cin >> b[i].x >> b[i].y;

    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+l,cmp);

    int ret = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1; j <= l ; j++)
        {
            int w = b[j].x , &cnt = b[j].y;
            if(cnt == 0) continue;
            if(w < a[i].x) break;
            if(w > a[i].y) continue;   // 存一下是对的

            ret++;
            cnt--;
            break;
            
        }
    }

    cout << ret << endl;

    return 0;

}