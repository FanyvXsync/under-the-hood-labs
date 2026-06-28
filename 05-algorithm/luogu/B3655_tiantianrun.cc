#include <iostream>
using namespace std;

int a[6];

int main()
{
    int n; cin >> n;
    for(int i = 0; i < 5; i++) cin >> a[i];

    int ret = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if(x == 0)
        {
            cnt = 0;
            continue;
        }

        cnt++;
        if(cnt >= 3 && cnt < 7) ret += a[1];
        else if(cnt >= 7 && cnt < 30) ret += a[2];
        else if(cnt >= 30 && cnt < 120) ret += a[3];
        else if(cnt >= 120 && cnt < 365) ret += a[4];
        else if(cnt >= 365) ret += a[5];
        else ret += a[0];

        //  < 

    }

    cout << ret << endl;

    return 0;
}