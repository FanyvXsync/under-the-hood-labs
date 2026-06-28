#include <iostream>
using namespace std;

const int N = 210;

int n, n1, n2;
int a[N], b[N];

int c[5][5] = {
    0, -1, 1 , 1, -1,
    1, 0, -1, 1 ,-1,
    -1, 1 ,0, -1 , 1,
    -1, -1 ,1 ,0, 1,
    1,1, -1, -1, 0
};

int main()
{
    cin >> n >> n1 >> n2;

    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];

    int A = 0, B = 0;
    for(int i = 0; i < n; i++)
    {
        int x = i % n1,  y = i % n2;
        int t = c[a[x]][b[y]];

        if(t > 0) A++;
        else if(t < 0) B++;
    }

    cout << A << " " << B << endl;

    return 0;


}