#include <iostream>
using namespace std;
const int N = 1e5 + 10;

int a[N];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int cnt = a[1] == 0? 0 : 1;
    int left = 1; int right = 2;

    int ret = 0;

    while(right < n)
    {
        cnt += a[right];

        while(right - left + 1 != cnt * 2)
        {
            cnt -= a[left];
            left++;
        }

        ret = max(ret, cnt);

        right++;
    }



    return 0;
}
