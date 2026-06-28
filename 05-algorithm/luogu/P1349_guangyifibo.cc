/*
矩阵快速幂加速递推，线代章
[a3, a2] = [a2, a1](RET) * [ ] (A)
构造出A 矩阵， 行乘列

[an,  an-1] = RET * A^n-2
*/


#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const int N = 3;
LL p, q, a1, a2, n , mod;
LL ret;

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
        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= 2; j++)
                for(int k = 1; k <= 2; k++)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j] % mod) % mod; 
        
        return C;
    }
}RET, A;

void qpow(LL b)
{
    RET.m[1][1] = a2; RET.m[1][2] = a1;
    A.m[1][1] = p;  A.m[1][2] = 1; A.m[2][1] = q;

    while(b)
    {
        if(b & 1) RET = RET * A;
        b >>= 1;
        A = A * A;
    }
}


int main()
{

    cin >> p >> q >> a1 >> a2 >> n >> mod;

    if(n == 1)
    {
        cout << a1 << endl;
        return 0;
    }

    if(n == 2)
    {
        cout << a2 << endl;
        return 0;
    }

    qpow(n - 2);

    cout << RET.m[1][1] << endl;

    return 0;
}