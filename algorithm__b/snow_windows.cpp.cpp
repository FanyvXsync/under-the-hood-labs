#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e6+10;

typedef long long LL;


int n,T;
LL a[N];

int main ()
{
    cin >> T;
    while(T--)
    {
    
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
        }

        unordered_map<int,int> mp;

        int left = 1, right = 1;
        int ret = 0;

        while(right <= n)
        {
            mp[a[right]]++;
            while(mp[a[right]]>1)
            {
                mp[a[left]]--;
                left++;
            }
           
            ret = max(ret,right-left+1);
            right++;
            

        }

        cout << ret << endl;
    }

    return 0;
}