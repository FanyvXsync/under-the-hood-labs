#include <iostream>
#include <cmath>
using namespace std;
typedef  long long LL;

LL a,b;

LL qpow(LL a, LL b)
{
    
    LL ret = 1;

    while(b)
    {
        if(a > 1e9) return -1;
        if(b & 1) ret = ret * a;
       
        
        if(ret > 1e9) 
        {
            return -1;
        }
        b >>= 1;
        a = a * a;
    }

    return ret;
}


int main()
{   
    cin >> a >> b;

    cout << qpow(a, b) << endl;
}