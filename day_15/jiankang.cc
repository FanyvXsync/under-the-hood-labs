#include <iostream>
#include <vector>
using namespace std;
const int N = 30, G = 20;

int v, vt[N];
int g, gt[G][N];

int ret;

int main()
{
    cin >> v;
    for(int i = 1; i <= v ; i++) cin >> vt[i]; 

    cin >> g;
    for(int i = 1; i <= g; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            cin >> gt[i][j];
        }
    }

    for(int i = 1; i <= g; i++)
    {

    }

    return 0;
}