#include <iostream>
using namespace std;
const int N = 110;

int n , m;
int f[N];
int f2[N];

struct days
{
    int lef;
    int rig;
}a[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i].lef >> a[i].rig;
        f[a[i].lef] += 1;
        f[a[i].rig + 1] -= 1;
    }

    for(int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i];
        if(f[i] >= 2 || f[i] == 0) 
        {
            cout << i << " " << f[i] << endl;
            return 0;
        }
    }

    cout << "OK" << endl;


    return 0;
}
