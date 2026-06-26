#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;
int n;
map<int,int> mp;
int ret;

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x = 0;
        cin >> x;
        mp[i] = x;
    }

    for(int i=1;i<=n;i++)
    {
        int tmp = 1e6;
        for(int j=1;j<i;i++)
        {
            if(i==1)
            {
                tmp = mp[i];
            }
            else
            tmp = tmp > abs(mp[j]-mp[i]) ? abs(mp[j]-mp[i]) : tmp;
        }
        ret += tmp;
    }

    cout << ret << endl;

    return 0;
}


