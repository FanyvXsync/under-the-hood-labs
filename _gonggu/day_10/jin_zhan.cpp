#include <iostream>
using namespace std;
typedef long long LL;

LL y , z;
LL x = 1e12;


int main()
{
    cin >> y >> z;
    if(z <= x + y)
    {
        cout << x + y - z << endl;
        return 0;
    }
    else
    {
        x = z / 1e6 - 1;
        x = x * 1e6;
        cout << abs(x + y - z) << endl;
    }


    return 0;
}