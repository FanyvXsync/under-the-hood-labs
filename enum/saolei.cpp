#include <iostream>

using namespace std;

const int N = 1e5+10;

int a[N],b[N];
int n; 


int check1()
{
    a[1] = 0;
    for(int i=1;i<=n;i++)
    {
        a[i+1] = b[i] - a[i] - a[i-1];
        if(a[i+1] < 0 || a[i+1] >1) return false;
    }

    if(a[n+1] != 0) return false;

    return true;
}

int check2()
{
    a[1] = 1;
    for(int i=1;i<=n;i++)
    {
        a[i+1] = b[i] - a[i] - a[i-1];
        if(a[i+1] < 0 || a[i+1] >1) return false;
    }

    if(a[n+1] != 0) return false;

    return true;
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];

    int ret = 0;

    ret+= check1();
    ret+= check2();

    cout << ret;
    return 0;

}