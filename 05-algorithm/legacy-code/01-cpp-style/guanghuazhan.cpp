#include <iostream>

using namespace std;

const int N = 1e6+10;
const int M = 2e3+10;

int mp[N];
int a[N];
int n,m,kind;


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n ; i++)
    {
        cin >> a[i];
    }

    int left = 1;
    int right = 1;
    int ret = n, begin = 1;
  
    
    
    while(right <= n)
    {
        
        if(mp[a[right]]++ == 0)
        {
            kind++;
        }

        while(kind == m)
        {
            int len = right - left + 1;
            if(len < ret)
            {
                ret = len;
                begin = left;
            }

            if(mp[a[left]]-- == 1) kind-- ; left++;

        }

        right++;
    }

    cout << begin << " " << begin + ret - 1 << endl;

    return 0;
}