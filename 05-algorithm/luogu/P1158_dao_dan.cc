#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int x[N], y[N];
int x1,x2,y1,y2;
int n;

int r1, r2;


bool calc(int x, int y)
{
    return (x1 - x)*(x1 - x) + (y1 - y)*(y1 - y) >= (x2 - x)*(x2 - x) + (y2 - y)*(y2 - y);
}


int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;

    for(int i = 1; i<= n; i++) cin >> x[i] >> y[i];

    for(int i = 1; i <= n; i++)
    {
        if(calc(x[i], y[i]))
        {
            r1 = max(r1, (x1 - x[i])*(x1 - x[i]) + (y1 - y[i])*(y1 - y[i]));
        }
        else
        {
            r2 = max(r2, (x2 - x[i])*(x2 - x[i]) + (y2 - y[i])*(y2 - y[i]));
        }
    }

    cout << r1 + r2 << endl;

    return 0;
}