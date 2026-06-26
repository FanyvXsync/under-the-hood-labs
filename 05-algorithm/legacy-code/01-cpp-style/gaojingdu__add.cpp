#include <iostream>
#include <string>

using namespace std;

const int N = 1e5+10;

int a[N],b[N],c[N];
int la,lb,lc;

void add(int a[],int b[],int c[])
{
    for(int i=0;i<lc;i++)
    {
        c[i]+= a[i] + b[i];
        c[i+1] += c[i] / 10;
        c[i] %= 10;
    }

    if(c[lc]) lc++;

}


int main ()
{
    string x,y;
    cin >> x >> y;
    la = x.size();lb = y.size();lc = max(la,lb);

    for(int i=0;i < la;i++) a[la-i-1] = x[i] - '0';
    for(int i=0;i < lb;i++) b[lb-i-1] = y[i] - '0';

    add(a,b,c);

    for(int i=lc-1;i>=0;i--) cout << c[i];


    return 0;
}