#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;

int id[N], n;

int main()
{
    cin >> n;
    int sum = 0; int ret = 0;
    
    memset(id, -1 , sizeof id);
    id[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        int x;  cin >> x;
        sum = (x + sum) % 7;

        if(id[sum] != -1) ret = max(ret,  i - id[sum]);
        else id[sum] = i;
    }

    cout << ret << endl;

    return 0;
}