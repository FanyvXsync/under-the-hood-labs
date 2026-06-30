// A^k   A 要是方阵
// 类比整数快速幂   因为满足结合律
// RET = E 单位矩阵  RET = RET * A....
// 如何赋值:(1) tmp (2) 类里面重载运算符
// n^3 * logk
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;
const int N = 110, MOD = 1e9 + 7;

LL n, k;

struct mat
{
   LL m[N][N];

   mat()
   {
        memset(m, 0, sizeof m);
   }

   mat operator*(const mat& B) const
   {
        mat C;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int k = 1; k <= n; k++)
                    C.m[i][j] = (m[i][k] * B.m[k][j] + C.m[i][j]) % MOD;
            }
        }

        return C;
   }

}A,RET;


void qpow(LL b)
{
    for(int i = 1; i <= n; i++) RET.m[i][i] = 1;

    while(b)
    {
        if(b & 1) RET = RET * A;
        b >>= 1;
        A = A * A;
    }
}

int main()
{   
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> A.m[i][j];

    
    qpow(k);

    for(int i = 1; i = n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << RET.m[i][j];
        }
    }
    return 0;
}