#include <iostream>
using namespace std;

int main()
{
    int m; cin >> m;

    int l = 0; int r = 1;
    int sum = 0;
    while(r < m / 2)
    {
        sum += r;

        if(sum == m)
        {
            cout << l << " " << r << endl;
        }

        while(sum > m)
        {
            sum -= l;
            l++;
        }

        r++;
    }

    return 0;
}