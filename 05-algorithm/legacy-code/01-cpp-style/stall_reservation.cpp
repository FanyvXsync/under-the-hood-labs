#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 5e4+10;
struct node
{
    int x; // 开始      // 结束时间
    int y; // 结束      // 牛棚编号
    int z; // 奶牛编号

    bool operator<(const node& y) const 
    {
        return x > y.x;
    }

}a[N];

int n;
int ret[N];

bool cmp(node& x, node& y)
{
    return x.x < y.x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].z = i;
    }

    sort(a+1, a + 1 + n, cmp);

    int nums = 1;

    priority_queue<node> heap;
    ret[a[1].z] = 1;
    heap.push({a[1].y,1});

    for(int i = 2; i <= n ; i++)
    {
        int l = a[i].x , r = a[i].y;
        if( l <= heap.top().x)
        {
            nums++;
            ret[a[i].z] = nums;
            heap.push({r,nums});
        }
        else
        {
            auto t = heap.top(); heap.pop();
            ret[a[i].z] = t.y;
            heap.push({r,t.y});
        }

    }

    cout << nums << endl;
    for(int i = 1; i <= n; i++) cout << ret[i] << endl;

    return 0;
}