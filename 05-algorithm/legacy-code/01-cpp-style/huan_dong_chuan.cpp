#include <iostream>
#include <queue>
using namespace std;

const int N =  1e6 + 10;
int n , k;
int a[N];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    deque<int> q; // 存下标
    for(int i = 1; i <= n; i++)
    {
        while(q.size() && a[q.back()] >= a[i]) q.pop_back();

        q.push_back(i);
        // 判断队列里面的元素是不是在合法窗口内
        if(q.back() - q.front() + 1 > k) q.pop_front();
        
        if(i >= k) cout << a[q.front()] << " "; 

    }
    cout << endl;

    q.clear();

    for(int i = 1; i <= n; i++)
    {
        while(q.size() && a[q.back()] <= a[i]) q.pop_back();

        q.push_back(i);
        // 判断队列里面的元素是不是在合法窗口内
        if(q.back() - q.front() + 1 > k) q.pop_front();
        
        if(i >= k) cout << a[q.front()] << " "; 

    }


    return 0;

}