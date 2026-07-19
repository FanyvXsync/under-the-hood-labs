#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
    string s; 
    LL n;
    cin >> s >> n;

    LL len = s.size();

    while(n > len)
    {
        LL k = len;
        while(k < n) k <<= 1;
        k >>= 1;

        if(n == k + 1) n--;
        else if(n > k + 1) n = n - k - 1;
    }

    cout << s[n - 1] << endl;

    return 0;
}