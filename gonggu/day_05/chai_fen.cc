#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<int> ret;

int main()
{
    cin >> n;
    if(n % 2 != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    while(n)
    {
        cnt++;
        if((n >>= 1) & 1) ret.push_back(pow(2, cnt));
    }

    int m = ret.size();
    for(int i = m - 1; i >= 0; i--)
    {
        cout << ret[i] << " ";
    }
    
    
    

    return 0;
}